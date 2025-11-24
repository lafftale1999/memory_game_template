#ifndef GAME_INPUT_HPP_
#define GAME_INPUT_HPP_

#include "button_driver.hpp"
#include "millis.h"

#include <stdint.h>

enum input {
    INPUT_TIMEOUT = 100
};

class game_input {
private:
    button_handle* buttons;
    uint8_t buttons_size;

public:
    game_input(button_handle* buttons, uint8_t buttons_size);

    uint8_t wait_for_input_ms(int wait_ms);
    uint8_t wait_for_input();

    void flush();
};

#endif