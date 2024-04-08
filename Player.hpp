#pragma once
export module Player;

#include <vector>
#include "ICard.hpp"

class GameStateControllor;  // Forward declaration

class Player {
private:
    std::vector<ICard*> hand;
public:
    // method to play a card
    void playCard(GameStateControllor& gameState, int cardIndex);
};

