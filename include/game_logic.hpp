#ifndef GAME_LOGIC_HPP_
#define GAME_LOGIC_HPP_

#include <stdint.h>
#include <stdio.h>

#define GAME_LOGIC_START_LIFES 3

enum game_state {
    PLAYER_LOST,
    PLAYER_WON,
    GAME_IS_RUNNING
};

class game_logic {
private:
    uint8_t sequence[40];
    uint8_t max_range;
    uint8_t level;
    uint8_t max_level;
    uint8_t lives;
    game_state state;

    void add_level_sequence();
    void check_game_condition();
public:
    /*  
    Creates the logic for our game.

    @param max_range defines the highest number of options that can be generated
    @param lives defines how many lives the user has.
    */
    game_logic(uint8_t max_range, uint8_t lives = GAME_LOGIC_START_LIFES);
    
    game_state game_round();

};

#endif