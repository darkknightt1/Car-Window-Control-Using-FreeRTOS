#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include <stdint.h>

void INT_PORTF_INIT(uint8_t pin,uint8_t priority);
void INT_PORTB_INIT(uint8_t pin,uint8_t priority);
void INT_PORTE_INIT(uint8_t pin,uint8_t priority);
void INT_PORTD_INIT(uint8_t pin,uint8_t priority);
void INT_PORTA_INIT(uint8_t pin,uint8_t priority);
#endif