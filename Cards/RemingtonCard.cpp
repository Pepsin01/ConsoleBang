#include "RemingtonCard.hpp"

RemingtonCard::RemingtonCard(GameStateController& gameState, CardColor color) : 
	WeaponCard(gameState, "Remington (Weapon)",
		"Extends range by 3. Only one weapon could be equipped at a time",
		color, 3)
{
}
