#include "WinchesterCard.hpp"

WinchesterCard::WinchesterCard(GameStateControllor& gameState, CardColor color) : 
	WeaponCard(gameState, "Winchester (Weapon)",
		"Extends range by 5. Only one weapon could be equipped at a time",
		color, 5)
{
}
