#pragma once
#include <string>

class GameUIOutput
{
public:
	void startGameScreen();
	void gameRulesScreen();
	GameUIOutput();
private:
	std::string wrapWithXs(const std::string& text);

	const std::string beforeStartScreen;
	const std::string rulesStartScreen;
	const std::string xLine;
};