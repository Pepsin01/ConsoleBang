#pragma once
#include <vector>
#include <algorithm>
#include <random>

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

