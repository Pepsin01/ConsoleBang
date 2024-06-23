#pragma once
#include <vector>

enum PlayerRole
{
    SHERIF,
    VICE,
    BANDIT,
    RENEGADE
};

/*
* @brief Class that randomizes the player's role
*/
class PlayerRoleRandomizer
{
	std::vector<PlayerRole> roles_;
public:
    /*
    * @brief Constructor
    * @param totalPlayers Total number of players in the game
	*/
	PlayerRoleRandomizer(int totalPlayers);

	/*
	* @brief Returns the next random role
	* @return Next role
	*/
	PlayerRole getNextRole();
};

