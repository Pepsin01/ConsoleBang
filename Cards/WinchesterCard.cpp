#include "WinchesterCard.hpp"

WinchesterCard::WinchesterCard(GameStateControllor& gameState, CardColor color) : 
	WeaponCard(gameState, "Winchester", "Winchester - description", color, 5)
{
}
