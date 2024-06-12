#pragma once
#include <vector>

enum PlayerRole
{
    SHERIF,
    VICE,
    BANDIT,
    RENEGADE
};

class PlayerRoleRandomizer
{
	private:
		std::vector<PlayerRole> roles;
        int totalPlayers;
	public:
		PlayerRoleRandomizer(int totalPlayers);
		PlayerRole getNextRole();
};

