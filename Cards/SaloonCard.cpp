#include "SaloonCard.hpp"

SaloonCard::SaloonCard(GameStateControllor& gameState, CardColor color) :
	PlayableCard(gameState, "Saloon", "Saloon - description", color)
{
}

void SaloonCard::execute()
{
}
