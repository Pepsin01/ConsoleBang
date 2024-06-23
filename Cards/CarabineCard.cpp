#include "CarabineCard.hpp"

CarabineCard::CarabineCard(GameStateController& gameState, CardColor color) :
	WeaponCard(gameState, "Carabine (Weapon)",
		"Extends range by 4. Only one weapon could be equipped at a time",
		color, 4)
{
}
