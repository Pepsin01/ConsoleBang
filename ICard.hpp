#pragma once

class GameStateControllor;  // Forward declaration
class Player;  // Forward declaration

class ICard {
public:
    virtual void execute(GameStateControllor& gameState, Player& currentPlayer) = 0;
};
