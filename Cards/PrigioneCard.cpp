#include "PrigioneCard.hpp"

PrigioneCard::PrigioneCard(GameStateControllor& gameState, CardColor color) : 
	DebuffCard(gameState, "Prigione (Debuff)",
		"Can be put in other players equipment. "
		"If still there at the start of their turn they pass their turn.",
		color
	)
{
}
