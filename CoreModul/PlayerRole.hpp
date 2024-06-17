#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

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
private:
	std::vector<PlayerRole> roles;
    int totalPlayers;
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

