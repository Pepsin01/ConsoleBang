# Console Bang! Card Game Specification

## Task
Develop a terminal-based card game inspired by the Bang! game, allowing multiple players to engage on a single computer.

## Game Logic Module

### StateController Class
The StateController class manages the game's state and flow. It serves as a library for external programs to interact with and manipulate the game state. Key responsibilities include:

- Transitioning between different game states (e.g., player turns, resolving card effects).
- Providing access to the current game state.
- Allowing external programs to set or update the game state.

### Player Class
The Player class represents an individual participant in the game. It manages player-specific information, controls player actions, and evaluates their impact on the game state. Key functionalities include:

- Maintaining player attributes (e.g., health, role, hand of cards).
- Executing actions on behalf of the player (e.g., playing cards, targeting other players).
- Evaluating the impact of player actions on the game state.

### Card Class
The Card class encapsulates the characteristics and behaviors of cards within the game. It stores card-specific information and controls the execution of card actions. Important features include:

- Storing card attributes (e.g., type, effect, value).
- Providing methods for resolving card effects.
- Interacting with the game state based on card actions.

#### List of playable cards
| Number | Name | Type |
| ------ | ---- | ---- |
| 25     | BANG! | Brown |
| 12     | Mancato! (Missed!) | Brown |
| 3      | Duello (Duel) | Brown |
| 1      | Wells Fargo | Brown |
| 2      | Diligenza (Stagecoach) | Brown |
| 1      | Dinamite (Dynamite) | Blue |
| 1      | Appaloosa | Blue |
| 2      | Cavallo (Horse) | Blue |
| 1      | Saloon | Brown |
| 2      | Volcanic | Weapon |
| 3      | Schofield | Weapon |
| 1      | Remington | Weapon |
| 1      | Rev. Carabine | Weapon |
| 1      | Winchester | Weapon |
| 3      | Prigione (Jail) | Blue |
| 1      | Gatling |  Brown |
| 2      | Barile (Barrel) | Blue |
| 2      | Indiani! (Injuns!) |  Brown |
| 4      | Maestrina (Mistress) |  Brown |
| 4      | Panico! (Panic!) |  Brown |
| 6      | Birra (Beer) |  Brown |
| 2      | Emporio (General Store) |  Brown |

## User Interface Module

### Printer Class
The Printer class manages the display of information on the terminal, conveying the current state of the game to the players. It is responsible for:

- Formatting and printing information about the game state.
- Displaying updates, such as player actions and changes in the game environment.

### InputReader Class
The InputReader class handles user input from the terminal, translating it into actions within the game logic module. Key functionalities include:

- Reading and interpreting player inputs.
- Validating input for adherence to game rules.
- Communicating user actions to the game logic module.
