#include <stdint.h>

#include "led.h"

void wait()
{
    for (volatile uint32_t i = 0; i < 150000; ++i)
    {
        //do nothing, wait
    }
}

int main()
{
    Led led;

    while(1)
    {
        wait();
        led.m_led_toggle();
    }
}
