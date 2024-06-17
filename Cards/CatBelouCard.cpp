#include "CatBelouCard.hpp"

using namespace std;

CatBelouCard::CatBelouCard(GameStateControllor& gameState, CardColor color) :
	PlayableCard(gameState, "Cat Belou (Playable)", "Discard random card from target players hand or choose one from his equipment", color)
{
}

bool CatBelouCard::execute(Player& player)
{
	int targetPlayerIndex = CardUIInput::selectCastTarget(gameState, *this);
	if (targetPlayerIndex == -1)
		return false;

	shared_ptr<Player> targetPlayer = gameState.getPlayer(targetPlayerIndex);
	// Ask player to select card from hand or equipment
	if (CardUIInput::fromHandOrEquipment())
	{
		// Check if targeted player has cards in hand
		if (targetPlayer->getHandSize() == 0)
		{
			CardUIOutput::cannotBePlayed("Target player has no cards in hand.");
			return false;
		}
		gameState.discardCard(move(targetPlayer->handRandomCard()));
		return true;
	}
	else
	{
		// Check if targeted player has equipment cards
		if (targetPlayer->getEquipmentSize() == 0)
		{
			CardUIOutput::cannotBePlayed("Target player has no equipment cards.");
			return false;
		}
		// Ask player to select equipment card
		int cardIndex = CardUIInput::selectEquipmentCard(*targetPlayer); 
		gameState.discardCard(move(targetPlayer->handEquipmentCard(cardIndex)));
		return true;
	}
}
