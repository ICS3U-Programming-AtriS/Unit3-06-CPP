// Copyright (c) 2025 Atri Sarker All rights reserved.
// .
// Created By: Atri S
// Date: March 27, 2025
// Random Number Guessing Game With Error handling

#include <iostream>
#include <string>
#include <random>

int main() {
    /* 
    # Generate a random number between 0 and 9 [INCLUSIVE] #
    */
    // declare integer to hold random number
    int correctNum;
    // Generate random seed for generator
    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    // Integer Range that contains 0-9 [INCLUSIVE]
    std::uniform_int_distribution<int> idist(0, 9);
    // Generate a random number from the range
    correctNum = idist(rgen);

    // Get the user's guess as a string
    std::string userInput;
    std::cout << "Enter a number (0-9): ";
    // I used getline() since "cin >> userInput" can't handle multiple words
    std::getline(std::cin, userInput);

    try {
        // Convert the user's guess to an integer
        int userNum = std::stoi(userInput);

        // Check if the user's guess is the same as the correct number
        if (userNum == correctNum) {
            // Tell the user that they guessed correctly
            std::cout << "You guessed correctly!\n";
        } else /*If it isn't, tell the user that they guessed wrong*/ {
            // Tell the user that they guessed wrong
            std::cout << "Wrong!";
            // Also tell them the correct answer
            std::cout << " The correct answer was ";
            std::cout << correctNum << ".\n";
        }
    } catch (std::invalid_argument) {
        // Tell the user that their input wasn't an integer
        std::cout << userInput;
        std::cout << " is not an integer.\n";
    }
}
