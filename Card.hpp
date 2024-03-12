#pragma once
export module Card;

class GameState;  // Forward declaration

class Card {
public:
    virtual void execute(GameState& gameState, Player& currentPlayer, Player& targetPlayer) = 0;
};
