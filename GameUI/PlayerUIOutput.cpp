#include "PlayerUIOutput.hpp"

using namespace std;

void PlayerUIOutput::playerPublicScreen(int playerNumber, const string& role, int health, int maxHealth, vector<unique_ptr<Card>>& equipment)
{
	GameUIOutput gameUIOutput;
	string result = "Player " + to_string(playerNumber) + " - " + role + "\n";
	result += "Health: " + to_string(health) + "/" + to_string(maxHealth) + "\n";
	result += "Equipment:\n";
	result += renderCardVector(equipment);
	gameUIOutput.renderScreen(result);
}

void PlayerUIOutput::playerPrivateScreen(int playerNumber, const string& role, int health, int maxHealth, vector<unique_ptr<Card>>& hand, vector<unique_ptr<Card>>& equipment)
{
	GameUIOutput gameUIOutput;
	string result = "Player " + to_string(playerNumber) + " - " + role + "\n";
	result += "Health: " + to_string(health) + "/" + to_string(maxHealth) + "\n";
	result += "Hand:\n";
	result += renderCardVector(hand);
	result += "Equipment:\n";
	result += renderCardVector(equipment);
	gameUIOutput.renderScreen(result);
}

string PlayerUIOutput::renderCardVector(vector<unique_ptr<Card>>& cards)
{
	// Render all cards
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
		for (int i = 0; i < tallestCard; i++)
		{
			for (size_t j = cardsRendered; j < ((cardStrings.size() - cardsRendered < SCREEN_WIDTH / CARD_WIDTH) ? cardStrings.size() - cardsRendered : SCREEN_WIDTH / CARD_WIDTH); j++)
			{
				result += cardStrings[j].substr(i * CARD_WIDTH, CARD_WIDTH);
			}
			result += '\n';
		}
		result += '\n';
		cardsRendered += SCREEN_WIDTH / CARD_WIDTH;
	}

	return result;
}
