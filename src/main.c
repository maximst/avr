#define F_CPU 22220000L // 22.22 MHz

#include <avr/io.h>
#include <stdio.h>
#include "display.c"


char value[7];
uint32_t counter = 0;


interrupt [EXT_INT0] void ext_int0_isr(void) {
    counter++;
}

interrupt [TIM1_COMPA] void timer1_compa_isr(void) {
    sprintf(&value, "%i", counter);
    counter = 0;
    TCNT1H = 0;
    TCNT1L = 0;
}

void main() {
    DDRB = 0b11111111;
    DDRD = 0b00000100;
    PORTD = 0b00000100;
    
    TCCR1A = 0b00000000;
    TCCR1B = 0b00000101;
    OCR1A = 21699;

    TIMSK = 0b00010000;

    sei();

    while (1) {
        show_value(&PORTB, value);
    }
}
