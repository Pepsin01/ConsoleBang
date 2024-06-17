#pragma once

/*
* @brief Class that handles the input for the game UI
*/
class GameUIInput
{
public:
	/*
	* @brief Waits for the player to press enter.
	* @return True if the player pressed enter, false otherwise
	*/
	static bool waitForEnter();
	/*
	* @brief Asks the player to input a number of players that will play the game.
	* @return Number of players
	*/
	static int getPlayerCount();
};

