#include "VolcanicCard.hpp"

VolcanicCard::VolcanicCard(GameStateControllor& gameState, CardColor color) : 
	WeaponCard(gameState, "Volcanic", "Volcanic - description", color, 1)
{
}
