#include "PanicoCard.hpp"

PanicoCard::PanicoCard(GameStateControllor& gameState, CardColor color) : 
	PlayableCard(gameState, "Panico", "Panico - description", color)
{
}

void PanicoCard::execute()
{
}
