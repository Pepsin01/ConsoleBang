#pragma once
#include "GameUIInput.hpp"
#include "GameUIOutput.hpp"
#include "CardUIOutput.hpp"
#include "../CoreModul/GameState.hpp"
#include "../CoreModul/Player.hpp"
#include "../CoreModul/Card.hpp"
#include <iostream>
#include <string>

/*
* @brief Class that handles the input for the card UI
*/
class CardUIInput
{
public:
	/*
	* @brief Asks the player to select a target for the card.
	* @param gameState Current game state
	* @param card Card that is being played
	* @return Index of the player that is selected as a target
	*/
	static int selectCastTarget(GameStateController& gameState, Card& card);
	/*
	* @brief Asks the player to select a card from their hand.
	* @param player Player that is currently playing
	* @return Index of the card that is selected
	*/
	static int selectEquipmentCard(Player& player);
	/*
	* @brief Asks the player to decide whether they want to do an action with card from hand or equipment.
	* @return True if the player wants to play a card from hand, false if they want to play a card from equipment
	*/
	static bool fromHandOrEquipment();
};

