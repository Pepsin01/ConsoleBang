#include "SaloonCard.hpp"

SaloonCard::SaloonCard(GameStateController& gameState, CardColor color) :
	PlayableCard(gameState, "Saloon (Playable)", "Heals every player by 1", color)
{
}

bool SaloonCard::execute(Player& player)
{
	for (int i = 0; i < static_cast<int>(gameState.playerCount()); i++)
	{
		gameState.getPlayer(i)->changeHealth(1);
	}
	return true;
}
