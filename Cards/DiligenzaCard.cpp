#include "DiligenzaCard.hpp"

using namespace std;

DiligenzaCard::DiligenzaCard(GameStateControllor& gameState, CardColor color) :
	PlayableCard(gameState, "Diligenza (Playable)", "Play this card and instantly draw two new cards.", color)
{
}

bool DiligenzaCard::execute(Player& player)
{
	for (size_t i = 0; i < 2; i++)
	{
		unique_ptr<Card> card = gameState.drawCard();
		if (card)
			player.receiveCard(move(card));
		else {
			CardUIOutput::cannotBePlayed("No more cards in the deck.");
			return false;
		}
	}
	return true;
}
