#include "VolcanicCard.hpp"

VolcanicCard::VolcanicCard(GameStateController& gameState, CardColor color) : 
	WeaponCard(gameState, "Volcanic (Weapon)",
		"Allows you to play any number of BANG! cards",
		color, 1)
{
}
