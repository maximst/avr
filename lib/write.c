/* Library for writing ports data */
#include <util/delay.h>
#include "write.h"


void serial_write(volatile uint8_t* port, const int pin, char data, const int sync_pin) {
    /* This function write serial data to defined port */
    int i;
    char mask = (1 << pin);
    char sync_mask = (1 << sync_pin);

    *port &= ~sync_mask; // Set sync pin to "0"

    for (i = 8; i--; i >= 0) {
        if (i - pin >= 0) {
            *port &= ~mask | mask & data >> i - pin;
        }
        else {
            *port &= ~mask | mask & data << pin - i;
        }

        // If sync_pin is set then him toggled
        if (0 <= sync_pin <= 7) {
            *port ^= sync_mask;
            _delay_ms(1);
            *port ^= sync_mask;
            _delay_ms(1);
        }
    }
}
