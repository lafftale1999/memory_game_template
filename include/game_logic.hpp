#ifndef GAME_LOGIC_HPP_
#define GAME_LOGIC_HPP_

#include <stdint.h>
#include <stdio.h>

#define GAME_LOGIC_START_LIFES 3
#define GAME_LOGIC_MAX_LEVEL 20
#define GAME_LOGIC_PROGRESSION_INDEX 2
#define GAME_LOGIC_MAX_SEQUENCES GAME_LOGIC_MAX_LEVEL * GAME_LOGIC_PROGRESSION_INDEX

enum game_state {
    PLAYER_LOST,
    PLAYER_WON,
    ROUND_CLEARED,
    GAME_IS_RUNNING,
    WRONG_ENTRY
};

enum end_of_sequence_message {
    END_OF_SEQUENCE = 100
};

class game_logic {
private:
    uint8_t sequence[GAME_LOGIC_MAX_SEQUENCES];
    uint8_t sequence_size;
    uint8_t current_entry_pos;
    uint8_t max_range;
    uint8_t level;
    uint8_t max_level;
    uint8_t lives;
    game_state state;

    void add_level_sequence();
    void check_game_condition();
    void reset_round();
public:

    game_logic() = default;

    /*  
    Creates the logic for our game.

    @param max_range defines the highest number of options that can be generated
    @param lives defines how many lives the user has.
    */
    game_logic(uint8_t max_range, uint8_t lives = GAME_LOGIC_START_LIFES);
    
    void generate_game_round();
    game_state check_entry(uint8_t entry);
    void reset_game();
    game_state get_state();
    void set_state(game_state state);
    uint8_t read_single_sequence();
    uint8_t get_current_level();
};

#endif