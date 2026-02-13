// =============================================================================
// Terminal Pac-Man Game in C++
// =============================================================================
// A console-based Pac-Man game using ANSI escape codes for rendering.
// Cross-platform: works on Windows (CLion/MSVC/MinGW) and Linux/macOS.
//
// Controls: W/A/S/D to move, Q to quit
// Objective: Eat all pellets to win. Avoid ghosts or eat them after a power pellet!
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <thread>

#ifdef _WIN32
  #include <conio.h>
  #include <windows.h>
#else
  #include <termios.h>
  #include <unistd.h>
  #include <fcntl.h>
#endif

// =============================================================================
// Constants
// =============================================================================

static const int MAP_WIDTH = 28;
static const int MAP_HEIGHT = 31;

static const char WALL = '#';
static const char PELLET = '.';
static const char POWER_PELLET = 'o';
static const char EMPTY = ' ';
static const char GATE = '-';

static const int PELLET_SCORE = 10;
static const int POWER_PELLET_SCORE = 50;
static const int GHOST_SCORE = 200;

static const int POWER_DURATION = 30;  // ticks of power-up mode
static const int INITIAL_LIVES = 3;

// ANSI color codes
static const char* RESET   = "\033[0m";
static const char* YELLOW  = "\033[1;33m";
static const char* RED     = "\033[1;31m";
static const char* CYAN    = "\033[1;36m";
static const char* PINK    = "\033[1;35m";
static const char* ORANGE  = "\033[38;5;208m";
static const char* BLUE    = "\033[1;34m";
static const char* WHITE   = "\033[1;37m";
static const char* GREEN   = "\033[1;32m";
static const char* DIM     = "\033[2m";

// =============================================================================
// Direction enum
// =============================================================================

enum Direction { NONE, UP, DOWN, LEFT, RIGHT };

// =============================================================================
// The classic Pac-Man maze layout
// =============================================================================
// # = wall, . = pellet, o = power pellet, - = ghost gate, ' ' = empty

static const std::string INITIAL_MAP[MAP_HEIGHT] = {
    "############################",
    "#............##............#",
    "#.####.#####.##.#####.####.#",
    "#o####.#####.##.#####.####o#",
    "#.####.#####.##.#####.####.#",
    "#..........................#",
    "#.####.##.########.##.####.#",
    "#.####.##.########.##.####.#",
    "#......##....##....##......#",
    "######.##### ## #####.######",
    "     #.##### ## #####.#     ",
    "     #.##          ##.#     ",
    "     #.## ###--### ##.#     ",
    "######.## #      # ##.######",
    "      .   #      #   .      ",
    "######.## #      # ##.######",
    "     #.## ######## ##.#     ",
    "     #.##          ##.#     ",
    "     #.## ######## ##.#     ",
    "######.## ######## ##.######",
    "#............##............#",
    "#.####.#####.##.#####.####.#",
    "#.####.#####.##.#####.####.#",
    "#o..##.......  .......##..o#",
    "###.##.##.########.##.##.###",
    "###.##.##.########.##.##.###",
    "#......##....##....##......#",
    "#.##########.##.##########.#",
    "#.##########.##.##########.#",
    "#..........................#",
    "############################",
};

// =============================================================================
// Cross-platform terminal helpers
// =============================================================================

#ifdef _WIN32

static HANDLE hConsole;
static DWORD origConsoleMode;

static void disableRawMode() {
    SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), origConsoleMode);
    // Show cursor
    std::cout << "\033[?25h" << std::flush;
}

static void enableRawMode() {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);

    // Save original console mode
    GetConsoleMode(hInput, &origConsoleMode);
    atexit(disableRawMode);

    // Enable virtual terminal processing for ANSI escape codes on Windows
    DWORD outMode = 0;
    GetConsoleMode(hConsole, &outMode);
    outMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hConsole, outMode);

    // Hide cursor
    std::cout << "\033[?25l" << std::flush;
}

static int kbhit_read() {
    if (_kbhit()) {
        int ch = _getch();
        // Handle extended keys (arrow keys, function keys, etc.)
        if (ch == 0 || ch == 0xE0) {
            _getch(); // discard the second byte
            return -1;
        }
        return ch;
    }
    return -1;
}

