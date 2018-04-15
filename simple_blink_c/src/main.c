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
    led_init();

    while(1)
    {
        wait();
        led_toggle();
    }
}
