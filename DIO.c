
#include "DIO.h"
#include "bitwise_operation.h"
#include "tm4c123gh6pm.h"
/*
* Fucntion name: DIO_init
* Description: Initialize a Digital pin given its port number and 
* pin number and its direction 
*
*/
void DIO_init(uint8_t port_num)
{
  // initiallizing the clock
switch(port_num)
  { 
  case INT_GPIOA:
    SYSCTL_RCGCGPIO_R|=0X01;         //run mode clock enable for PORTA
    while (SYSCTL_PRGPIO_R0==0){};
    GPIO_PORTA_LOCK_R=0x4C4F434B;
    GPIO_PORTA_CR_R=0xFF;
    GPIO_PORTA_DEN_R=0xFF; 
    break;
  case INT_GPIOB:
    SYSCTL_RCGCGPIO_R|=0X02;         //run mode clock enable for PORTB
    while (SYSCTL_PRGPIO_R1==0){};
    GPIO_PORTB_LOCK_R=0x4C4F434B;
    GPIO_PORTB_CR_R=0xFF; 
    GPIO_PORTB_DEN_R=0xFF; 
    break;
  case INT_GPIOC:
    SYSCTL_RCGCGPIO_R|=0X04 ;
      while (SYSCTL_PRGPIO_R2==0){};
    GPIO_PORTC_LOCK_R=0x4C4F434B;
    GPIO_PORTC_CR_R=0xFF; 
    GPIO_PORTC_DEN_R=0xFF; 
    break;
  case INT_GPIOD:
    SYSCTL_RCGCGPIO_R|=0X08;
    while (SYSCTL_PRGPIO_R3==0){};
    GPIO_PORTD_LOCK_R=0x4C4F434B;
    GPIO_PORTD_CR_R=0xFF; 
    GPIO_PORTD_DEN_R=0xFF; 
    break;
  case INT_GPIOE:
    SYSCTL_RCGCGPIO_R|=0X10; 
    while (SYSCTL_PRGPIO_R4==0){};
    GPIO_PORTE_LOCK_R=0x4C4F434B;
    GPIO_PORTE_CR_R=0x3F; 
    GPIO_PORTE_DEN_R=0x3F; 
    break;
  case INT_GPIOF:
    SYSCTL_RCGCGPIO_R|=0X20;         //run mode clock enable for PORTF
    while(SYSCTL_PRGPIO_R5==0){};   //check if the peripheral is ready or not after enabling the clock
    GPIO_PORTF_LOCK_R=0x4C4F434B;  //unlocking the port pins to allow the changes by register DEN, PUR, PDR
    GPIO_PORTF_CR_R=0x1F;         //allow the changes for all the pins
    GPIO_PORTF_DEN_R = 0x1F;     //enable all the pins by digital
    GPIO_PORTF_DIR_R = 0x0E;    //0b01110 //set directions for the pins where pin4:input, pin3:output, pin2: output, pin1: output, pin0:input
    GPIO_PORTF_PUR_R =0x11;
    break;
  }
}




void DIO_writePin(uint8_t port_num, uint8_t pin_num, uint8_t value)
{
 
   switch(port_num)
    {
    case INT_GPIOA:
      if(value == LOGIC_HIGH)
      {
        Set_Bit(GPIO_PORTA_DATA_R,pin_num);
      }
      else
      {
        Clear_Bit(GPIO_PORTA_DATA_R,pin_num);
      }
      break;
    case INT_GPIOB:
      if(value == LOGIC_HIGH)
      {
        Set_Bit(GPIO_PORTB_DATA_R,pin_num);
      }
      else
      {
        Clear_Bit(GPIO_PORTB_DATA_R,pin_num);
      }
      break;
    case INT_GPIOC:
      if(value == LOGIC_HIGH)
      {
        Set_Bit(GPIO_PORTC_DATA_R,pin_num);
      }
      else
      {
        Clear_Bit(GPIO_PORTC_DATA_R,pin_num);
      }
      break;
    case INT_GPIOD:
      if(value == LOGIC_HIGH)
      {
        Set_Bit(GPIO_PORTD_DATA_R,pin_num);
      }
      else
      {
        Clear_Bit(GPIO_PORTD_DATA_R,pin_num);
      }
      break;
    case INT_GPIOE:
      if(value == LOGIC_HIGH)
      {
        Set_Bit(GPIO_PORTA_DATA_R,pin_num);
      }
      else
      {
         Clear_Bit(GPIO_PORTE_DATA_R,pin_num);
      }
      break;
    case INT_GPIOF:
      if(value == LOGIC_HIGH)
      {
        Set_Bit(GPIO_PORTF_DATA_R,pin_num);
      }
      else
      {
        Clear_Bit(GPIO_PORTF_DATA_R,pin_num);
      }
      break;
    } 
}



