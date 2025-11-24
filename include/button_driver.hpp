#ifndef MEMORY_BUTTON_DRIVER_HPP_
#define MEMORY_BUTTON_DRIVER_HPP_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "avr/io.h"

#define DEBOUNCE_MS 200

class button_handle {
private:
    volatile uint8_t* ddr;
    volatile uint8_t* port;
    volatile uint8_t* pin_reg;
    uint8_t pin_mask;
    bool pressed;
    unsigned long last_pressed;

    // static registration for ISR
    static constexpr uint8_t MAX_BUTTONS = 8;
    static button_handle* instances[MAX_BUTTONS];
    static uint8_t instance_count;

    bool get_state();
    void debounced_button_click();
    void enable_interrupt();
    void handle_interrupt();

public:
    /*
    Sets up the pin properly to handle a button.

    @param *ddr address (&) to the Data Direction Register for the correct port
    @param *port address (&) to the Port Register for the correct port
    @param *pin_reg address (&) to the Pin Register for the correct port
    @param pin correct pin position in the port register.
    */
    button_handle(volatile uint8_t* ddr, volatile uint8_t* port, volatile uint8_t* pin_reg, uint8_t pin);

    /* 
    Checks the current state of the button.

    @return true if it has been pressed, false if it hasn't.
    */
    bool is_pressed();

    void flush();
    
    /* 
    Helper function for dispatching ISR for our buttons.
    */
    static void dispatch_isr();
    ~button_handle();
};

#endif