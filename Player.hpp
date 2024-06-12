#pragma once
#include <vector>
#include <memory>
#include "ICard.hpp"
#include "PlayerRole.hpp"

class GameStateControllor;  // Forward declaration

class Player {
private:
    std::vector<std::shared_ptr<ICard>> hand;
    const PlayerRole role;
    int health;
public:
    // method to play a card
    void playCard(GameStateControllor& gameState, int cardIndex);
    Player(PlayerRole role);
};

