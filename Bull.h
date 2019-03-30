#include <string>

#ifndef __BULL_H__
#define __BULL_H__

using FString = std::string;

// Full class of the game.
class Bull {
    public:
        Bull();
        bool is_game_won(void) const;
        int get_current_try(void) const;
        int get_max_tries(void) const;
        int get_word_length(void) const;
        void intro(void) const;
        void reset(void);
        void play_game(void);
        bool play_again(void);
        FString generate_word(int input);
        FString get_guess(void);
        Bull_Cow_Count eval_guess(FString);
    private:
        bool game_state_won;
        int current_try;
        int max_tries;
        const int WORD_LENGTH = 5;
        FString word;
};

struct Bull_Cow_Count {
    int Bulls = 0;
    int Cows = 0;
};
#endif