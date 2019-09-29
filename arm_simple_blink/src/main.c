#include <stdint.h>

#define ID_PIOB 12
#define LED_PIN 27

#define PMC_PCER0 *(volatile uint32_t *)0x400E0610

#define PIOB_PER  *(volatile uint32_t *)0x400E1000
#define PIOB_OER  *(volatile uint32_t *)0x400E1010
#define PIOB_OWER *(volatile uint32_t *)0x400E10A0
#define PIOB_SODR *(volatile uint32_t *)0x400E1030
#define PIOB_CODR *(volatile uint32_t *)0x400E1034

void init(void)
{
	PMC_PCER0 |= 1 << ID_PIOB;
	PIOB_PER  |= 1 << LED_PIN;
	PIOB_OER  |= 1 << LED_PIN;
	PIOB_OWER |= 1 << LED_PIN;
}

void wait()
{
	volatile uint32_t i = 0;
	for(i = 0; i < 150000; i++) {
	}
}

int main()
{
	init();
	while(1) {
		PIOB_SODR |= 1 << LED_PIN;
		wait();
		PIOB_CODR |= 1 << LED_PIN;
		wait();
	}
}
