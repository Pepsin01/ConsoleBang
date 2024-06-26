#include "EmporioCard.hpp"

using namespace std;

EmporioCard::EmporioCard(GameStateController& gameState, CardColor color) : 
	PlayableCard(gameState, "Emporio (Playable)", "Draws and gives a card to each player", color)
{}

bool EmporioCard::execute(Player & player)
{
	for (int i = 0; i < static_cast<int>(gameState.playerCount()); i++)
	{
		unique_ptr<Card> card = gameState.drawCard();
		if (card)
			gameState.getPlayer(i)->receiveCard(move(card));
		else {
			CardUIOutput::cannotBePlayed("No more cards in the deck.");
			return true;
		}
	}
	return true;
}
