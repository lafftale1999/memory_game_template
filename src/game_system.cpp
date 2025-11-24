#include "../include/game_system.hpp"
#include "avr/wdt.h"
#include "../include/usart.hpp"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void game_system::error_state() {
    gui.error_animation();

    wdt_enable(WDTO_15MS);
    while(1);
}

void game_system::show_high_score() {
    if (current_highscore <= 0) {
        gui.error_animation();
    } else {
        gui.bit_led_animation(current_highscore);
        millis_wait_ms(2000);
    }
}

void game_system::reset_game() {
    gui.reset_leds();
    game.reset_game();
}

void game_system::game_won() {
    gui.win_animation();
    if (current_highscore < game.get_current_level()) {
        current_highscore = game.get_current_level();
    }
}

void game_system::game_lost() {
    gui.loose_animation();
    if (current_highscore < game.get_current_level()) {
        current_highscore = game.get_current_level();
    }
}

void game_system::show_sequence() {
    uint8_t i = 0;
    char buf[10];
    while((i = game.read_single_sequence()) != END_OF_SEQUENCE) {
        gui.blink_sequence(i, 500);
    }
}

void game_system::new_round() {
    game.generate_game_round();

    show_sequence();
}

void game_system::play_game() {
    game.reset_game();
    gui.start_game_animation();

    uint8_t user_input = 0;
    game_state state = game.get_state();

    new_round();
    char buf[20];
    while(state != PLAYER_LOST) {
        input_source.flush();
        user_input = input_source.wait_for_input_ms(5000);
        
        if (user_input == INPUT_TIMEOUT) state = PLAYER_LOST;
        else {
            gui.light_single_led(user_input);
            state = game.check_entry(user_input);
        }
        
        switch(state) {
            case GAME_IS_RUNNING:
                continue;
            
            case WRONG_ENTRY:
                gui.wrong_entry_animation();
                show_sequence();
                continue;
                
            case ROUND_CLEARED:
                gui.win_animation();
                new_round();
                continue;

            case PLAYER_LOST:
                game_lost();
                break;
            
            case PLAYER_WON:
                game_won();
                break;
        }

        break;
    }
}

game_system::game_system(led_handle* leds, uint8_t leds_size, button_handle* buttons, uint8_t buttons_size) 
: gui(leds, leds_size), input_source(buttons, buttons_size), game(leds_size), current_highscore(0)
{
    if (leds == nullptr || buttons == nullptr) {
        error_state();
    }
}

void game_system::run_game() {
    // USART_Init(MYUBRR);

    while(1) {
        gui.start_up_animation();
        gui.menu_choice_animation(2);
        
        uint8_t user_input = input_source.wait_for_input();
        switch(user_input) {
            case 0:
                play_game();
                break;

            case 1:
                show_high_score();
                break;

            default:
                gui.error_animation();
                break;
        }
    }
}