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

## Build & Run

```bash
cd pacman

# Build with Make
make

# Run the game
./pacman
```

Or compile directly:

```bash
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
