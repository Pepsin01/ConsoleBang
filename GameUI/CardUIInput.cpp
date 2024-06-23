#include "CardUIInput.hpp"

using namespace std;

int CardUIInput::selectCastTarget(GameStateController& gameState, Card& card)
{
	int playerIndex = -1;
	while (true)
	{
		// Give the player the information about the card they are casting
		GameUIOutput::renderScreen(
			"You are casting this card:\n" +
			CardUIOutput::sliceCard(CardUIOutput::render(card)) + "\n"
			"Possible commands:\n"
			"SHOW <player number> - Shows the equipment cards and health of the player on given index.\n"
			"CAST <player number> - Casts a card on given index in your hand on the player on given index.\n"
			"RETURN - Stops card from being casted.\n"
		);

		// Get the input from the player
		string input;
		getline(cin, input);
		stringstream ss(input);
		string command;
		ss >> command;

		if (command == "SHOW") {
			if (ss >> playerIndex && playerIndex >= 0 && playerIndex < static_cast<int>(gameState.playerCount())) { // Check if the player index is valid
				gameState.getPlayer(playerIndex)->showPublicProfile();
			}
			else {
				GameUIOutput::renderScreen(
					"Invalid command format for SHOW.\n\n"
					"Press ENTER to continue.\n"
				);
				GameUIInput::waitForEnter();
			}
		}
		else if (command == "CAST") {
			if (ss >> playerIndex && playerIndex >= 0 && playerIndex < static_cast<int>(gameState.playerCount())) { // Check if the player index is valid
				return playerIndex;
			}
			GameUIOutput::renderScreen(
				"Invalid command format for CAST.\n\n"
				"Press ENTER to continue.\n"
			);
			GameUIInput::waitForEnter();
		}
		else if (command == "RETURN") {
			return -1; // Return -1 to signal that the card should not be casted
		}
		else {
			GameUIOutput::renderScreen(
				"Invalid command.\n\n"
				"Press ENTER to continue.\n"
			);
			GameUIInput::waitForEnter();
		}
	}
}

int CardUIInput::selectEquipmentCard(Player& player)
{
	int cardIndex = -1;
	while (true)
	{
		// Give the player the information about the command they can use
		GameUIOutput::renderScreen(
			"Possible commands:\n"
			"SHOW - Shows the equipment cards and health of the player.\n"
			"SELECT <card number> - Selects a card from the equipment.\n"
			"RETURN - Stops card from being casted.\n"
		);

		// Get the input from the player
		string input;
		getline(cin, input);
		stringstream ss(input);
		string command;
		ss >> command;

		if (command == "SHOW") {
			player.showPublicProfile();
		}
		else if (command == "SELECT") {
			if (ss >> cardIndex && cardIndex >= 0 && cardIndex < player.getEquipmentSize()) { // Check if the card index is valid
				return cardIndex;
			}
			GameUIOutput::renderScreen(
				"Invalid command format for SELECT.\n\n"
				"Press ENTER to continue.\n"
			);
			GameUIInput::waitForEnter();
		}
		else if (command == "RETURN") {
			return -1;
		}
		else {
			GameUIOutput::renderScreen(
				"Invalid command.\n\n"
				"Press ENTER to continue.\n"
			);
			GameUIInput::waitForEnter();
		}
	}
}

bool CardUIInput::fromHandOrEquipment()
{
	while (true)
	{
		// Give the player the information about the command they can use
		GameUIOutput::renderScreen(
			"From where do you want to take the player the card?\n"
			"Possible commands:\n"
			"1. HAND - Selects a random card from players hand.\n"
			"2. EQUIPMENT - Selects a card from players equipment.\n"
		);

		// Get the input from the player
		string input;
		getline(cin, input);
		stringstream ss(input);
		string command;
		ss >> command;

		if (command == "HAND") {
			return true;
		}
		if (command == "EQUIPMENT") {
			return false;
		}
		GameUIOutput::renderScreen(
			"Invalid command.\n\n"
			"Press ENTER to continue.\n"
		);
		GameUIInput::waitForEnter();
	}
}
