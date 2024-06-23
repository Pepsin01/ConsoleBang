#include "PanicoCard.hpp"

using namespace std;

PanicoCard::PanicoCard(GameStateController& gameState, CardColor color) : 
	PlayableCard(gameState, "Panico (Playable)", 
		"Take random card from another player hand or choose one from his equipment. " 
		"This card has range of 1."
		, color
	){}

bool PanicoCard::execute(Player& player)
{
	int targetPlayerIndex = CardUIInput::selectCastTarget(gameState, *this);
	if (targetPlayerIndex == -1)
		return false;

	// Check if target player is in range
	if (gameState.calculateDistance(gameState.getCurrentPlayerIndex(), targetPlayerIndex) > player.calculateRangeWithoutWeapon() + 1)
	{
		CardUIOutput::cannotBePlayed("Target player is out of range.");
		return false;
	}

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
		player.receiveCard(move(targetPlayer->handRandomCard()));
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
		player.receiveCard(move(targetPlayer->handEquipmentCard(cardIndex)));
		return true;
	}
}
