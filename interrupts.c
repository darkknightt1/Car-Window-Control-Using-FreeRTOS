#include "bitwise_operation.h"
#include "interrupts.h"
#include "tm4c123gh6pm.h"
#include "DIO.h"
//#include "types.h"
#include <stdint.h>

void INT_PORTF_INIT(uint8_t pin,uint8_t priority)
{
  pin=(1<<pin);
  GPIO_PORTF_IS_R &=~    0x1F; //catch on edge 
  GPIO_PORTF_IBE_R  &=~  0x1F;//clear ibe "use rising or falling edge only not both"
  GPIO_PORTF_IEV_R  &=~0x1F;//falling edge
  GPIO_PORTF_ICR_R |=  0x1F;//clear interrupt flag "just in case"
  GPIO_PORTF_IM_R  |=  0x1F;//unmask the pin
  NVIC_PRI7_R      |=  priority << 21; //set pririty
  NVIC_EN0_R       |=1<<30;//enable portf interrupt
	/*pin=(1<<pin);
  GPIO_PORTF_IS_R &=~    0x11; //catch on edge 
  GPIO_PORTF_IBE_R  &=~  0x11;//clear ibe "use rising or falling edge only not both"
  GPIO_PORTF_IEV_R  &=~0x11;//falling edge
  GPIO_PORTF_ICR_R |=  0x11;//clear interrupt flag "just in case"
  GPIO_PORTF_IM_R  |=  0x11;//unmask the pin
  NVIC_PRI7_R      |=  priority << 21; //set pririty
  NVIC_EN0_R       |=1<<30;//enable portf interrupt*/
  
}

void INT_PORTE_INIT(uint8_t pin,uint8_t priority)
{
  pin=(1<<pin);
  GPIO_PORTE_IS_R =(GPIO_PORTE_IS_R  & 0xFFFFFF00) &~ pin; //catch on edge 
  GPIO_PORTE_IBE_R =(GPIO_PORTE_IBE_R  & 0xFFFFFF00) &~ pin;//clear ibe "use rising or falling edge only not both"
  GPIO_PORTE_IEV_R |=pin;//rising edge
  GPIO_PORTE_ICR_R |=pin;//clear interrupt flag "just in case"
  GPIO_PORTE_IM_R  |=pin;//unmask the pin
  NVIC_PRI7_R      |=  priority << 21; //set pririty
  NVIC_EN0_R       |=1<<4;//enable portf interrupt
  
}
void INT_PORTD_INIT(uint8_t pin,uint8_t priority)
{
  pin=(1<<pin);
  GPIO_PORTD_IS_R =(GPIO_PORTD_IS_R  & 0xFFFFFF00) &~ pin; //catch on edge
  GPIO_PORTD_IBE_R =(GPIO_PORTD_IBE_R  & 0xFFFFFF00) &~ pin;//clear ibe "use rising or falling edge only not both"
  GPIO_PORTD_IEV_R |=pin;//rising edge
  GPIO_PORTD_ICR_R |=pin;//clear interrupt flag "just in case"
  GPIO_PORTD_IM_R  |=pin;//unmask the pin
  NVIC_PRI0_R      |=  priority << 29; //set pririty
  NVIC_EN0_R       |=1<<3;//enable portf interrupt

}

void INT_PORTA_INIT(uint8_t pin,uint8_t priority)
{
  pin=(1<<pin);
  GPIO_PORTA_IS_R =(GPIO_PORTE_IS_R  & 0xFFFFFF00) &~ pin; //catch on edge
  GPIO_PORTA_IBE_R =(GPIO_PORTE_IBE_R  & 0xFFFFFF00) &~ pin;//clear ibe "use rising or falling edge only not both"
  GPIO_PORTA_IEV_R |=pin;//rising edge
  GPIO_PORTA_ICR_R |=pin;//clear interrupt flag "just in case"
  GPIO_PORTA_IM_R  |=pin;//unmask the pin
  NVIC_PRI0_R      |=  priority << 5; //set pririty
  NVIC_EN0_R       |=1<<0;//enable portf interrupt

}


