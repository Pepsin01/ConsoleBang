#pragma once
export module Card;

class GameStateControllor;  // Forward declaration

class ICard {
public:
    virtual void execute(GameStateControllor& gameState, Player& currentPlayer) = 0;
};
