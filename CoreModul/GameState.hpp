#pragma once

#include <vector>
#include <memory>
#include <deque>
#include "Player.hpp"
#include "../GameUI/GameUIOutput.hpp"
#include "../GameUI/GameUIInput.hpp"
#include "../GameUI/CardUIInput.hpp"
#include "../GameUI/CardUIOutput.hpp"
#include "Card.hpp"


enum GameState
{
    START,
    PLAYER_TURN,
    CARD_EXECUTION,
	END
};

/*
* @class GameStateController
* @brief Class that controls the game state and the game loop
*/
class GameStateController {
	std::vector<std::shared_ptr<Player>> players; // Vector currently playing players
    int currentPlayerIndex; // Index of the current player

    std::deque<std::unique_ptr<Card>> deck; // Deck of cards

    GameState currentState; // Current game state

    GameUIOutput& uiOut; // Output UI
    GameUIInput& uiIn; // Input UI
    
    /*
    * @brief Constructor
    * @param uiOut Output UI
    * @param uiIn Input UI
    * @param playerCount Number of players
    * @return GameStateController instance
    */
    GameStateController(GameUIOutput& uiOut, GameUIInput& uiIn, int playerCount);

    void initializeDeck(); // Initialize the deck of cards

    void initializePlayers(int playerCount); // Initialize the players

	static std::vector<CardColor> generateDeckColors(int cardCount); // Generate colors for the deck

    /*
    * @brief Add cards to the deck
    * @param deck Deck of cards
    * @param gameState Game state controllor to pass to the cards
    * @param colors Colors to assign to the cards
    * @param count Number of cards to add
    */
    template <typename CardType>
    void addCardsToDeck(std::deque<std::unique_ptr<Card>>& deck, GameStateController& gameState, std::vector<CardColor>& colors, int count)
    {
        for (int i = 0; i < count; i++)
        {
            deck.push_back(std::make_unique<CardType>(gameState, colors.back()));
            colors.pop_back();
        }
    }

    void mainGameLoop(); // Main game loop

    bool isGameEnd() const; // Check if the game has ended

    bool isSherifDead() const; // Check if the sherif is dead

    bool areBanditsDead() const; // Check if all bandits are dead

    void endGame() const; // End the game
public:
    /*
    * @brief Get the instance of the GameStateController
    * @param uiOut Output UI
    * @param uiIn Input UI
    * @param playerCount Number of players
    * @return GameStateController instance
    * @note Singleton pattern method
    */
    static GameStateController& getInstance(GameUIOutput& uiOut, GameUIInput& uiIn, int playerCount);  // Singleton pattern method
    
    /*
    * @brief Get the current game state
    * @return Current game state
    */
    GameState getCurrentState() const;
    
    /*
    * @brief Get the player at the given index
    * @param index Index of the player
    * @return Player at the given index
	*/
    std::shared_ptr<Player> getPlayer(int index);
    
    /*
    * @brief Get the number of players
    * @return Number of players
	*/
    size_t playerCount() const;
    
    /*
    * @brief Get the index of the current player
    * @return Index of the current player
    * @note The current player is the player that is currently having a turn
    */
    int getCurrentPlayerIndex() const;

    /*
    * @brief Start the game
	*/
    void startGame();

    /*
    * @brief Draw a card from the top of the deck
    * @return Card drawn from the deck
    */
    std::unique_ptr<Card> drawCard();

    /*
    * @brief Puts the given card on the bottom of the deck
    * @param card Card to put on the bottom of the deck
	*/
    void discardCard(std::unique_ptr<Card> card);

    /*
    * @brief Tries to cast a debuff card to a player which is chosen by the current player
    * @param card Card to cast
    * @return nullptr if the card is casted, the card if the card is not casted
    * @note The card is not casted if the player chooses to not cast the card
	*/
    std::unique_ptr<Card> castDebuff(std::unique_ptr<Card> card);

    /*
    * @brief Method that calculates the minimal distance between two players as if they sit around a table
    * @param attackerIndex Index of the attacker
    * @param defenderIndex Index of the defender
    * @return Distance between the attacker and the defender
    */
    int calculateDistance(int attackerIndex, int defenderIndex);
};


