#include "WellsFargoCard.hpp"

using namespace std;

WellsFargoCard::WellsFargoCard(GameStateController& gameState, CardColor color) :
	PlayableCard(gameState, "Wells Fargo (Playable)", "Play this card and instantly draw three new cards.", color)
{}

bool WellsFargoCard::execute(Player & player)
{
	for (size_t i = 0; i < 3; i++)
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
