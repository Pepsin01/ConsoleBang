#include "PlayerRole.hpp"

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

	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(roles), std::end(roles), rng);
}

PlayerRole PlayerRoleRandomizer::getNextRole()
{
	PlayerRole role = roles.back();
	roles.pop_back();
	return role;
}
