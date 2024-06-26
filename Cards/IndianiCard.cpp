#include "IndianiCard.hpp"

using namespace std;

IndianiCard::IndianiCard(GameStateController& gameState, CardColor color) :
	PlayableCard(gameState, "Indiani (Playable)", "Every other player that doesn't return fire with Bang! looses 1 health", color)
{}

bool IndianiCard::execute(Player & player)
{
	for (int i = 0; i < static_cast<int>(gameState.playerCount()); i++)
	{
		if (i == gameState.getCurrentPlayerIndex())
			continue;
		shared_ptr<Player> targetPlayer = gameState.getPlayer(i);
		if (!targetPlayer->returnFire())
			targetPlayer->changeHealth(-1);
	}
	return true;
}
