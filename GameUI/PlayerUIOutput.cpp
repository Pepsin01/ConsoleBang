#include "PlayerUIOutput.hpp"

using namespace std;

void PlayerUIOutput::playerPublicScreen(const string& role, int health, int maxHealth, vector<unique_ptr<Card>>& equipment)
{
	string result = "Player's role: " + role + "\n";
	result += "Health: " + to_string(health) + "/" + to_string(maxHealth) + "\n";
	result += "Equipment cards:\n";
	result += renderCardVector(equipment);
	result += "\n";
	GameUIOutput::renderScreen(
		result +
		"Press ENTER to continue.\n"
	);
	GameUIInput::waitForEnter();

}

void PlayerUIOutput::playerPrivateScreen(int playerNumber, const string& role, int health, int maxHealth, vector<unique_ptr<Card>>& hand, vector<unique_ptr<Card>>& equipment)
{
	string result = "Player " + to_string(playerNumber) + " - " + role + "\n";
	result += "Health: " + to_string(health) + "/" + to_string(maxHealth) + "\n";
	result += "Cards in hand:\n";
	result += renderCardVector(hand);
	result += "Equipment cards:\n";
	result += renderCardVector(equipment);
	result += "\n";
	GameUIOutput::renderScreen(result);
}

void PlayerUIOutput::playerDeadScreen()
{
	GameUIOutput::renderScreen("You are dead!\n\nPress ENTER to continue.\n");
	GameUIInput::waitForEnter();
}

void PlayerUIOutput::playerJailScreen()
{
	GameUIOutput::renderScreen("You are in jail!\n\nPress ENTER to continue.\n");
	GameUIInput::waitForEnter();
}

void PlayerUIOutput::cannotPlayCardScreen(Card& card)
{
	GameUIOutput::renderScreen(
		"You cannot play this card now!\n" +
		CardUIOutput::sliceCard(CardUIOutput::render(card)) +
		"\nPress ENTER to continue.\n"
	);
	GameUIInput::waitForEnter();
}

string PlayerUIOutput::renderCardVector(vector<unique_ptr<Card>>& cards)
{
	if (cards.empty())
		return "No cards\n";
	// Render all card strings
	vector<string> cardStrings;
	for (size_t i = 0; i < cards.size(); i++)
	{
		cardStrings.push_back(CardUIOutput::render(*cards[i]));
	}
	
	// Find the tallest card
	int tallestCard = 0;
	for (size_t i = 0; i < cards.size(); i++)
	{
		if (static_cast<int>(cardStrings[i].size()) > tallestCard)
		{
			tallestCard = static_cast<int>(cardStrings[i].size());
		}
	}
	tallestCard /= CardUIOutput::CARD_WIDTH; // Divide by the width to get number lines in a card

	string result; // The final result
	int cardsRendered = 0; // Number of cards rendered so far

	// Render the cards side by side
	while (cardsRendered < static_cast<int>(cards.size()))
	{
		// Render the slot numbers for each card
		for (size_t j = cardsRendered; j < ((cardStrings.size() - cardsRendered < GameUIOutput::SCREEN_WIDTH / CardUIOutput::CARD_WIDTH) ? cardStrings.size() : GameUIOutput::SCREEN_WIDTH / CardUIOutput::CARD_WIDTH); j++)
		{
			result += to_string(j) + string(CardUIOutput::CARD_WIDTH - to_string(j).size(), ' ');
		}
		result += '\n';
		// Render the cards line by line
		for (int i = 0; i < tallestCard; i++)
		{
			// Render each line of each card
			for (size_t j = cardsRendered; j < ((cardStrings.size() - cardsRendered < GameUIOutput::SCREEN_WIDTH / CardUIOutput::CARD_WIDTH) ? cardStrings.size() : GameUIOutput::SCREEN_WIDTH / CardUIOutput::CARD_WIDTH); j++)
			{
				// If the card is shorter than the current line, fill with spaces
				if (static_cast<int>(cardStrings[j].size()) <= i * CardUIOutput::CARD_WIDTH)
					result += string(CardUIOutput::CARD_WIDTH, ' ');
				else
					result += cardStrings[j].substr(i * CardUIOutput::CARD_WIDTH, CardUIOutput::CARD_WIDTH);
			}
			result += '\n';
		}
		result += '\n';
		cardsRendered += GameUIOutput::SCREEN_WIDTH / CardUIOutput::CARD_WIDTH; // Move to the next row of cards
	}

	return result;
}
