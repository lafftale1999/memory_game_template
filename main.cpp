#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/power.h>
#include <util/atomic.h>

#include "include/millis.h"
#include "include/led_driver.hpp"
#include "include/button_driver.hpp"

int main(void) {
    sei();
    millis_init();
    
    led_handle green(&DDRB, &PORTB, &PINB, PB5);
    button_handle green_button(&DDRB, &PORTB, &PINB, PB4);

    while(1) {
        if (green_button.is_pressed()) {
            green.toggle();
        }
    
        millis_wait_ms(50);
    }

    return 0;
}