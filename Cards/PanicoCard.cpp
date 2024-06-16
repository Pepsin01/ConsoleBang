#include "PanicoCard.hpp"

PanicoCard::PanicoCard(GameStateControllor& gameState, CardColor color) : 
	PlayableCard(gameState, "Panico", "Panico - description", color)
{
}

bool PanicoCard::execute(Player& player)
{
	return false;
}
