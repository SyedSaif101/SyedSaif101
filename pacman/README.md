# 🟡 Pac-Man — Terminal Edition (C++)

A classic Pac-Man game built entirely in C++, playable directly in your terminal.

![C++](https://img.shields.io/badge/C++17-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Terminal](https://img.shields.io/badge/Terminal-Game-%23121011.svg?style=for-the-badge&logo=gnu-bash&logoColor=white)

## Features

- 🎮 Classic Pac-Man gameplay in your terminal
- 🗺️ Authentic maze layout with walls, pellets, and power pellets
- 👻 Four ghosts with distinct AI behaviors:
  - **Blinky** (Red) — directly chases Pac-Man
  - **Pinky** (Pink) — targets ahead of Pac-Man's direction
  - **Inky** (Cyan) — semi-random movement
  - **Clyde** (Orange) — chases when far, scatters when close
- ⚡ Power pellets let you eat ghosts
- 💛 Score tracking and lives system
- 🎨 Colorful ANSI rendering with animated power pellets

## Requirements

- **C++17** compatible compiler (g++, clang++)
- **Linux/macOS** terminal (uses POSIX terminal APIs)

---

## Running in CLion (Recommended)

### What to Download

1. **CLion** — Download and install from [jetbrains.com/clion](https://www.jetbrains.com/clion/download/)
   - Free 30-day trial available; free for students via [JetBrains Education](https://www.jetbrains.com/community/education/)
2. **C++ Compiler** — CLion needs a compiler toolchain:
   - **Linux (Ubuntu/Debian):** `sudo apt update && sudo apt install build-essential cmake`
   - **Linux (Fedora):** `sudo dnf install gcc-c++ cmake make`
   - **macOS:** Install Xcode Command Line Tools: `xcode-select --install`

### How to Open and Run in CLion

1. **Open the project:**
   - Launch CLion → **File → Open** → select the `pacman` folder (the one containing `CMakeLists.txt`)
   - CLion will auto-detect the CMake project and configure it

2. **Build the project:**
   - Click the **Build** button (🔨) in the toolbar, or press **Ctrl+F9** (Linux) / **Cmd+F9** (macOS)

3. **Run the game:**
   - Click the **Run** button (▶️) in the toolbar, or press **Shift+F10** (Linux) / **Ctrl+R** (macOS)
   - **Important:** The game runs in CLion's built-in terminal, which supports ANSI colors

4. **Play!** Use **W/A/S/D** to move and **Q** to quit

> **Tip:** If colors look off, go to **Run → Edit Configurations → pacman**, and check **"Emulate terminal in output console"** for full ANSI color support.

---

## Build & Run (Command Line)

```bash
cd pacman

# Option 1: Build with Make
make
./pacman

# Option 2: Build with CMake
cmake -B build
cmake --build build
./build/pacman

# Option 3: Compile directly
g++ -std=c++17 -Wall -O2 -o pacman pacman.cpp
./pacman
```

## Controls

| Key | Action     |
|-----|------------|
| `W` | Move Up    |
| `A` | Move Left  |
| `S` | Move Down  |
| `D` | Move Right |
| `Q` | Quit       |

## How to Play

1. Navigate Pac-Man through the maze using WASD keys
2. Eat all pellets (`.`) to win the level
3. Avoid ghosts (`M`) — they will chase you!
4. Eat power pellets (`o`) to temporarily turn ghosts blue
5. While ghosts are blue, eat them for bonus points!
6. You start with 3 lives — lose them all and it's Game Over

## Scoring

| Item          | Points |
|---------------|--------|
| Pellet (`.`)  | 10     |
| Power Pellet (`o`) | 50 |
| Ghost         | 200    |

## Map Legend

| Symbol | Meaning       |
|--------|---------------|
| `#`    | Wall          |
| `.`    | Pellet        |
| `o`    | Power Pellet  |
| `-`    | Ghost Gate    |
| `C`    | Pac-Man       |
| `M`    | Ghost         |
