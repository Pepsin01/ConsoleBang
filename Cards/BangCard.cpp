#include "BangCard.hpp"

using namespace std;

BangCard::BangCard(GameStateController& gameState, CardColor color) : 
	PlayableCard(gameState, "Bang (Playable)", "Applies a bang effect on chosen player", color)
{}

bool BangCard::execute(Player& player)
{
	int targetPlayerIndex = CardUIInput::selectCastTarget(gameState, *this);
	if (targetPlayerIndex == -1)
		return false;

	if (gameState.calculateDistance(gameState.getCurrentPlayerIndex(), targetPlayerIndex) > player.calculateRange())
	{
		CardUIOutput::cannotBePlayed("Target player is out of range.");
		return false;
	}

	if (!player.tryPlayBang())
	{
		CardUIOutput::cannotBePlayed("Number of played bangs exceeded for this turn.");
		return false;
	}

	shared_ptr<Player> targetPlayer = gameState.getPlayer(targetPlayerIndex);
	if (!targetPlayer->defendBangEffect())
		targetPlayer->changeHealth(-1);
	return true;
}
