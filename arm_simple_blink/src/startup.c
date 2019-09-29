#include <stdint.h>

extern uint32_t _ROM_START;
extern uint32_t _RAM_START;
extern uint32_t _RAM_END;
extern uint32_t _BSS_START;
extern uint32_t _BSS_END;

#define STACK_TOP 0x20005000

void startup(void);
int main(void);

uint32_t *int_vectors[2] __attribute__((section("vectors"))) =
{
	(uint32_t *) STACK_TOP,
	(uint32_t *) startup
};

void startup()
{
	uint32_t * rom_start_q = &_ROM_START;
	uint32_t * ram_start_q = &_RAM_START;
	uint32_t * ram_end_q = &_RAM_END;
	uint32_t * bss_start_q = &_BSS_START;
	uint32_t * bss_end_q = &_BSS_END;

	while(ram_start_q != ram_end_q) {
		*ram_start_q = *rom_start_q;
		ram_start_q++;
		rom_start_q++;
	}

	while(bss_start_q != bss_end_q) {
		*bss_start_q = 0;
		bss_start_q++;
	}
	main();
}
