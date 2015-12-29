/* Library for writing ports data */
#include "write.h"


void serial_write(volatile uint8_t* port, const int pin, char data) {
    /* This function write serial data to defined port */
    int i;
    char mask = 1 << pin;

    for (i = 8; i--; i >= 0) {
        if (i - pin >= 0) {
            *port &= ~mask | mask & data >> i - pin;
        }
        else {
            *port &= ~mask | mask & data << pin - i;
        }
    }
}