static void sleepMs(int ms) {
    Sleep(ms);
}

#else

static struct termios orig_termios;

static void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
    // Show cursor
    std::cout << "\033[?25h" << std::flush;
}

static void enableRawMode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawMode);

    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);

    // Hide cursor
    std::cout << "\033[?25l" << std::flush;
}

static int kbhit_read() {
    char ch;
    ssize_t n = read(STDIN_FILENO, &ch, 1);
    if (n > 0) return ch;
    return -1;
}

static void sleepMs(int ms) {
    usleep(ms * 1000);
}

#endif

// =============================================================================
// Ghost structure
// =============================================================================

struct Ghost {
    int x, y;
    int startX, startY;
    Direction dir;
    const char* color;
    std::string name;
    bool eaten;
    int respawnTimer;

    Ghost(int sx, int sy, const char* c, const std::string& n)
        : x(sx), y(sy), startX(sx), startY(sy),
          dir(UP), color(c), name(n), eaten(false), respawnTimer(0) {}

    void reset() {
        x = startX;
        y = startY;
        dir = UP;
        eaten = false;
        respawnTimer = 0;
    }
};

// =============================================================================
// Game class
// =============================================================================

class PacmanGame {
private:
    std::vector<std::string> map;
    int pacX, pacY;
    Direction pacDir;
    Direction nextDir;
    int score;
    int lives;
    int totalPellets;
    int pelletsEaten;
    bool powerMode;
    int powerTimer;
    bool gameOver;
    bool gameWon;
    int tick;
    std::vector<Ghost> ghosts;

public:
    PacmanGame() { init(); }

    void init() {
        map.resize(MAP_HEIGHT);
        for (int i = 0; i < MAP_HEIGHT; i++) {
            map[i] = INITIAL_MAP[i];
        }

        // Pac-Man starting position
        pacX = 14;
        pacY = 23;
        pacDir = NONE;
        nextDir = NONE;

        score = 0;
        lives = INITIAL_LIVES;
        powerMode = false;
        powerTimer = 0;
        gameOver = false;
        gameWon = false;
        tick = 0;

        // Count pellets
        totalPellets = 0;
        pelletsEaten = 0;
        for (int y = 0; y < MAP_HEIGHT; y++) {
            for (int x = 0; x < MAP_WIDTH; x++) {
                if (map[y][x] == PELLET || map[y][x] == POWER_PELLET) {
                    totalPellets++;
                }
            }
        }

        // Initialize ghosts in the ghost house
        ghosts.clear();
        ghosts.push_back(Ghost(14, 11, RED,    "Blinky"));
        ghosts.push_back(Ghost(12, 14, PINK,   "Pinky"));
        ghosts.push_back(Ghost(14, 14, CYAN,   "Inky"));
        ghosts.push_back(Ghost(16, 14, ORANGE, "Clyde"));
    }

    void resetPositions() {
        pacX = 14;
        pacY = 23;
        pacDir = NONE;
        nextDir = NONE;
        powerMode = false;
        powerTimer = 0;
        for (auto& g : ghosts) {
            g.reset();
        }
    }

    bool isWalkable(int x, int y, bool isGhost = false) const {
        if (y < 0 || y >= MAP_HEIGHT) return false;
        // Allow tunnel wrapping
        if (x < 0 || x >= MAP_WIDTH) {
            if (y == 14) return true; // tunnel row
            return false;
        }
        char cell = map[y][x];
        if (cell == WALL) return false;
        if (cell == GATE && !isGhost) return false;
        return true;
    }

    void wrapPosition(int& x, int& /*y*/) const {
        if (x < 0) x = MAP_WIDTH - 1;
        if (x >= MAP_WIDTH) x = 0;
    }

    void processInput() {
        int ch;
        // Read all available input, keep the last valid direction
        while ((ch = kbhit_read()) != -1) {
            switch (ch) {
                case 'w': case 'W': nextDir = UP;    break;
                case 's': case 'S': nextDir = DOWN;  break;
                case 'a': case 'A': nextDir = LEFT;  break;
                case 'd': case 'D': nextDir = RIGHT; break;
                case 'q': case 'Q': gameOver = true;  return;
            }
        }
    }

