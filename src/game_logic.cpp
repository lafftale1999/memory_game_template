#include "../include/game_logic.hpp"

#include <stdlib.h>

void game_logic::add_level_sequence() {
    for (int i = 0; i < GAME_LOGIC_PROGRESSION_INDEX; i++) {
        uint8_t rnd = rand() % max_range;
        sequence[sequence_size++] = rnd;
    }
    level++;
}

void game_logic::check_game_condition() {
    if (level == max_level) state = PLAYER_WON;
    else if (state != PLAYER_LOST && state != WRONG_ENTRY) state = GAME_IS_RUNNING;
}

void game_logic::reset_round() {
    current_entry_pos = 0;
}

game_logic::game_logic(uint8_t max_range, uint8_t lives)
: sequence(), sequence_size(0), current_entry_pos(0), max_range(max_range), level(0), max_level(GAME_LOGIC_MAX_LEVEL), lives(lives), state(GAME_IS_RUNNING)
{}

void game_logic::generate_game_round() {
    check_game_condition();
    if (state == GAME_IS_RUNNING) {
        add_level_sequence();
        reset_round();
    }
}

game_state game_logic::check_entry(uint8_t entry) {
    if (lives <= 0) state = PLAYER_LOST;

    // Correct entry
    if (entry == sequence[current_entry_pos++]) {
        // Check if the player has reached the current level's requirement
        if (current_entry_pos == sequence_size) state = ROUND_CLEARED;
        // Check if the player has finished the game
        else if (current_entry_pos == GAME_LOGIC_MAX_SEQUENCES) state = PLAYER_WON;
        else state = GAME_IS_RUNNING;
    } else if (--lives == 0) {
        state = PLAYER_LOST;
    } else {
        reset_round();
        state = WRONG_ENTRY;
    }

    return state;
}

/* 
uint8_t sequence[GAME_LOGIC_MAX_SEQUENCES];
uint8_t sequence_size;
uint8_t current_entry_pos;
uint8_t max_range;
uint8_t level;
uint8_t max_level;
uint8_t lives;
game_state state;

*/
void game_logic::reset_game() {
    sequence_size = 0;
    current_entry_pos = 0;
    level = 0;
    lives = GAME_LOGIC_START_LIFES;
    state = GAME_IS_RUNNING;
}

game_state game_logic::get_state() {
    return state;
}

void game_logic::set_state(game_state state) {
    this->state = state;
}

uint8_t game_logic::read_single_sequence() {
    if (current_entry_pos == sequence_size) {
        current_entry_pos = 0;
        return END_OF_SEQUENCE;
    }
    
    return sequence[current_entry_pos++];
}

uint8_t game_logic::get_current_level() {
    return level;
}