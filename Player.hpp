#pragma once
export module Player;

#include <vector>
#include "Card.hpp"

class GameState;  // Forward declaration

class Player {
private:
    std::vector<Card*> hand;
public:
    // method to play a card
    void playCard(GameState& gameState, int cardIndex, Player& targetPlayer);
};

