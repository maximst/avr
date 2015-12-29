/* This program flash alternately LEDs
 * LEDs connected to pins PB0 and PB1
 */

#define F_CPU 1000000L // Set CPU frequency for delay function

#include <avr/io.h>
#include <util/delay.h>
#include "lib/write.h"


void main() {
    // Set 8bit register DDRB,
    // for configure pins PB0 and PB1 as output
    // Port numbers PB[X]
    //   X = 76543210
    DDRB = 0b00000011;
    
    while (1) {
        // PORTB - is 8 bit register
        // which defines the status of the outputs
        PORTB = 0b00000001; // Set pin PB0 to high level and other pins to low
        _delay_ms(200); // Wait 200 ms
        PORTB = 0b00000010; // Set pin PB1 to high level and other pins to low
        _delay_ms(200); // Wait 200 ms
    }
}
