#pragma once

#include <vector>
#include <memory>
#include <deque>
#include <algorithm>
#include <random>
#include <ctime>
#include "Player.hpp"
#include "../GameUI/GameUIOutput.hpp"
#include "../GameUI/GameUIInput.hpp"
#include "PlayerRole.hpp"
#include "Card.hpp"
#include "../Cards/AppaloosaCard.hpp"
#include "../Cards/BangCard.hpp"
#include "../Cards/BarileCard.hpp"
#include "../Cards/BirraCard.hpp"
#include "../Cards/CatBelouCard.hpp"
#include "../Cards/CarabineCard.hpp"
#include "../Cards/DiligenzaCard.hpp"
#include "../Cards/DuelloCard.hpp"
#include "../Cards/EmporioCard.hpp"
#include "../Cards/GatlingCard.hpp"
#include "../Cards/IndianiCard.hpp"
#include "../Cards/MancatoCard.hpp"
#include "../Cards/MustangCard.hpp"
#include "../Cards/PanicoCard.hpp"
#include "../Cards/PrigioneCard.hpp"
#include "../Cards/RemingtonCard.hpp"
#include "../Cards/SaloonCard.hpp"
#include "../Cards/SchofieldCard.hpp"
#include "../Cards/VolcanicCard.hpp"
#include "../Cards/WellsFargoCard.hpp"
#include "../Cards/WinchesterCard.hpp"

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

    void initializeDeck();

    void initializePlayers(int playerCount);

    std::vector<CardColor> generateDeckColors(int cardCount);

    template <typename CardType>
    void addCardsToDeck(std::deque<std::unique_ptr<Card>>& deck, GameStateControllor& gameState, std::vector<CardColor>& colors, int count)
    {
        for (int i = 0; i < count; i++)
        {
            deck.push_back(make_unique<CardType>(gameState, colors.back()));
            colors.pop_back();
        }
    }
public:
    static GameStateControllor& getInstance(GameUIOutput& uiOut, GameUIInput& uiIn, int playerCount);  // Singleton pattern method
    
    GameState getCurrentState() const;
    
    std::shared_ptr<Player> getPlayer(int index);
    
    size_t playerCount();
    
    int getCurrentPlayerIndex() const;

    void startGame();

    void endGame();

    std::unique_ptr<Card> drawCard();
};


