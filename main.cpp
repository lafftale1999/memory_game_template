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
    
    button_handle blue_button(&DDRB, &PORTB, &PINB, PB5);
    button_handle yellow_button(&DDRB, &PORTB, &PINB, PB4);
    button_handle red_button(&DDRB, &PORTB, &PINB, PB3);
    button_handle green_button(&DDRB, &PORTB, &PINB, PB2);

    led_handle blue_led(&DDRB, &PORTB, &PINB, PB0);
    led_handle yellow_led(&DDRD, &PORTD, &PIND, PD7);
    led_handle red_led(&DDRD, &PORTD, &PIND, PD6);
    led_handle green_led(&DDRD, &PORTD, &PIND, PD5);

    while(1) {
        
        if (blue_button.is_pressed()) blue_led.toggle();
        if (yellow_button.is_pressed()) yellow_led.toggle();
        if (red_button.is_pressed()) red_led.toggle();
        if (green_button.is_pressed()) green_led.toggle();

        millis_wait_ms(50);
    }

    return 0;
}