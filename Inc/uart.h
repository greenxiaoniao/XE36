#ifndef __UART_H
#define	__UART_H

//#include "stm32h7xx_hal_uart.h"

#define UART2_BaudRate 115200;
#define UART3_BaudRate 115200;
#define UART4_BaudRate 115200;
#define UART5_BaudRate 9600;
#define UART6_BaudRate 115200;
#define UART7_BaudRate 115200;
#define UART8_BaudRate 115200;



void MX_USART2_UART_Init(void);
void MX_USART3_UART_Init(void);
void MX_USART4_UART_Init(void);
void MX_USART5_UART_Init(void);
void MX_USART6_UART_Init(void);
void MX_USART7_UART_Init(void);
void MX_USART8_UART_Init(void);
void Uart_Init(void);
#endif
