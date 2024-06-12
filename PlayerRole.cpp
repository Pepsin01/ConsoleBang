#include "PlayerRole.hpp"

PlayerRoleRandomizer::PlayerRoleRandomizer(int totalPlayers) : totalPlayers(totalPlayers)
{
}

PlayerRole PlayerRoleRandomizer::getNextRole()
{
    return PlayerRole();
}
