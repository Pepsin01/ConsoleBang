#include "BirraCard.hpp"

BirraCard::BirraCard(GameStateControllor& gameState, CardColor color) : 
	PlayableCard(gameState, "Birra", "Birra - description", color)
{}

bool BirraCard::execute(Player & player)
{
	return false;
}
