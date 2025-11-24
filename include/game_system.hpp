#ifndef GAME_SYSTEM_HPP_
#define GAME_SYSTEM_HPP_

#include "game_gui.hpp"
#include "game_input.hpp"
#include "game_logic.hpp"
#include "millis.h"
#include "random_seed.hpp"

class game_system {
private:
    game_gui gui;
    game_input input_source;
    game_logic game;

    uint8_t current_highscore;
    
    void show_sequence();
    void error_state();
    void show_high_score();
    void reset_game();
    void game_won();
    void game_lost();
    void play_game();
    void new_round();

public:
    game_system() = default;

    /* 
    Creates the logic and the overall functionality for our game.

    @param **leds pointer to an array of leds
    @param leds_size the size of the led array
    @param **buttons pointer to an array of buttons
    @param buttons_size the size of the button array
    */
    game_system(led_handle* leds, uint8_t leds_size, button_handle* buttons, uint8_t buttons_size);

    void run_game();
};

#endif