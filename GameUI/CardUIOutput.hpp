#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "../CoreModul/Card.hpp"

constexpr int CARD_WIDTH = 30;

class CardUIOutput
{
private:
	std::vector<std::string> divideIntoLines(const std::string& text, int lineLength);
public:
	std::string render(Card& card);
};

