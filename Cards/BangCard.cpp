#include "BangCard.hpp"

BangCard::BangCard(GameStateControllor& gameState, CardColor color) : 
	PlayableCard(gameState, "Bang", "Bang - description", color)
{}

void BangCard::execute()
{
}
