#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "../CoreModul/Card.hpp"
#include "GameUIOutput.hpp"
#include "GameUIInput.hpp"

constexpr int CARD_WIDTH = 30;

class CardUIOutput
{
private:
	static std::vector<std::string> divideIntoLines(const std::string& text, int lineLength);
public:
	static std::string render(Card& card);
	static std::string sliceCard(const std::string& card);
	static void cannotBePlayed(const std::string& reason);
};

