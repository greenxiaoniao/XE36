#ifndef __LCD_H
#define	__LCD_H

#include "stm32h7xx_hal.h"
#include "stdint.h"

#define LCDON 0X06
#define BIAS 0X52          // 0x80  high 4bits
#define RC256 0X30
#define SYSTEN 0X02
#define SYSDIS 0X00
#define LCDOFF 0X04

#define LCD_DATA_Pin GPIO_PIN_11
#define LCD_DATA_GPIO_Port GPIOE
#define LCD_WR_Pin GPIO_PIN_12
#define LCD_WR_GPIO_Port GPIOE
#define LCD_CS_Pin GPIO_PIN_13
#define LCD_CS_GPIO_Port GPIOE
#define LCD_LIGHT_Pin GPIO_PIN_14
#define LCD_LIGHT_GPIO_Port GPIOE

void MX_Lcd_Init(void);
//void dis_menu(uint8_t *p);
void Lcd_Dispay_Process(uint8_t p[]);
#endif /* __Lcd_H */
