#pragma once
#include <string>

constexpr int SCREEN_WIDTH = 150;
constexpr int SCREEN_HEIGHT = 50;
const std::string xLine = std::string(SCREEN_WIDTH, 'X') + '\n'; // line of Xs that fills the screen width

class GameUIOutput
{
public:
	void startGameScreen();
	void gameRulesScreen();
	void endGameScreen();
	void nextPlayerWarningScreen();
	static void renderScreen(const std::string& text);
	GameUIOutput();
private:
	static std::string wrapWithXs(const std::string& text);

	const std::string beforeStartMessage;
	const std::string rulesMessage;
	const std::string nextPlayerWarningMessage;
	const std::string endGameMessage;
};