    void movePacman() {
        int nx = pacX, ny = pacY;

        // Try the queued direction first
        if (nextDir != NONE) {
            int tx = pacX, ty = pacY;
            switch (nextDir) {
                case UP:    ty--; break;
                case DOWN:  ty++; break;
                case LEFT:  tx--; break;
                case RIGHT: tx++; break;
                default: break;
            }
            wrapPosition(tx, ty);
            if (isWalkable(tx, ty)) {
                pacDir = nextDir;
                nextDir = NONE;
            }
        }

        // Move in current direction
        nx = pacX;
        ny = pacY;
        switch (pacDir) {
            case UP:    ny--; break;
            case DOWN:  ny++; break;
            case LEFT:  nx--; break;
            case RIGHT: nx++; break;
            default: return;
        }
        wrapPosition(nx, ny);

        if (isWalkable(nx, ny)) {
            pacX = nx;
            pacY = ny;
        }

        // Eat pellet
        if (pacX >= 0 && pacX < MAP_WIDTH && pacY >= 0 && pacY < MAP_HEIGHT) {
            char cell = map[pacY][pacX];
            if (cell == PELLET) {
                map[pacY][pacX] = EMPTY;
                score += PELLET_SCORE;
                pelletsEaten++;
            } else if (cell == POWER_PELLET) {
                map[pacY][pacX] = EMPTY;
                score += POWER_PELLET_SCORE;
                pelletsEaten++;
                powerMode = true;
                powerTimer = POWER_DURATION;
                // Reverse ghost directions
                for (auto& g : ghosts) {
                    if (!g.eaten) {
                        switch (g.dir) {
                            case UP:    g.dir = DOWN;  break;
                            case DOWN:  g.dir = UP;    break;
                            case LEFT:  g.dir = RIGHT; break;
                            case RIGHT: g.dir = LEFT;  break;
                            default: break;
                        }
                    }
                }
            }
        }

        // Check win
        if (pelletsEaten >= totalPellets) {
            gameWon = true;
        }
    }

    void moveGhost(Ghost& ghost) {
        if (ghost.eaten) {
            ghost.respawnTimer--;
            if (ghost.respawnTimer <= 0) {
                ghost.x = ghost.startX;
                ghost.y = ghost.startY;
                ghost.eaten = false;
            }
            return;
        }

        // Determine target based on ghost personality and power mode
        int targetX, targetY;
        if (powerMode) {
            // Scatter: move to a random corner
            targetX = (ghost.x < MAP_WIDTH / 2) ? MAP_WIDTH - 2 : 1;
            targetY = (ghost.y < MAP_HEIGHT / 2) ? MAP_HEIGHT - 2 : 1;
        } else {
            // Chase Pac-Man with slight variation per ghost
            targetX = pacX;
            targetY = pacY;
            if (ghost.name == "Blinky") {
                // Direct chase
            } else if (ghost.name == "Pinky") {
                // Aim ahead of Pac-Man
                switch (pacDir) {
                    case UP:    targetY -= 4; break;
                    case DOWN:  targetY += 4; break;
                    case LEFT:  targetX -= 4; break;
                    case RIGHT: targetX += 4; break;
                    default: break;
                }
            } else if (ghost.name == "Inky") {
                // Semi-random offset
                targetX += (rand() % 5) - 2;
                targetY += (rand() % 5) - 2;
            } else { // Clyde
                // Chase if far, scatter if close
                int dist = std::abs(ghost.x - pacX) + std::abs(ghost.y - pacY);
                if (dist < 8) {
                    targetX = 1;
                    targetY = MAP_HEIGHT - 2;
                }
            }
        }

        // Try all four directions, pick the one closest to target
        Direction bestDir = ghost.dir;
        int bestDist = 999999;
        Direction dirs[] = {UP, DOWN, LEFT, RIGHT};

        // Shuffle a bit for variety when equal
        for (auto d : dirs) {
            // Don't allow 180-degree turns (unless no other option)
            if ((d == UP && ghost.dir == DOWN) ||
                (d == DOWN && ghost.dir == UP) ||
                (d == LEFT && ghost.dir == RIGHT) ||
                (d == RIGHT && ghost.dir == LEFT)) {
                continue;
            }

            int nx = ghost.x, ny = ghost.y;
            switch (d) {
                case UP:    ny--; break;
                case DOWN:  ny++; break;
                case LEFT:  nx--; break;
                case RIGHT: nx++; break;
                default: break;
            }
            wrapPosition(nx, ny);

            if (isWalkable(nx, ny, true)) {
                int dist = (nx - targetX) * (nx - targetX) +
                           (ny - targetY) * (ny - targetY);
                if (dist < bestDist) {
                    bestDist = dist;
                    bestDir = d;
                }
            }
        }

        // If no valid move without reversing, allow reverse
        if (bestDist == 999999) {
            for (auto d : dirs) {
                int nx = ghost.x, ny = ghost.y;
                switch (d) {
                    case UP:    ny--; break;
                    case DOWN:  ny++; break;
                    case LEFT:  nx--; break;
                    case RIGHT: nx++; break;
                    default: break;
                }
                wrapPosition(nx, ny);
                if (isWalkable(nx, ny, true)) {
                    bestDir = d;
                    break;
                }
            }
        }

        ghost.dir = bestDir;
        int nx = ghost.x, ny = ghost.y;
        switch (ghost.dir) {
            case UP:    ny--; break;
            case DOWN:  ny++; break;
            case LEFT:  nx--; break;
            case RIGHT: nx++; break;
            default: break;
        }
        wrapPosition(nx, ny);
        if (isWalkable(nx, ny, true)) {
            ghost.x = nx;
            ghost.y = ny;
        }
    }

