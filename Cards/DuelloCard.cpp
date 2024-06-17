#include "DuelloCard.hpp"

using namespace std;

DuelloCard::DuelloCard(GameStateControllor& gameState, CardColor color) :
	PlayableCard(gameState, "Duello (Playable)",
		"Target player must return fire, then you must return fire and etc."
		"The last one who doesn't return fire looses 1 health",
		color
	)
{}

bool DuelloCard::execute(Player & player)
{
	int targetPlayerIndex = CardUIInput::selectCastTarget(gameState, *this);
	if (targetPlayerIndex == -1)
		return false;

	shared_ptr<Player> targetPlayer = gameState.getPlayer(targetPlayerIndex);
	while (true)
	{
		if (!targetPlayer->returnFire())
		{
			targetPlayer->changeHealth(-1);
			break;
		}
		if (!player.returnFire())
		{
			player.changeHealth(-1);
			break;
		}
	}
	return true;
}
