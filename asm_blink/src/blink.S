.global main
main:
	call led_init
	call blink

led_init:
	sbi 0x4,7
	sbi 0x5,7
	ret

led_on:
	sbi 0x5,7
	ret

led_off:
	cbi 0x5,7
	ret

wait:
	ldi r18, 40
wait_outer:
	ldi r17, 0
wait_mid:
	ldi r16, 0
wait_inner:
	dec r16
	brne wait_inner
	dec r17
	brne wait_mid
	dec r18
	brne wait_outer
	nop
	ret

blink:
	call led_on
	call wait
	call led_off
	call wait
	rjmp blink