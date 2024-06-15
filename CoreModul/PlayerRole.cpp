#include "PlayerRole.hpp"

using namespace std;

PlayerRoleRandomizer::PlayerRoleRandomizer(int totalPlayers) : totalPlayers(totalPlayers)
{
	roles.push_back(SHERIF);
	roles.push_back(RENEGADE);
	
	if (totalPlayers >= 5)
		roles.push_back(VICE);
	if (totalPlayers == 7)
		roles.push_back(VICE);

	int size = roles.size();

	for (int i = 0; i < totalPlayers - size; i++)
		roles.push_back(BANDIT);

	shuffle(begin(roles), end(roles), default_random_engine{ static_cast<unsigned int>(time(nullptr)) });
}

PlayerRole PlayerRoleRandomizer::getNextRole()
{
	PlayerRole role = roles.back();
	roles.pop_back();
	return role;
}
