#pragma once
#include <vector>
#include <memory>
#include "Card.hpp"
#include "PlayerRole.hpp"
#include "GameState.hpp"

//class GameStateControllor;  // Forward declaration

class Player {
private:
    std::vector<std::unique_ptr<Card>> hand;
    const PlayerRole role;
    int health;
    GameStateControllor& gameState;
public:
    // method to play a card
    void playCard(GameStateControllor& gameState, int cardIndex);
    Player(GameStateControllor& gameState, PlayerRole role);
};

