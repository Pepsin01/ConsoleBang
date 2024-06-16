#include "CatBelouCard.hpp"

CatBelouCard::CatBelouCard(GameStateControllor& gameState, CardColor color) :
	PlayableCard(gameState, "Cat Belou", "Cat Belou - description", color)
{
}

bool CatBelouCard::execute(Player& player)
{
	return false;
}
