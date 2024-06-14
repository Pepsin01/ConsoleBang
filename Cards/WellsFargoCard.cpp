#include "WellsFargoCard.hpp"

WellsFargoCard::WellsFargoCard(GameStateControllor& gameState, CardColor color) :
	PlayableCard(gameState, "Wells Fargo", "Wells Fargo - description", color)
{}

void WellsFargoCard::execute()
{
}
