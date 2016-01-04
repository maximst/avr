#ifndef WRITE_H
#define WRITE_H
#define set_h(port, pin) (port |= (1 << pin))
#define set_l(port, pin) (port &= ~(1 << pin))
#define set_h_pins(port, mask) (port |= mask)
#define set_l_pins(port, mask) (port &= ~mask)
#define inverse_pin(port, pin) (port ^= 1 << pin)
#define inverse_pins(port, mask) (port ^= mask)

void serial_write(volatile uint8_t* port, const int pin, char data, const int sync_pin);

#endif
