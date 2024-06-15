// ConsoleBang!.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "GameUI/GameUIOutput.hpp"
#include "GameUI/GameUIInput.hpp"
#include "CoreModul/GameState.hpp"

int main()
{
	std::cout <<
		"  /$$$$$$                                          /$$                 /$$$$$$$                                /$$\n"
		" /$$__  $$                                        | $$                | $$__  $$                              | $$\n"
		"| $$  \\__/  /$$$$$$  /$$$$$$$   /$$$$$$$  /$$$$$$ | $$  /$$$$$$       | $$  \\ $$  /$$$$$$  /$$$$$$$   /$$$$$$ | $$\n"
		"| $$       /$$__  $$| $$__  $$ /$$_____/ /$$__  $$| $$ /$$__  $$      | $$$$$$$  |____  $$| $$__  $$ /$$__  $$| $$\n"
		"| $$      | $$  \\ $$| $$  \\ $$|  $$$$$$ | $$  \\ $$| $$| $$$$$$$$      | $$__  $$  /$$$$$$$| $$  \\ $$| $$  \\ $$|__/\n"
		"| $$    $$| $$  | $$| $$  | $$ \\____  $$| $$  | $$| $$| $$_____/      | $$  \\ $$ /$$__  $$| $$  | $$| $$  | $$    \n"
		"|  $$$$$$/|  $$$$$$/| $$  | $$ /$$$$$$$/|  $$$$$$/| $$|  $$$$$$$      | $$$$$$$/|  $$$$$$$| $$  | $$|  $$$$$$$ /$$\n"
		" \\______/  \\______/ |__/  |__/|_______/  \\______/ |__/ \\_______/      |_______/  \\_______/|__/  |__/ \\____  $$|__/\n"
		"                                                                                                     /$$  \\ $$     \n"
		"                                                                                                    |  $$$$$$/     \n"
		"                                                                                                     \\______/      \n";

	GameUIOutput gameUI;
	GameUIInput gameInput;
	GameStateControllor& gameState = GameStateControllor::getInstance(gameUI, gameInput, gameInput.getPlayerCount());

	gameState.startGame();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
