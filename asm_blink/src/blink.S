.equ DDRB, 0x04 ; memory mapped register
.equ PORTB, 0x05 ; memory mapped register
.equ PIN7, 0x07 ; LED Pin number


.section .vectors
__vectors:
	jmp reset

.global main
main:
	call blink

reset:
	sbi DDRB,PIN7 ; set DDRB to output at bit 7
	cbi PORTB,PIN7; set LED off
	call main

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
	sbi PORTB,PIN7 ; turn LED on
	call wait
	cbi PORTB,PIN7 ; turn LED off
	call wait
	rjmp blink
