#include <string>

using FString = std::string;

struct FBullCowCount {
    int Bulls = 0;
    int Cows = 0;
};

enum EWordStatus {
    Okay,
    Not_Isogram,
    No_Input
};

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
        FBullCowCount eval_guess(FString);
        EWordStatus check_input(FString);
    private:
        bool game_state_won;
        int current_try;
        int max_tries;
        const int WORD_LENGTH = 5;
        FString word;
};