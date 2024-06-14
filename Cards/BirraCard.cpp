#include "BirraCard.hpp"

BirraCard::BirraCard(GameStateControllor& gameState, CardColor color) : 
	PlayableCard(gameState, "Birra", "Birra - description", color)
{}

void BirraCard::execute()
{
}
