#pragma once
export module GameState;

#include <vector>
#include "Player.hpp"
#include "GameUIOutput.hpp"

enum GameState
{
    START,
    PLAYER_TURN,
    CARD_EXECUTION,
	END
};

class GameStateControllor {
private:
    std::vector<Player> players;
    int currentPlayerIndex;

    GameState currentState;

    GameUIOutput& uiOut;
    
    GameStateControllor(GameUIOutput& uiOut, int playerCount);
public:
    static GameStateControllor& getInstance(GameUIOutput& uiOut, int playerCount);  // Singleton pattern method
    
    GameState getCurrentState() const;
    
    Player& getPlayer(int index);
    
    int playerCount();
    
    int getCurrentPlayerIndex() const;

    void startGame();

    void endGame();
};


