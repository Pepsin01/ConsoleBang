#include "GameUIOutput.hpp"
#include <iostream>
using namespace std;

GameUIOutput::GameUIOutput() :
	beforeStartScreen(
		string("\nWelcome to ConsoleBang!\n\n") +
		"1. Set the resolution of this window so that the \"Xs\" fill it exactly.\n\n" +
		"2. Press Enter and enjoy the game.\n\n"),
	rulesStartScreen("Game Rules:\n\n"),
	xLine(string(150, 'X') + '\n')
{}

void GameUIOutput::startGameScreen()
{
	cout << wrapWithXs(beforeStartScreen);
}

void GameUIOutput::gameRulesScreen()
{
	cout << wrapWithXs(rulesStartScreen);
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
	while (lineCount + i < 50)
	{
		wrappedText += xLine;
		i++;
	}
	wrappedText += text;
	return wrappedText;
}
