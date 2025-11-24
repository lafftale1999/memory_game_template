#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/power.h>
#include <util/atomic.h>

#include "include/millis.h"
#include "include/game_system.hpp"
#include "include/random_seed.hpp"

int main(void) {
    sei();
    millis_init();
    setup_seed();

    button_handle buttons[] = {
        button_handle(&DDRB, &PORTB, &PINB, PB5),
        button_handle(&DDRB, &PORTB, &PINB, PB4),
        button_handle(&DDRB, &PORTB, &PINB, PB3),
        button_handle(&DDRB, &PORTB, &PINB, PB2)
    };
    
    led_handle leds[] = {
        led_handle(&DDRB, &PORTB, &PINB, PB0),
        led_handle(&DDRD, &PORTD, &PIND, PD7),
        led_handle(&DDRD, &PORTD, &PIND, PD6),
        led_handle(&DDRD, &PORTD, &PIND, PD5)
    };
    
    game_system game(leds, static_cast<uint8_t>(sizeof(leds) / sizeof(leds[0])), buttons, static_cast<uint8_t>(sizeof(buttons) / sizeof(buttons[0])));
    
    while(1) {
        game.run_game();
        millis_wait_ms(20);
    }

    return 0;
}