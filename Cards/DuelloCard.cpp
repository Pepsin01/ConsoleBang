#include "DuelloCard.hpp"

DuelloCard::DuelloCard(GameStateControllor& gameState, CardColor color) :
	PlayableCard(gameState, "Duello", "Duello - description", color)
{}

void DuelloCard::execute()
{
}
