#include "SchofieldCard.hpp"

SchofieldCard::SchofieldCard(GameStateController& gameState, CardColor color) :
	WeaponCard(gameState, "Schofield (Weapon)",
		"Extends range by 2. Only one weapon could be equipped at a time",
		color, 2)
{
}
