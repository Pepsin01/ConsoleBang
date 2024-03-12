#pragma once
export module GameState;

#include <vector>
#include "Player.hpp"

class GameState {
private:
    std::vector<Player> players;
    // other game state attributes and methods
public:
    static GameState& getInstance();  // Singleton pattern method

    // methods to manage the game state
    void startGame();
    void endGame();
    // other necessary methods
};


