#include "EmporioCard.hpp"

EmporioCard::EmporioCard(GameStateControllor& gameState, CardColor color) : 
	PlayableCard(gameState, "Emporio", "Emporio - description", color)
{}

void EmporioCard::execute()
{
}
