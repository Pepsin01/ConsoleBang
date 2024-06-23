#include "PlayerRole.hpp"
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

PlayerRoleRandomizer::PlayerRoleRandomizer(const int totalPlayers)
{
	// These two roles are always present in the game
	roles_.push_back(SHERIF);
	roles_.push_back(RENEGADE);
	
	if (totalPlayers >= 5)
		roles_.push_back(VICE);
	if (totalPlayers == 7)
		roles_.push_back(VICE);

	const size_t size = roles_.size();

	// Fill the rest of the roles with bandits
	for (size_t i = 0; i < totalPlayers - size; i++)
		roles_.push_back(BANDIT);

	shuffle(roles_.begin(), roles_.end(), default_random_engine(time(nullptr)));
}

PlayerRole PlayerRoleRandomizer::getNextRole()
{
	const PlayerRole role = roles_.back();
	roles_.pop_back();
	return role;
}
