#include "GameUIOutput.hpp"
#include <iostream>
using namespace std;

GameUIOutput::GameUIOutput() :
	beforeStartMessage(
		string("\nWelcome to ConsoleBang!\n\n") +
		"1. Set the resolution of this window so that the \"Xs\" fill it exactly.\n\n" +
		"2. Press Enter and enjoy the game.\n\n"
	),
	rulesMessage("Game Rules:\n\n"),
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
