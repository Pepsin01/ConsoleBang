#include "DiligenzaCard.hpp"

DiligenzaCard::DiligenzaCard(GameStateControllor& gameState, CardColor color) :
	PlayableCard(gameState, "Diligenza", "Diligenza - description", color)
{
}

bool DiligenzaCard::execute(Player& player)
{
	return false;
}
