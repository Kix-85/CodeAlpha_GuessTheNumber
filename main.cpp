#include <iostream>
#include <cstdlib> // For srand and rand
using namespace std;

// Function to display a welcome message
void Welcome()
{
    cout << "Guess The Number\n";
    cout << "-----Welcome-----\n\n";
}

// Function to choose the game difficulty level
int Level()
{
    cout << "Choose Game Difficulty:\n1 - Easy\n2 - Normal\n3 - Hard\n";
    while (1) {
        int LevelNumber;
        cin >> LevelNumber;
        switch (LevelNumber) {
            case 1:
                return 10; // Return the maximum range for easy level
            case 2:
                return 100; // Return the maximum range for normal level
            case 3:
                return 1000; // Return the maximum range for hard level
            default:
                cout << "Enter a valid number:\n"; // Prompt for valid input
                break;
        }
    }
}

// Function to generate a random number within the specified level
int Random_Number(int level)
{
    srand((unsigned)time(nullptr)); // Seed the random number generator
    int RandomNumber = rand() % level; // Generate a random number within the specified range
    return RandomNumber;
}

// Function to play the guessing game
void BeginTheGame(int RandomNumber)
{
    bool win = false;
    cout << "Time to play detective! What's your estimate?\n";
    while (!win) {
        int Number;
        cin >> Number;
        if (Number == RandomNumber) {
            cout << "Great job! You've cracked the code. Thanks for playing!\n";
            win = true;
        } else if (Number < RandomNumber) {
            cout << "You're getting warmer! Go up a notch.\n";
            cout << "Give a guess:\n";
        } else {
            cout << "Cool it down! The answer is lower.\n";
            cout << "Give a guess:\n";
        }
    }
}

// Function to handle playing the game again
void UpForAChallenge()
{
    int level = Level(); // Get the chosen difficulty level
    int RandomNumber = Random_Number(level); // Generate a random number
    BeginTheGame(RandomNumber); // Play the guessing game
    cout << "Game over! Up for another challenge? (Y/N)\n";
    char Again;
    cin >> Again;
    if (Again == 'Y' || Again == 'y') {
        return UpForAChallenge(); // Play again if user chooses 'Y'
    } else if (Again == 'N' || Again == 'n') {
        cout << "Thanks for participating!";
    } else {
        bool WhatAreYouDoing = false;
        while (!WhatAreYouDoing) {
            cout << "Enter (Y/N)\n";
            cin >> Again;
            if (Again == 'Y' || Again == 'y') {
                return UpForAChallenge(); // Play again if user chooses 'Y'
            } else if (Again == 'N' || Again == 'n') {
                cout << "Thanks for participating!";
                WhatAreYouDoing = true;
            }
        }
    }
}

int main() {
    Welcome(); // Display the welcome message
    UpForAChallenge(); // Start the game
}
