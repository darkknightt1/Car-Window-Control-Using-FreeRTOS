#ifndef UART_H_
#define UART_H_

#define TX_PORT_ID  PORTE
#define RX_PORT_ID  PORTE
#define TX_PIN_ID  PIN4_ID
#define RX_PIN_ID  PIN5_ID

#include <stdint.h>
typedef enum{
bit5,bit6,bit7,bit8,bit9=7
}UART_BitData;
typedef enum{
	disabled,reserved,enable_even,enable_odd
}UART_Parity;
typedef enum{
	bit_1,bit_2
}UART_StopBit;
typedef enum{
	b48=4800,b96=b48*2,b144=b96*2,b57=57600,b1152=b57*2

}UART_BaudRate;
typedef struct{
 UART_BitData bit_data;
 UART_Parity parity;
 UART_StopBit stop_bit;
 UART_BaudRate baud_rate;
}UART_ConfigType;
void UART_init(void);
char UART_Receive_Byte(void); 
void UART_Send_Byte(unsigned char data);
void UART_Send_String(char *str);
void UART_Receive_String(uint8_t *str);
void Delay(unsigned long counter);

void printChar(char c);
void printString(char *String, void (*PTR_Func)(char));






#endif /* UART_H_ */
