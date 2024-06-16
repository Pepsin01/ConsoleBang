#include "BangCard.hpp"

BangCard::BangCard(GameStateControllor& gameState, CardColor color) : 
	PlayableCard(gameState, "Bang", "Bang - description", color)
{}

bool BangCard::execute(Player & player)
{
	return false;
}
