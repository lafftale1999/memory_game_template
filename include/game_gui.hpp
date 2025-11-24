#ifndef GAME_GRAPHICAL_USER_INTERFACE_HPP_
#define GAME_GRAPHICAL_USER_INTERFACE_HPP_

#include "led_driver.hpp"
#include "millis.h"

#include <stdint.h>
#define GUI_BLINK_FAST_INTERVAL_MS  250
#define GUI_BLINK_INTERVAL_MS       500
#define GUI_SEQUENCE_INTERVAL_MS    100


class game_gui {
private:
    led_handle* leds;
    uint8_t leds_size;
    
public:
    game_gui(led_handle* leds, uint8_t leds_size);

    void reset_leds();
    void light_single_led(uint8_t index);
    void turn_on_all_leds();
    void blink_sequence(uint8_t led_index, int wait_ms);
    void start_up_animation();
    void menu_choice_animation(uint8_t choices_len);
    void bit_led_animation(uint8_t byte);
    void start_game_animation();
    void win_animation();
    void wrong_entry_animation();
    void loose_animation();
    void error_animation();
};

#endif