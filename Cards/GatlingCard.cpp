#include "GatlingCard.hpp"

GatlingCard::GatlingCard(GameStateControllor& gameState, CardColor color) : 
	PlayableCard(gameState, "Gatling", "Gatling - description", color)
{}

void GatlingCard::execute()
{
}
