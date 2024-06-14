#include "CatBelouCard.hpp"

CatBelouCard::CatBelouCard(GameStateControllor& gameState, CardColor color) :
	PlayableCard(gameState, "Cat Belou", "Cat Belou - description", color)
{
}

void CatBelouCard::execute()
{
}
