#include <iostream>
#include "main.h"
using namespace std;

int main(void) {
    bool game = true;
    bool won = false;
    int i = 0;
    const int number_of_turns = 10;

    while (game==true) {
        intro();
        string targetword = generate_Word();

        while (i < number_of_turns && won == false) {
            string guess = get_Guess();
            won = eval_Guess(guess, target_word);
            i++;
        }

        game = play_Again();
    }

    return 0;
}

void intro(void) {
    const int WORD_LENGTH = 5;
    cout << "Welcome to Bulls & Cows! \n";
    cout << "Guess a " << WORD_LENGTH << " letter word. For each letter that you got right\n";
    cout << "you get a cow. If it's in the right place, you get a bull.\n";
    cout << "Now, enter your first guess: ";
    return;
}

string get_Guess(void) {
    string guess;
    getline (cin, guess);
    cout << "Your guess was: " << guess << endl;
    return guess;
}

bool play_Again(void) {
    string input;
    cout << "Thanks for Playing! Do you want to play again? \n";
    cout << "Y or N? Enter: ";
    getline(cin, input);
    if (input == "Y") {
        return true;
    }
    else if (input == "N") {
        return false;
    }
    else {
        cout << "Please enter either Y or N. \n";
        play_Again();
    }
}

bool eval_Guess(string guess, string target_word){
    if (guess)
}

string generate_Word(void) {
    int = 
}