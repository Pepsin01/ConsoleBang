#include "GameUIInput.hpp"
#include <iostream>
#include <limits>

using namespace std;

bool GameUIInput::waitForEnter()
{
    cin.get();
	return true;
}

int GameUIInput::getPlayerCount()
{
    int number;
    while (true) {
        cout << "Enter the number of players: ";
        cin >> number;
        if (cin.fail() || number < 3 || number > 7) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Not a valid number of players, insert number between 3-7 please" << '\n';
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return number;
        }
    }
}
