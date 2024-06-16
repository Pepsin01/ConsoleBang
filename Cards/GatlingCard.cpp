#include "GatlingCard.hpp"

GatlingCard::GatlingCard(GameStateControllor& gameState, CardColor color) : 
	PlayableCard(gameState, "Gatling", "Gatling - description", color)
{}

bool GatlingCard::execute(Player & player)
{
	return false;
}
