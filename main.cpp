#include "Bull.h"
#include <iostream>

using FText = std::string;

// Instantiate a new game from Bull class.
Bull BCGame;

int main(void) {
    BCGame.play_game();
    switch (BCGame.is_game_won()){
        case false: BCGame.play_game();
    }
    return 0;
};