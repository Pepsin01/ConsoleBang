#pragma once

#include <vector>
#include <memory>
#include <deque>
#include "Player.hpp"
#include "GameUIOutput.hpp"
#include "GameUIinput.hpp"
#include "PlayerRole.hpp"

enum GameState
{
    START,
    PLAYER_TURN,
    CARD_EXECUTION,
	END
};

class GameStateControllor {
private:
    std::vector<std::shared_ptr<Player>> players;
    int currentPlayerIndex;

    std::deque<std::unique_ptr<Card>> deck;

    GameState currentState;

    GameUIOutput& uiOut;
    GameUIInput& uiIn;
    
    GameStateControllor(GameUIOutput& uiOut, GameUIInput& uiIn, int playerCount);
public:
    static GameStateControllor& getInstance(GameUIOutput& uiOut, GameUIInput& uiIn, int playerCount);  // Singleton pattern method
    
    GameState getCurrentState() const;
    
    std::shared_ptr<Player> getPlayer(int index);
    
    size_t playerCount();
    
    int getCurrentPlayerIndex() const;

    void startGame();

    void endGame();
};


