#pragma once
#include <string>

/*
* @brief Class that handles the output for the game UI
*/
class GameUIOutput
{
public:
	void startGameScreen();
	void gameRulesScreen();
	void endGameScreen();
	void nextPlayerWarningScreen();
	/*
	* @brief Renders the screen with the given text and the rest of the screen fills with Xs.
	* @param text Text to render
	*/
	static void renderScreen(const std::string& text);
	GameUIOutput();

	static constexpr int SCREEN_WIDTH = 150; // width of the screen in characters
	static constexpr int SCREEN_HEIGHT = 50; // height of the screen in characters
	static inline std::string xLine = std::string(SCREEN_WIDTH, 'X') + '\n'; // line of Xs that fills the screen width
private:
	static std::string wrapWithXs(const std::string& text); // wraps the text with Xs to fill the screen width

	const std::string beforeStartMessage;
	const std::string rulesMessage;
	const std::string nextPlayerWarningMessage;
	const std::string endGameMessage;
};