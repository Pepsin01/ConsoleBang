#include "IndianiCard.hpp"

IndianiCard::IndianiCard(GameStateControllor& gameState, CardColor color) :
	PlayableCard(gameState, "Indiani", "Indiani - description", color)
{}

bool IndianiCard::execute(Player & player)
{
	return false;
}
