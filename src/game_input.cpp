#include "../include/game_input.hpp"
#include "../include/millis.h"

game_input::game_input(button_handle* buttons, uint8_t buttons_size)
: buttons(buttons), buttons_size(buttons_size) {}

uint8_t game_input::wait_for_input_ms(int wait_ms) {
    millis_t now = millis_get();
    millis_t start = millis_get();

    while((now - start) < wait_ms) {
        for (uint8_t i = 0; i < buttons_size; i++) {
            if (buttons[i].is_pressed()) return i;
        }
        millis_wait_ms(10);
        now = millis_get();
    }

    return INPUT_TIMEOUT;
}

uint8_t game_input::wait_for_input() {
    while (1) {
        for (uint8_t i = 0; i < buttons_size; i++) {
            if (buttons[i].is_pressed()) return i;
        }
        millis_wait_ms(10);
    }
}

void game_input::flush() {
    for (uint8_t i = 0; i < buttons_size; i++) {
        buttons[i].flush();
    }
}