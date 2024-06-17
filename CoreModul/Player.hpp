#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include <random>
#include <ctime>
#include "Card.hpp"
#include "PlayerRole.hpp"
#include "GameState.hpp"
#include "../GameUI/PlayerUIOutput.hpp"
#include "../GameUI/PlayerUIInput.hpp"
#include "../GameUI/GameUIOutput.hpp"
#include "../GameUI/GameUIInput.hpp"


/*
* @brief Class that represents a player in the game
*/
class Player {
private:
    int health; // Player's health
    bool bangPlayed; // Flag that indicates if the player has played a bang card in the current turn

    std::vector<std::unique_ptr<Card>> hand; // Player's hand
    std::vector<std::unique_ptr<Card>> equipment; // Player's equipment

    GameStateControllor& gameState; // Reference to the game state

    void showPrivateProfile(); // Triggers the private profile screen rendering

    void moveCardToEquipment(std::unique_ptr<Card> card); // Moves a card from the hand to the equipment
    void replaceWeapon(std::unique_ptr<Card> card); // Replaces the weapon in the equipment with a new one

    bool passesTurn(); // Checks if the player passes the turn
    bool evaluatePrigione(); // Evaluates the prigione card effect

    std::string roleToString() const; // Converts the player's role to a string
    int getMaximumHealth() const; // Returns the maximum health of the player


public:
    /*
    * @brief Player's role
    */
    const PlayerRole role;

    /*
    * @brief Returns the player's health
    * @return Player's health
    */
    int getHealth() const;

    /*
    * @brief Calculates the player's range with the weapon according to his equipment
    * @return Player's range
	*/
    int calculateRange() const;

    /*
    * @brief Calculates the player's range without the weapon
    * @return Player's range
	*/
    int calculateRangeWithoutWeapon() const;

    /*
    * @brief Calculates the player's distance modifier according to his equipment
    * @return Player's distance modifier
    */
    int calculateDistanceModifier() const;

    /*
    * @brief Counts the number of cards in the player's hand
    * @return Player's hand size
	*/
    int getHandSize() const;

    /*
    * @brief Counts the number of cards in the player's equipment
    * @return Player's equipment size
	*/
    int getEquipmentSize() const;

    /*
    * @return Returns reference to the game state controller that the player is in
    */
    GameStateControllor& getGameState() const;

    /*
    * @brief Checks if the player is dead
    * @return True if the player is dead, false otherwise
	*/
    bool isDead() const;

    /*
    * @brief Makes the player play a card from his hand on the given index
    * @param cardIndex Index of the card to play
    */
    void playCard(int cardIndex);

    /*
    * @brief Player constructor
    * @param gameState Reference to the game state controller
    * @param role Player's role
	*/
    Player(GameStateControllor& gameState, PlayerRole role);

    /*
    * @brief Starts the player's turn loop
    */
    void takeTurn();

    /*
    * @brief Changes the player's health by the given amount.
    * The amount can be negative, which means that the player loses health.
    * @note The health cannot be more than the maximum health
    * @param damage Amount of health to change
	*/
    void changeHealth(int damage);

    /*
    * @brief Shows the player's public profile
    */ 
    void showPublicProfile();

    /*
    * @brief Try to defend against a bang card by playing a Mancato card or using equipment cards
    * @return True if the player successfully defended, false otherwise
	*/
    bool defendBangEffect();

    /*
    * @brief Try to return fire by playing a bang card
    * @return True if the player successfully returned fire, false otherwise
    */ 
    bool returnFire();

    /*
    * @brief Checks if the player can play a bang card (hasn't played a bang card in the current turn or has a Volcanic weapon)
    * @return True if the player successfully played a bang card, false otherwise
	*/
    bool tryPlayBang();

    /*
    * @brief Takes a random card from the player's hand and returns it
    * @return Random card from the player's hand
    */
    std::unique_ptr<Card> handRandomCard();

    /*
    * @brief Takes a card from the player's equipment by the given index and returns it
    * @param index Index of the card to take
    * @return Card from the player's equipment
	*/
    std::unique_ptr<Card> handEquipmentCard(int index);

    /*
    * @brief Receives a card and puts it in the player's hand
    * @param card Card to receive
    */
    void receiveCard(std::unique_ptr<Card> card);

    /*
    * @brief Receives a debuff card and puts it in the player's equipment
    * @param card Debuff card to receive
	*/
    void receiveDebuff(std::unique_ptr<Card> card);

    /*
    * @brief Discards a card from the player's hand by the given index
    * @param index Index of the card to discard
    * @note The card is handed to the game state controller to be discarded
    */ 
    void discardCard(int index);
};

