#include "Player.hpp"

void Player::playCard(GameStateControllor& gameState, int cardIndex)
{
}

Player::Player(PlayerRole role) : role(role)
{
	if (role == SHERIF)
		health = 5;
	else
		health = 4;
}
