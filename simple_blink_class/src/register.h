#ifndef __REGISTER_H__
#define __REGISTER_H__

#include <stdint.h>

constexpr uint8_t ddrb = 0x24U;
constexpr uint8_t portb = 0x25U;

constexpr uint8_t bval7 = 1U << 7U;

#endif //__REGISTER_H__