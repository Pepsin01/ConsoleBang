#pragma once
#include <string>

class GameUIOutput
{
public:
	void startGameScreen();
	void gameRulesScreen();
	void nextPlayerWarningScreen();
	GameUIOutput();
private:
	std::string wrapWithXs(const std::string& text);

	const std::string beforeStartMessage;
	const std::string rulesMessage;
	const std::string nextPlayerWarningMessage;
	const std::string xLine;
};