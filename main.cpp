#include "Bull.h"
#include <iostream>

using FText = std::string;

// Instantiate a new game from Bull class.
Bull BCGame;

int main(void) {
    BCGame.play_game();
    // loop should be inside play game method..
    BCGame.play_again();
    // after play game is finished ask if play again.
    return 0;
};