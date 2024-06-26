#include "GatlingCard.hpp"

using namespace std;

GatlingCard::GatlingCard(GameStateController& gameState, CardColor color) : 
	PlayableCard(gameState, "Gatling (Playable)", "Applies bang effect on all the other players", color)
{}

bool GatlingCard::execute(Player & player)
{
	for (int i = 0; i < static_cast<int>(gameState.playerCount()); i++)
	{
		if (i == gameState.getCurrentPlayerIndex())
			continue;
		shared_ptr<Player> targetPlayer = gameState.getPlayer(i);
		if (!targetPlayer->defendBangEffect())
			targetPlayer->changeHealth(-1);
	}
	return true;
}
