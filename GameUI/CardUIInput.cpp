#include "CardUIInput.hpp"

using namespace std;

int CardUIInput::selectCastTarget(GameStateControllor& gameState, Card& card)
{
	int playerIndex = -1;
	while (true)
	{
		GameUIOutput::renderScreen(
			"You are casting this card:\n" +
			CardUIOutput::sliceCard(CardUIOutput::render(card)) + "\n"
			"Possible commands:\n"
			"SHOW <player number> - Shows the equipment cards and health of the player on given index.\n"
			"CAST <player number> - Casts a card on given index in your hand on the player on given index.\n"
			"RETURN - Stops card from being casted.\n"
		);

		string input;
		getline(cin, input);
		stringstream ss(input);
		string command;
		ss >> command;

		if (command == "SHOW") {
			if (ss >> playerIndex && playerIndex >= 0 && playerIndex < gameState.playerCount()) {
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
			if (ss >> playerIndex && playerIndex >= 0 && playerIndex < gameState.playerCount()) {
				return playerIndex;
			}
			else {
				GameUIOutput::renderScreen(
					"Invalid command format for CAST.\n\n"
					"Press ENTER to continue.\n"
				);
				GameUIInput::waitForEnter();
			}
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
	return playerIndex;
}
