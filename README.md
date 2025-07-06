# Snake Game in C++

A classic console-based **Snake Game** implemented in C++ using basic system libraries (`<iostream>`, `<conio.h>`, and `<windows.h>`). The game includes snake movement, fruit collection, tail growth, and collision detection. Colored output is used for enhanced terminal visualization.

## Features

- 🐍 Snake head and body movement
- 🍎 Fruit randomly appears on the board
- 🧠 Score tracking
- 💥 Collision detection (walls and self)
- 🎮 Keyboard controls (`W`, `A`, `S`, `D`)
- 🧵 Dynamic tail growth
- 🖥️ Console-based interface with simple colors (using ANSI escape codes)

## Controls

| Key | Action       |
|-----|--------------|
| `W` | Move Up      |
| `S` | Move Down    |
| `A` | Move Left    |
| `D` | Move Right   |
| `X` | Exit Game    |

## Game Rules

- Eat the fruit `F` to grow your snake and earn 10 points.
- Avoid hitting the wall or your own tail.
- The snake's movement speed slightly varies by direction:
  - Slower when moving vertically (`UP`, `DOWN`)
  - Faster when moving horizontally (`LEFT`, `RIGHT`)

## How to Run

### Prerequisites

- A C++ compiler that supports `<conio.h>` and `<windows.h>` (typically MSVC on Windows).
- Windows OS (due to use of `Sleep()` and `system("cls")`)

### Compilation (Command Line)

```bash
g++ snake_game.cpp -o snake_game
