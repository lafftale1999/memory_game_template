#include "../include/game_gui.hpp"

game_gui::game_gui(led_handle* leds, uint8_t leds_size) 
:leds(leds), leds_size(leds_size)
{}

void game_gui::reset_leds() {
    for (uint8_t i = 0; i < leds_size; i++) {
        leds[i].turn_off();
    }
}

void game_gui::turn_on_all_leds() {
    for (uint8_t i = 0; i < leds_size; i++) {
        leds[i].turn_on();
    }
}

void game_gui::light_single_led(uint8_t index) {
    if (index >= leds_size) return;
    reset_leds();
    leds[index].turn_on();
}

void game_gui::blink_sequence(uint8_t led_index, int wait_ms) {
    if (led_index >= leds_size) return;
    leds[led_index].turn_on();
    millis_wait_ms(wait_ms);
    leds[led_index].turn_off();
    millis_wait_ms(wait_ms);
}

void game_gui::start_up_animation() {
    for (uint8_t j = 0; j < 4; j++) {
        for (uint8_t i = 0; i < leds_size; i++) {
            leds[i].turn_on();
            millis_wait_ms(GUI_SEQUENCE_INTERVAL_MS);
        }

        for (uint8_t i = 0; i < leds_size; i++) {
            leds[i].turn_off();
            millis_wait_ms(GUI_SEQUENCE_INTERVAL_MS);
        }
    }
}

void game_gui::menu_choice_animation(uint8_t choices_len) {
    reset_leds();

    for (uint8_t i = 0; i < choices_len; i++) {
        leds[i].turn_on();
    }
}

void game_gui::bit_led_animation(uint8_t byte) {
    reset_leds();

    for (uint8_t i = 0; i < leds_size; i++) {

        uint8_t bit_index = leds_size - 1 - i;   // reverse the bit order

        if (byte & (1 << bit_index)) {
            leds[i].turn_on();
        }
    }
}

void game_gui::start_game_animation() {
    reset_leds();

    for (uint8_t j = 0; j < 3; j++) {
        for (uint8_t i = 0; i < leds_size; i++) {
            leds[i].turn_on();
            millis_wait_ms(GUI_SEQUENCE_INTERVAL_MS);
        }
        reset_leds();
    }

    for (uint8_t i = 0; i < leds_size; i++) {
        leds[i].turn_on();
        millis_wait_ms(1000);
    }

    reset_leds();
}

void game_gui::win_animation() {
    reset_leds();
    
    for (uint8_t j = 0; j < 2; j++) {
        for (uint8_t i = 0; i < leds_size; i++) {
            leds[i].turn_on();
            millis_wait_ms(GUI_SEQUENCE_INTERVAL_MS);
        }

        for (uint8_t i = 0; i < leds_size; i++) {
            leds[i].turn_off();
            millis_wait_ms(GUI_SEQUENCE_INTERVAL_MS);
        }
    }

    for (uint8_t i = 0; i < 3; i++) {
        turn_on_all_leds();
        millis_wait_ms(GUI_BLINK_FAST_INTERVAL_MS);
        reset_leds();
        millis_wait_ms(GUI_BLINK_FAST_INTERVAL_MS);
    }
}

void game_gui::wrong_entry_animation() {
    reset_leds();

    for (uint8_t i = 0; i < 3; i++) {
        turn_on_all_leds();
        millis_wait_ms(GUI_BLINK_FAST_INTERVAL_MS);
        reset_leds();
        millis_wait_ms(GUI_BLINK_FAST_INTERVAL_MS);
    }
}

void game_gui::loose_animation() {
    reset_leds();

    wrong_entry_animation();

    for (uint8_t j = 0; j < 2; j++) {
        for (uint8_t i = leds_size; i > 0; i--) {
            leds[i-1].turn_on();
            millis_wait_ms(GUI_SEQUENCE_INTERVAL_MS);
        }

        for (uint8_t i = leds_size; i > 0; i--) {
            leds[i-1].turn_off();
            millis_wait_ms(GUI_SEQUENCE_INTERVAL_MS);
        }
    }
}

void game_gui::error_animation() {
    for (int i = 0; i < 5; i++) {
        for (uint8_t j = 0; j < leds_size; j++) {
            leds[j].toggle();
            millis_wait_ms(200);
        }
    }
}