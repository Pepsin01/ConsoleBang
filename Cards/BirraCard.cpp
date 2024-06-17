#include "BirraCard.hpp"

BirraCard::BirraCard(GameStateControllor& gameState, CardColor color) : 
	PlayableCard(gameState, "Birra (Playable)", "Heals you by 1", color)
{}

bool BirraCard::execute(Player & player)
{
	player.changeHealth(1);
	return true;
}
