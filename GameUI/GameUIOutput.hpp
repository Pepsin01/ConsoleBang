#pragma once
#include <string>

constexpr int SCREEN_WIDTH = 150;
constexpr int SCREEN_HEIGHT = 50;

class GameUIOutput
{
public:
	void startGameScreen();
	void gameRulesScreen();
	void nextPlayerWarningScreen();
	void renderScreen(const std::string& text);
	GameUIOutput();
private:
	std::string wrapWithXs(const std::string& text);

	const std::string beforeStartMessage;
	const std::string rulesMessage;
	const std::string nextPlayerWarningMessage;
	const std::string xLine;
};