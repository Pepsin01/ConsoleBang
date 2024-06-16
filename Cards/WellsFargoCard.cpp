#include "WellsFargoCard.hpp"

WellsFargoCard::WellsFargoCard(GameStateControllor& gameState, CardColor color) :
	PlayableCard(gameState, "Wells Fargo", "Wells Fargo - description", color)
{}

bool WellsFargoCard::execute(Player & player)
{
	return false;
}