    void checkCollisions() {
        for (auto& ghost : ghosts) {
            if (ghost.eaten) continue;
            if (ghost.x == pacX && ghost.y == pacY) {
                if (powerMode) {
                    // Eat ghost
                    ghost.eaten = true;
                    ghost.respawnTimer = 10;
                    score += GHOST_SCORE;
                } else {
                    // Pac-Man dies
                    lives--;
                    if (lives <= 0) {
                        gameOver = true;
                    } else {
                        resetPositions();
                    }
                    return;
                }
            }
        }
    }

    void update() {
        tick++;
        processInput();
        if (gameOver || gameWon) return;

        movePacman();
        if (gameOver || gameWon) return;

        // Move ghosts at a slightly slower rate
        if (tick % 2 == 0) {
            for (auto& ghost : ghosts) {
                moveGhost(ghost);
            }
        }

        checkCollisions();

        // Update power mode timer
        if (powerMode) {
            powerTimer--;
            if (powerTimer <= 0) {
                powerMode = false;
            }
        }
    }

    void render() const {
        // Move cursor to top-left
        std::cout << "\033[H";

        // Header
        std::cout << YELLOW << "╔══════════════════════════════════════════════╗" << RESET << "\n";
        std::cout << YELLOW << "║" << WHITE << "          PAC-MAN  - Terminal Edition         " << YELLOW << "║" << RESET << "\n";
        std::cout << YELLOW << "╚══════════════════════════════════════════════╝" << RESET << "\n";
        std::cout << "\n";

        // Score and lives
        std::cout << WHITE << " Score: " << GREEN << score
                  << WHITE << "    Lives: ";
        for (int i = 0; i < lives; i++) std::cout << YELLOW << "C ";
        for (int i = lives; i < INITIAL_LIVES; i++) std::cout << DIM << ". ";
        std::cout << RESET;
        if (powerMode) {
            std::cout << "    " << BLUE << "[POWER!]" << RESET;
        }
        std::cout << "          \n\n";

        // Draw map
        for (int y = 0; y < MAP_HEIGHT; y++) {
            std::cout << " ";
            for (int x = 0; x < MAP_WIDTH; x++) {
                // Check if Pac-Man is here
                if (x == pacX && y == pacY) {
                    char pacChar = 'C';
                    switch (pacDir) {
                        case RIGHT: pacChar = 'C'; break;
                        case LEFT:  pacChar = 'D'; break;
                        case UP:    pacChar = '^'; break;
                        case DOWN:  pacChar = 'v'; break;
                        default:    pacChar = 'C'; break;
                    }
                    std::cout << YELLOW << pacChar << RESET;
                    continue;
                }

                // Check if a ghost is here
                bool ghostHere = false;
                for (const auto& ghost : ghosts) {
                    if (!ghost.eaten && ghost.x == x && ghost.y == y) {
                        if (powerMode) {
                            std::cout << BLUE << "M" << RESET;
                        } else {
                            std::cout << ghost.color << "M" << RESET;
                        }
                        ghostHere = true;
                        break;
                    }
                }
                if (ghostHere) continue;

                // Draw map cell
                char cell = map[y][x];
                switch (cell) {
                    case WALL:
                        std::cout << BLUE << "#" << RESET;
                        break;
                    case PELLET:
                        std::cout << WHITE << "." << RESET;
                        break;
                    case POWER_PELLET:
                        std::cout << (tick % 4 < 2 ? WHITE : YELLOW) << "o" << RESET;
                        break;
                    case GATE:
                        std::cout << WHITE << "-" << RESET;
                        break;
                    default:
                        std::cout << " ";
                        break;
                }
            }
            std::cout << "\n";
        }

        // Footer
        std::cout << "\n";
        std::cout << WHITE << " Controls: " << GREEN << "W" << WHITE << "/" << GREEN << "A"
                  << WHITE << "/" << GREEN << "S" << WHITE << "/" << GREEN << "D"
                  << WHITE << " = Move   " << RED << "Q" << WHITE << " = Quit" << RESET << "\n";
        std::cout << WHITE << " Eat all pellets to win! Power pellets ("
                  << YELLOW << "o" << WHITE << ") let you eat ghosts!" << RESET << "\n";
        std::cout << std::flush;
    }

