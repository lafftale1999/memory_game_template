#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/power.h>
#include <util/atomic.h>

#include "include/millis.h"
#include "include/led_driver.hpp"
#include "include/button_driver.hpp"
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
    
    while(1) {
        for (uint8_t i = 0; i < (sizeof(leds) / sizeof(leds[0])); i++) {
            if (buttons[i].is_pressed()) leds[i].toggle();
        }

        millis_wait_ms(20);
    }

    return 0;
}