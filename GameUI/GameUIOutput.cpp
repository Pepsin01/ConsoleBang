#include "GameUIOutput.hpp"
#include <iostream>
using namespace std;

GameUIOutput::GameUIOutput() :
	beforeStartMessage(
		string("\nWelcome to ConsoleBang!\n\n") +
		"1. Set the resolution of this window so that the \"Xs\" fill it exactly.\n\n" +
		"2. Press Enter and enjoy the game.\n\n"
	),
	rulesMessage(
		string("Rules:\n\n") +
		"	Objective:\n"
		"		The objective varies depending on the role you are assigned.\n"
		"		- Sheriff: Eliminate all Bandit and the Renegade.\n"
		"		- Vice: Protect the Sheriff and help eliminate all Bandit and the Renegade.\n"
		"		- Bandit: Kill the Sheriff\n"
		"		- Renegade: Be the last player alive.\n"
		"	Game Play:\n"
		"		1. Turn Sequence:\n"
		"			-Draw: Draw two cards from the deck.\n"
		"			-Play: Play any number of cards from your hand.\n"
		"			-Discard: At the end of your turn, discard cards if you have more cards in your hand than your current life points.\n"

		"		2. Special Rules:\n"
		"			-Distance and Range: The distance between players affects the range of your attacks.\n"
		"			Weapons and other cards can modify this range.\n"
		"			-Death: When a player loses all their health, they are out of the game.Their role is revealed.\n"
	),
	nextPlayerWarningMessage(
		string("WARNING!\n\n") + 
		"Next player's turn will start. Prevent other players form looking at the screen!\n\n" + 
		"Press Enter to continue.\n\n"
	),
	endGameMessage("Game Over!\n\n")
{}

void GameUIOutput::startGameScreen()
{
	cout << wrapWithXs(beforeStartMessage);
}

void GameUIOutput::gameRulesScreen()
{
	cout << wrapWithXs(rulesMessage);
}

void GameUIOutput::endGameScreen()
{
	cout << wrapWithXs(endGameMessage);
}

void GameUIOutput::nextPlayerWarningScreen()
{
	cout << wrapWithXs(nextPlayerWarningMessage);
}

void GameUIOutput::renderScreen(const std::string& text)
{
	cout << wrapWithXs(text);
}

std::string GameUIOutput::wrapWithXs(const std::string& text)
{
	int lineCount = 0;
	for (char c : text)
	{
		if(c == '\n') lineCount++;
	}
	int i = 0;
	string wrappedText = "";
	while (lineCount + i < SCREEN_HEIGHT)
	{
		wrappedText += xLine;
		i++;
	}
	wrappedText += text;
	return wrappedText;
}
