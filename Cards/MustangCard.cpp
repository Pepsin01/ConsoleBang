#include "MustangCard.hpp"

MustangCard::MustangCard(GameStateController& gameState, CardColor color) : 
	BlueCard(gameState, "Mustang (Equipment)",
		"Distance from other players to is increased by 1", color)
{
}
