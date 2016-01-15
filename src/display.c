#include <util/delay.h>

void show_value(volatile uint8_t* port, char value) {
    uint8_t i;

    for (i=0; i<sizeof(value); i++) {
        *port &= 0b10000000 | (i | (value[i] << 3));
        _ms_delay(1);
    }
}