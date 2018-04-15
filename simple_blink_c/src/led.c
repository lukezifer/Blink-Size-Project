#include "led.h"

void led_init() 
{
    *(volatile uint8_t*)DDRB  |= BVAL7;
    *(volatile uint8_t*)PORTB |= BVAL7;
}

void led_toggle() 
{
    *(volatile uint8_t*)PORTB ^= BVAL7;
}