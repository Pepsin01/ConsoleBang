#include "PlayerUIOutput.hpp"

using namespace std;

void PlayerUIOutput::playerPublicScreen(int playerNumber, const string& role, int health, int maxHealth, vector<unique_ptr<Card>>& equipment)
{
	string result = "Player " + to_string(playerNumber) + " - " + role + "\n";
	result += "Health: " + to_string(health) + "/" + to_string(maxHealth) + "\n";
	result += "Equipment:\n";
	result += renderCardVector(equipment);
	result += "\n";
	GameUIOutput::renderScreen(result);
}

void PlayerUIOutput::playerPrivateScreen(int playerNumber, const string& role, int health, int maxHealth, vector<unique_ptr<Card>>& hand, vector<unique_ptr<Card>>& equipment)
{
	GameUIOutput gameUIOutput;
	string result = "Player " + to_string(playerNumber) + " - " + role + "\n";
	result += "Health: " + to_string(health) + "/" + to_string(maxHealth) + "\n";
	result += "Cards in hand:\n";
	result += renderCardVector(hand);
	result += "Equipment cards:\n";
	result += renderCardVector(equipment);
	result += "\n";
	GameUIOutput::renderScreen(result);
}

string PlayerUIOutput::renderCardVector(vector<unique_ptr<Card>>& cards)
{
	if (cards.empty())
		return "No cards\n";
	// Render all card strings
	vector<string> cardStrings;
	CardUIOutput cardUIOutput;
	for (size_t i = 0; i < cards.size(); i++)
	{
		cardStrings.push_back(cardUIOutput.render(*cards[i]));
	}
	
	// Find the tallest card
	int tallestCard = 0;
	for (size_t i = 0; i < cards.size(); i++)
	{
		if (cardStrings[i].size() > tallestCard)
		{
			tallestCard = cardStrings[i].size();
		}
	}
	tallestCard /= CARD_WIDTH; // Divide by the width to get number lines in a card

	string result; // The final result
	int cardsRendered = 0; // Number of cards rendered so far

	// Render the cards side by side
	while (cardsRendered < cards.size())
	{
		// Render the slot numbers for each card
		for (size_t j = cardsRendered; j < ((cardStrings.size() - cardsRendered < SCREEN_WIDTH / CARD_WIDTH) ? cardStrings.size() - cardsRendered : SCREEN_WIDTH / CARD_WIDTH); j++)
		{
			result += to_string(j) + string(CARD_WIDTH - to_string(j).size(), ' ');
		}
		result += '\n';
		// Render the cards line by line
		for (int i = 0; i < tallestCard; i++)
		{
			// Render each line of each card
			for (size_t j = cardsRendered; j < ((cardStrings.size() - cardsRendered < SCREEN_WIDTH / CARD_WIDTH) ? cardStrings.size() - cardsRendered : SCREEN_WIDTH / CARD_WIDTH); j++)
			{
				// If the card is shorter than the current line, fill with spaces
				if (cardStrings[j].size() < i * CARD_WIDTH)
					result += string(CARD_WIDTH, ' ');
				else
					result += cardStrings[j].substr(i * CARD_WIDTH, CARD_WIDTH);
			}
			result += '\n';
		}
		result += '\n';
		cardsRendered += SCREEN_WIDTH / CARD_WIDTH; // Move to the next row of cards
	}

	return result;
}
