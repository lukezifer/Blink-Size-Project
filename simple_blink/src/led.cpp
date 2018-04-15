#include "led.h"

void led_init() 
{
    *reinterpret_cast<volatile uint8_t*>(ddrb) |= bval7;
    *reinterpret_cast<volatile uint8_t*>(portb) |= bval7;
}

void led_toggle() 
{
    *reinterpret_cast<volatile uint8_t*>(portb) ^= bval7;
}