uint8_t DIO_readPin(uint8_t port_num, uint8_t pin_num)
{
  switch(port_num)
  {
  case INT_GPIOA:
    return Get_Bit(GPIO_PORTA_DATA_R, pin_num);
    break;
  case INT_GPIOB:
    return Get_Bit(GPIO_PORTB_DATA_R, pin_num);
    break;
  case INT_GPIOC:
    return Get_Bit(GPIO_PORTC_DATA_R, pin_num);
    break;
  case INT_GPIOD:
    return Get_Bit(GPIO_PORTD_DATA_R, pin_num);
    break;
  case INT_GPIOE:
    return Get_Bit(GPIO_PORTE_DATA_R, pin_num);
    break;
  case INT_GPIOF:
    return Get_Bit(GPIO_PORTF_DATA_R, pin_num);
    break;
  }
  return 2; /*error in arguments*/
}
void DIO_writePort(uint8_t port_num, uint32_t value)
{
  switch(port_num)
  {
    case INT_GPIOA:
    GPIO_PORTA_DATA_R = value;
    break;

    case INT_GPIOB:
    GPIO_PORTB_DATA_R = value;
    break;

    case INT_GPIOC:
    GPIO_PORTC_DATA_R = value;
    break;

    case PORTD:
    GPIO_PORTD_DATA_R = value;
    break;

    case INT_GPIOE:
    GPIO_PORTE_DATA_R = value;
    break;

    case INT_GPIOF:
    GPIO_PORTF_DATA_R = value;
    break;
  }
}
void GPIO_setupPinDirection(uint8_t port_num, uint8_t pin_num, uint8_t direction)
{
  /*
  * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
  * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
  * In this case the input is not valid port/pin number
  */
  
  
  
  /* Setup the pin direction as required */
  switch(port_num)
  {
  case INT_GPIOA:
    if(direction == PIN_OUTPUT)
    {
      Set_Bit(GPIO_PORTA_DIR_R,pin_num);
    }
    else
    {
      Clear_Bit(GPIO_PORTA_DIR_R,pin_num);
			Set_Bit(GPIO_PORTA_PUR_R,pin_num);
			
    }
    break;
  case INT_GPIOB:
    if(direction == PIN_OUTPUT)
    {
      Set_Bit(GPIO_PORTB_DIR_R,pin_num);
    }
    else
    {
      Clear_Bit(GPIO_PORTB_DIR_R,pin_num);
			Set_Bit(GPIO_PORTB_PUR_R,pin_num);

    }
    break;
  case INT_GPIOC:
    if(direction == PIN_OUTPUT)
    {
      Set_Bit(GPIO_PORTC_DIR_R,pin_num);
    }
    else
    {
      Clear_Bit(GPIO_PORTC_DIR_R,pin_num);
			Set_Bit(GPIO_PORTB_PUR_R,pin_num);

    }
    break;
  case INT_GPIOD:
    if(direction == PIN_OUTPUT)
    {
      Set_Bit(GPIO_PORTD_DIR_R,pin_num);
    }
    else
    {
      Clear_Bit(GPIO_PORTD_DIR_R,pin_num);
			Set_Bit(GPIO_PORTD_PUR_R,pin_num);
    }
    break;
  case INT_GPIOE:
    if(direction == PIN_OUTPUT)
    {
      Set_Bit(GPIO_PORTE_DIR_R,pin_num);
    }
    else
    {
      Clear_Bit(GPIO_PORTE_DIR_R,pin_num);
			Set_Bit(GPIO_PORTE_PUR_R,pin_num);

    }
    break;
  case INT_GPIOF:
    if(direction == PIN_OUTPUT)
    {
      Set_Bit(GPIO_PORTF_DIR_R,pin_num);
    }
    else
    {
      Clear_Bit(GPIO_PORTF_DIR_R,pin_num);
//Set_Bit(GPIO_PORTF_PUR_R,pin_num);

    }
    break;
  }
  
}
