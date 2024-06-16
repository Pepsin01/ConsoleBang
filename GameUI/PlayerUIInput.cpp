#include "PlayerUIInput.hpp"

using namespace std;

bool PlayerUIInput::parseCommand(Player& player) {
    cout <<
        "Possible commands:\n"
        "1. PLAY <card number> - Triggers the play action with a card on given index in your hand.\n"
        "2. DISCARD <card number> - Triggers the discard action with a card on given index in your hand.\n"
        "3. END - Ends your turn if you don't have more cards in your hand than is the number of your current health\n"
        "4. SHOW <player number> - Shows the equipment cards and health of the player on given index.\n";

    string input;
    getline(cin, input);
    stringstream ss(input);
    string command;
    ss >> command;

    if (command == "PLAY") {
        int cardIndex;
        if (ss >> cardIndex && cardIndex >= 0 && cardIndex < player.getHandSize()) {
            player.playCard(cardIndex);
        }
        else {
            GameUIOutput::renderScreen(
                "Invalid command format for PLAY.\n\n"
                "Press ENTER to continue.\n"
            );
            GameUIInput::waitForEnter();
        }
    }
    else if (command == "DISCARD") {
        int cardIndex;
        if (ss >> cardIndex && cardIndex >= 0 && cardIndex < player.getHandSize()) {
            player.discardCard(cardIndex);
        }
        else {
            GameUIOutput::renderScreen(
                "Invalid command format for DISCARD.\n\n"
                "Press ENTER to continue.\n"
            );
            GameUIInput::waitForEnter();
        }
    }
    else if (command == "END") {
        if (player.getHandSize() <= player.getHealth()) {
			return true;
		}
		else {
            GameUIOutput::renderScreen(
                "You have more cards in your hand than is the number of your current health.\n\n"
                "Press ENTER to continue.\n"
            );
            GameUIInput::waitForEnter();
		}
    }
    else if (command == "SHOW") {
        int playerIndex;
        if (ss >> playerIndex) {
            shared_ptr<Player> p = player.getGameState().getPlayer(playerIndex);
            if (p) {
				p->showPublicProfile();
			}
			else {
				GameUIOutput::renderScreen(
					"Player with given index does not exist.\n\n"
					"Press ENTER to continue.\n"
				);
				GameUIInput::waitForEnter();
			}
        }
        else {
            GameUIOutput::renderScreen(
                "Invalid command format for SHOW.\n\n"
                "Press ENTER to continue.\n"
            );
        }
    }
    else {
        GameUIOutput::renderScreen(
            "Unknown command.\n"
            "Press ENTER to continue.\n"
        );
        GameUIInput::waitForEnter();
    }
    return false;
}