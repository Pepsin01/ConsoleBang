#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "../CoreModul/Card.hpp"
#include "GameUIOutput.hpp"
#include "GameUIInput.hpp"

constexpr int CARD_WIDTH = 30; // width of the card in characters

/*
* @brief Class that handles the output for the card UI
*/
class CardUIOutput
{
private:
	static std::vector<std::string> divideIntoLines(const std::string& text, int lineLength);
public:
	/*
	* @brief Renders the card visual representation for console output.
	* @param card Card to render
	* @return String with the card visual representation
	*/
	static std::string render(Card& card);
	/*
	* @brief Slices the card text into lines of the global card width.
	* @param card Card text to slice
	* @return Vector of strings with the sliced card text
	*/
	static std::string sliceCard(const std::string& card);
	/*
	* @brief Shows message that the card cannot be played with the given reason.
	* @param reason Reason why the card cannot be played
	*/
	static void cannotBePlayed(const std::string& reason);
};

