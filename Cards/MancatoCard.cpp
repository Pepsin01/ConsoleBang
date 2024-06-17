#include "MancatoCard.hpp"

MancatoCard::MancatoCard(GameStateControllor& gameState, CardColor color) :
	ReactionCard(gameState, "Mancato (Reaction)", "If in your hand while targeted by Bang! effect then is discarded and you don't loose health", color)
{}
