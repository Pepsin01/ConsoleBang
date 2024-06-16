#include "SaloonCard.hpp"

SaloonCard::SaloonCard(GameStateControllor& gameState, CardColor color) :
	PlayableCard(gameState, "Saloon", "Saloon - description", color)
{
}

bool SaloonCard::execute(Player& player)
{
	return false;
}
