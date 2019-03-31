#include "Bull.h"
#include <iostream>

using FText = std::string;

// constructor
Bull::Bull(void) {
    reset();
}

void Bull::reset(void) {
    constexpr int MAX_TRIES = 10;
    max_tries = MAX_TRIES;
    current_try = 1;
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
    word = generate_word(0);

    FText guess;
    while (game_state_won == false) {
        guess = get_guess();
        // first the struct and then the initialized form.
        FBullCowCount BullCowCount = eval_guess(guess);
        std::cout << "Bulls: " << BullCowCount.Bulls;
        std::cout << ". Cows: " << BullCowCount.Cows << std::endl;
    }

    game_state_won = play_again();
    return;
};

FText Bull::generate_word(int input) {
    switch (input) {
        case 0: return "Salty";
        case 1: return "Sweet";
        case 2: return "Swift";
    };
};

FText Bull::get_guess(void) {
    FText guess;
    std::cout << "Try " << current_try << ". Enter your guess: ";
    std::getline (std::cin, guess);
    return guess;
};

FBullCowCount Bull::eval_guess(FString guess) {
    current_try++;

    // setup the return variable from the struct
    FBullCowCount BullCowCount;
    int word_length = word.length();
    for (int i = 0; i < word_length; i++) {
        for (int j = 0; j < word_length; j++) {
            if (guess[j] == word[i]){
                if (i == j) {
                    BullCowCount.Bulls++;
                }
                else {
                    BullCowCount.Cows++;
                }
            }
        }
    }

    if (BullCowCount.Bulls == word_length) {
        game_state_won = true;
        std::cout << "You won! You needed " << current_try;
        std::cout << " tries to complete the word: " << word << ". \n";
    }
    else {
        game_state_won = false;
    }

    return BullCowCount;
};

bool Bull::play_again(void) {
    FText input;
    std::cout << "Thanks for Playing! Do you want to play again? \n";
    std::cout << "Y or N? Enter: ";
    std::getline(std::cin, input);
    if (input[0] == 'Y') {
        reset();
    }
    else if (input[0] == 'N') {}
    else {
        std::cout << "Please enter either Y or N. \n";
        play_again();
    };
    return;
};

EWordStatus check_input(FString) {
    return EWordStatus::Okay;
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