    void renderGameOver() const {
        std::cout << "\033[H\033[2J";
        std::cout << "\n\n";
        std::cout << RED << "  ╔═══════════════════════════════════════╗\n";
        std::cout << RED << "  ║                                       ║\n";
        std::cout << RED << "  ║            G A M E   O V E R          ║\n";
        std::cout << RED << "  ║                                       ║\n";
        std::cout << RED << "  ╚═══════════════════════════════════════╝\n" << RESET;
        std::cout << "\n";
        std::cout << WHITE << "         Final Score: " << GREEN << score << RESET << "\n";
        std::cout << WHITE << "         Pellets Eaten: " << GREEN << pelletsEaten
                  << "/" << totalPellets << RESET << "\n\n";
        std::cout << WHITE << "         Press any key to exit..." << RESET << "\n\n";
        std::cout << std::flush;
    }

    void renderWin() const {
        std::cout << "\033[H\033[2J";
        std::cout << "\n\n";
        std::cout << GREEN << "  ╔═══════════════════════════════════════╗\n";
        std::cout << GREEN << "  ║                                       ║\n";
        std::cout << GREEN << "  ║        Y O U   W I N !                ║\n";
        std::cout << GREEN << "  ║                                       ║\n";
        std::cout << GREEN << "  ╚═══════════════════════════════════════╝\n" << RESET;
        std::cout << "\n";
        std::cout << WHITE << "         Final Score: " << YELLOW << score << RESET << "\n";
        std::cout << WHITE << "         All " << GREEN << totalPellets
                  << WHITE << " pellets eaten!" << RESET << "\n\n";
        std::cout << WHITE << "         Press any key to exit..." << RESET << "\n\n";
        std::cout << std::flush;
    }

    void run() {
        srand(static_cast<unsigned>(time(nullptr)));
        enableRawMode();

        // Clear screen
        std::cout << "\033[2J" << std::flush;

        while (!gameOver && !gameWon) {
            update();
            if (gameOver || gameWon) break;
            render();
            sleepMs(100); // ~100ms = 10 FPS
        }

        if (gameWon) {
            renderWin();
        } else {
            renderGameOver();
        }

        // Wait for keypress before exiting
        while (kbhit_read() == -1) {
            sleepMs(50);
        }
    }
};

// =============================================================================
// Main
// =============================================================================

int main() {
    PacmanGame game;
    game.run();
    return 0;
}
