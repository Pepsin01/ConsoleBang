#include "PlayerUIInput.hpp"

using namespace std;

bool PlayerUIInput::parseCommand(Player& player) {

    auto renderError = [](const std::string& message) {
        GameUIOutput::renderScreen(message + "\n\nPress ENTER to continue.\n");
        GameUIInput::waitForEnter();
        };

    // Display the possible commands
    cout <<
        "Possible commands:\n"
        "1. PLAY <card number> - Triggers the play action with a card on given index in your hand.\n"
        "2. DISCARD <card number> - Triggers the discard action with a card on given index in your hand.\n"
        "3. END - Ends your turn if you don't have more cards in your hand than is the number of your current health\n"
        "4. SHOW <player number> - Shows the equipment cards and health of the player on given index.\n";

    // Get the input from the player
    string input;
    getline(cin, input);
    stringstream ss(input);
    string command;
    ss >> command;

    if (command == "PLAY") {
        int cardIndex;
        if (ss >> cardIndex && cardIndex >= 0 && cardIndex < player.getHandSize()) { // Check if the card index is valid
            player.playCard(cardIndex);
        }
        else {
            renderError("Invalid command format for PLAY.");
        }
    }
    else if (command == "DISCARD") {
        int cardIndex;
        if (ss >> cardIndex && cardIndex >= 0 && cardIndex < player.getHandSize()) { // Check if the card index is valid
            player.discardCard(cardIndex);
        }
        else {
            renderError("Invalid command format for DISCARD.");
        }
    }
    else if (command == "END") {
        if (player.getHandSize() <= player.getHealth()) { // Check if the player has more cards in their hand than is the number of their current health
			return true;
		}
		else {
            renderError("You have more cards in your hand than is the number of your current health.");
		}
    }
    else if (command == "SHOW") {
        int playerIndex;
        if (ss >> playerIndex) { 
            shared_ptr<Player> p = player.getGameState().getPlayer(playerIndex); 
            if (p) { // Check if the player index is valid
				p->showPublicProfile();
			}
			else {
				renderError("Player with given index does not exist.");
			}
        }
        else {
            renderError("Invalid command format for SHOW.");
        }
    }
    else {
        renderError("Invalid command.");
    }
    return false;
}