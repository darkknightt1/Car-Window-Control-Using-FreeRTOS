#ifndef DIO_H_
#define DIO_H_

#include <stdint.h>

#define PIN_OUTPUT 0
#define PIN_INPUT 1

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4
#define PORTF 5


#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7


#define LOGIC_LOW 0
#define LOGIC_HIGH 1

void DIO_init(uint8_t port_num);
void DIO_writePin(uint8_t port_num, uint8_t pin_num, uint8_t value);
uint8_t DIO_readPin(uint8_t port_num, uint8_t pin_num);
void DIO_writePort(uint8_t port_num, uint32_t value);
void GPIO_setupPinDirection(uint8_t port_num, uint8_t pin_num, uint8_t direction);


#endif
