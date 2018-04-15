#include "led.h"

Led::Led()
{
    *reinterpret_cast<volatile uint8_t*>(ddrb) |= bval7;
    *reinterpret_cast<volatile uint8_t*>(portb) |= bval7;
}

void Led::m_led_toggle() const
{
    *reinterpret_cast<volatile uint8_t*>(portb) ^= bval7;
}