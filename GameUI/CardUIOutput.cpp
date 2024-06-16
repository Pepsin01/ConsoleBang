#include "CardUIOutput.hpp"

using namespace std;

vector<string> CardUIOutput::divideIntoLines(const string& text, int lineLength)
{
    vector<string> result;
    istringstream iss(text);
    string word;
    string currentLine;

    while (iss >> word) {
        // Check if adding the word would exceed the line length
        if (currentLine.length() + word.length() + 1 > lineLength) {
            // If the word itself is longer than the line length, split it
            while (word.length() > lineLength) {
                currentLine = word.substr(0, lineLength - 1) + "-";
                result.push_back(currentLine);
                word = word.substr(lineLength - 1);
                currentLine.clear();
            }
            // Add the remaining part of the word to a new line if it fits
            if (!currentLine.empty()) {
                result.push_back(currentLine);
                currentLine.clear();
            }
            currentLine = word;
        }
        else {
            // Add the word to the current line
            if (!currentLine.empty()) {
                currentLine += " ";
            }
            currentLine += word;
        }

        // If the current line is exactly the line length, move to next line
        if (currentLine.length() == lineLength) {
            result.push_back(currentLine);
            currentLine.clear();
        }
    }

    // Add any remaining text in the current line
    if (!currentLine.empty()) {
        result.push_back(currentLine);
    }

    return result;
}

string CardUIOutput::render(Card& card)
{
	string result = string(CARD_WIDTH, '_');
	result += "|" + string(CARD_WIDTH - 2, ' ') + "|";
	result += "| Name: " + card.name + string(CARD_WIDTH - 9 - card.name.size(), ' ') + "|";
    result += "|" + string(CARD_WIDTH - 2, '-') + "|";

    vector<string> descriptionLines = divideIntoLines("Description: " + card.description, CARD_WIDTH - 4);
    for (const string& line : descriptionLines) {
		result += "| " + line + string(CARD_WIDTH - 3 - line.size(), ' ') + "|";
	}

	result += "|" + string(CARD_WIDTH - 2, '-') + "|";

    string colorString;
	switch (card.color)
	{
	case CardColor::HEARTS:
        colorString = "Hearts";
		break;
	case CardColor::DIAMONDS:
        colorString = "Diamonds";
		break;
	case CardColor::CLUBS:
        colorString = "Clubs";
		break;
	case CardColor::SPADES:
        colorString = "Spades";
		break;
	}

    result += "| Color: " + colorString + string(CARD_WIDTH - 10 - colorString.size(), ' ') + "|";
    result += "|" + string(CARD_WIDTH - 2, '_') + "|";

	return result;
}

std::string CardUIOutput::sliceCard(const std::string& card)
{
    string result;
    int cardHeight = card.size() / CARD_WIDTH;
    for (int i = 0; i < cardHeight; i++) {
		result += card.substr(i * CARD_WIDTH, CARD_WIDTH) + '\n';
	}
    return result;
}
