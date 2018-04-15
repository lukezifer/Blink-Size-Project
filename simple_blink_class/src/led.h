#ifndef __LED_H__
#define __LED_H__ 

#include "register.h"

class Led
{
public:
    Led();

    void m_led_toggle();
};
#endif //__LED_H__