#include "Bull.h"
#include <iostream>

using FText = std::string;

// constructor
Bull::Bull(void) {
    reset();
}

void Bull::reset(void) {
    int MAX_TRIES = 10;
    max_tries = MAX_TRIES;
    current_try = 0;
    game_state_won = false;
    return;
}

void Bull::intro(void) const{
    std::cout << "Welcome to Bulls & Cows! \n";
    std::cout << "Guess a " << Bull::WORD_LENGTH << " letter word. For each letter that you got right\n";
    std::cout << "you get a cow. If it's in the right place, you get a bull.\n";
    std::cout << "Now, enter your first guess: ";
    return;
};

void Bull::play_game(void) {
    intro();
    generate_word(0);

    while (game_state_won == false) {
        get_guess();
    }
};

FText Bull::generate_word(int input) {
    switch (input) {
        case 0: return "Salty";
        case 1: return "Sweet";
        case 2: return "Swift";
    };
};

FText Bull::get_guess(void) {
    int current_try = 1;
    FText guess;
    std::cout << "Try " << current_try << ". Enter your guess: ";
    std::getline (std::cin, guess);
    std::cout << "Your guess was: " << guess << std::endl;
    return guess;
};

Bull_Cow_Count Bull::eval_guess(FString) {
    current_try++;

    return Bull_Cow_Count();
};

bool Bull::play_again(void) {
    FText input;
    std::cout << "Thanks for Playing! Do you want to play again? \n";
    std::cout << "Y or N? Enter: ";
    std::getline(std::cin, input);
    if (input[0] == 'Y') {
        return true;
    }
    else if (input[0] == 'N') {
        return false;
    }
    else {
        std::cout << "Please enter either Y or N. \n";
        Bull::play_again();
    };
};

// getter methods

int Bull::get_word_length(void) const{
    return WORD_LENGTH;
}

int Bull::get_current_try(void) const{
    return current_try;
};

int Bull::get_max_tries(void) const{
    return max_tries;
};

bool Bull::is_game_won(void) const{
    return game_state_won;
};