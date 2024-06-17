# Console Bang! Card Game

## Overview

Console Bang! is a terminal-based card game inspired by the popular Bang! game. This project allows multiple players to engage in an interactive game session on a single computer. The game includes various modules handling game logic, player interactions, and game state management.

For more information about the game rules and card effects [look here](https://en.wikipedia.org/wiki/Bang!_(card_game)).

## Features

- **Multiplayer Support**: Multiple players can play the game on the same computer, taking turns as dictated by the game rules.
- **Core Module**: Manages the state and flow of the game, including transitions between different game states and the effects of card plays.
- **Player Module**: Handles player-specific information and actions, maintaining attributes such as health, role, and hand of cards.
- **Card Module**: Implements various cards and their effects on the game state.
- **Game UI Module**: Manages user interactions and display outputs, including input and output functionalities for both players and cards.

## How to Compile, Run, and Clean the Project

### Prerequisites

Make sure you have the following tools installed:
- `g++` (GNU Compiler Collection for C++)
- `make` (Build automation tool)

### Steps to Compile, Run, and Clean the Project

1. **Compile the Project**:

    To compile the project, run the following command:
    ```sh
    make
    ```

    This command will compile the source files and create an executable named `ConsoleBang`.

2. **Run the Executable**:

    To run the compiled executable, use the following command:
    ```sh
    ./ConsoleBang
    ```

3. **Build and Run the Project**:

    You can also compile the project and immediately run the executable by using:
    ```sh
    make run
    ```

    This command will ensure the project is compiled and then execute the resulting binary.

4. **Clean the Project**:

    To clean up the compiled files and remove the executable, use:
    ```sh
    make clean
    ```

    This command will delete all object files and the executable, leaving only the source files and the `Makefile` intact.

