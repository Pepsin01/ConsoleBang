#include "SaloonCard.hpp"

SaloonCard::SaloonCard(GameStateController& gameState, CardColor color) :
	PlayableCard(gameState, "Saloon (Playable)", "Heals every player by 1", color)
{
}

bool SaloonCard::execute(Player& player)
{
	for (size_t i = 0; i < gameState.playerCount(); i++)
	{
		gameState.getPlayer(i)->changeHealth(1);
	}
	return true;
}
