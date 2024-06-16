#include "EmporioCard.hpp"

EmporioCard::EmporioCard(GameStateControllor& gameState, CardColor color) : 
	PlayableCard(gameState, "Emporio", "Emporio - description", color)
{}

bool EmporioCard::execute(Player & player)
{
	return false;
}
