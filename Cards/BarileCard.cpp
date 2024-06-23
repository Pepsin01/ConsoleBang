#include "BarileCard.hpp"

BarileCard::BarileCard(GameStateController& gameState, CardColor color) : 
	BlueCard(gameState, "Barile (Equipment)",
		"When you are targeted by Bang! effect card from the deck is drawn. "
		"If it's hearts then the Mancato effect is applied",
		color)
{
}
