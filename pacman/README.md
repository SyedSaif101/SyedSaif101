# 🟡 Pac-Man — Terminal Edition (C++)

A classic Pac-Man game built entirely in C++, playable directly in your terminal.
Cross-platform: runs on **Windows**, **Linux**, and **macOS**.

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
- 🖥️ **Cross-platform** — works on Windows, Linux, and macOS

## Requirements

- **C++17** compatible compiler
- **Windows 10+** (Command Prompt, PowerShell, or Windows Terminal) **or** Linux/macOS terminal

---

## Running in CLion on Windows (Recommended)

### What to Download

1. **CLion** — Download and install from [jetbrains.com/clion](https://www.jetbrains.com/clion/download/)
   - Free 30-day trial available; free for students via [JetBrains Education](https://www.jetbrains.com/community/education/)
2. **C++ Compiler toolchain** — CLion needs a compiler. Choose one:
   - **MinGW** (easiest): Download from [winlibs.com](https://winlibs.com/) or [MSYS2](https://www.msys2.org/)
     - In CLion: **File → Settings → Build → Toolchains → Add → MinGW** and point to the MinGW folder
   - **Microsoft Visual Studio** (MSVC): Install [Visual Studio Community](https://visualstudio.microsoft.com/) with the **"Desktop development with C++"** workload
     - CLion auto-detects MSVC if Visual Studio is installed

### How to Open and Run in CLion

1. **Download/clone** this repository (or just the `pacman` folder)
2. **Open the project:**
   - Launch CLion → **File → Open** → select the `pacman` folder (the one containing `CMakeLists.txt`)
   - CLion will auto-detect the CMake project and configure it
3. **Build the project:**
   - Click the **Build** button (🔨) in the toolbar, or press **Ctrl+F9**
4. **Run the game:**
   - Click the **Run** button (▶️) in the toolbar, or press **Shift+F10**
   - **Important:** Check **"Emulate terminal in output console"** for full ANSI color support:
     - Go to **Run → Edit Configurations → pacman** and enable the checkbox
5. **Play!** Use **W/A/S/D** to move and **Q** to quit

> **Tip:** For the best color experience on Windows, run the compiled `.exe` in **Windows Terminal** instead of the default `cmd.exe`.

---

## Running in CLion on Linux / macOS

### What to Download

1. **CLion** — Download from [jetbrains.com/clion](https://www.jetbrains.com/clion/download/)
2. **C++ Compiler:**
   - **Linux (Ubuntu/Debian):** `sudo apt update && sudo apt install build-essential cmake`
   - **Linux (Fedora):** `sudo dnf install gcc-c++ cmake make`
   - **macOS:** Install Xcode Command Line Tools: `xcode-select --install`

### How to Open and Run in CLion

1. **Open the project:**
   - Launch CLion → **File → Open** → select the `pacman` folder (the one containing `CMakeLists.txt`)
   - CLion will auto-detect the CMake project and configure it
2. **Build:** Click **Build** (🔨) or press **Ctrl+F9** / **Cmd+F9**
3. **Run:** Click **Run** (▶️) or press **Shift+F10** / **Ctrl+R**
4. **Play!** Use **W/A/S/D** to move and **Q** to quit

> **Tip:** If colors look off, go to **Run → Edit Configurations → pacman**, and check **"Emulate terminal in output console"** for full ANSI color support.

---

## Build & Run (Command Line)

### Windows (Command Prompt or PowerShell)

```cmd
cd pacman

rem Build with CMake (MinGW)
cmake -B build -G "MinGW Makefiles"
cmake --build build
build\pacman.exe

rem Or build with CMake (MSVC)
cmake -B build
cmake --build build --config Release
build\Release\pacman.exe
```

### Linux / macOS

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
