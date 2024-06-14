#include "IndianiCard.hpp"

IndianiCard::IndianiCard(GameStateControllor& gameState, CardColor color) :
	PlayableCard(gameState, "Indiani", "Indiani - description", color)
{}

void IndianiCard::execute()
{
}
