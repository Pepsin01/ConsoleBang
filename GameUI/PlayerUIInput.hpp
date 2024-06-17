#pragma once
#include <iostream>
#include <string>
#include "../CoreModul/Player.hpp"
#include "GameUIOutput.hpp"
#include "GameUIInput.hpp"

/*
* @brief Class that handles the input for the player UI
*/
class PlayerUIInput
{
public:
	/*
	* @brief Gives the player the option which command can be executed and translates the input into actions in the game.
	* @param player Player that is currently playing
	* @return True if the player wants to end their turn, false otherwise
	*/
	static bool parseCommand(Player& player);
};

