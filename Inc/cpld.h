#ifndef __CPLD_H
#define	__CPLD_H

#define M4A5_A13_Pin 				GPIO_PIN_8
#define M4A5_A13_GPIO_Port 			GPIOC
#define M4A5_A14_Pin 				GPIO_PIN_9
#define M4A5_A14_GPIO_Port 			GPIOC
#define M4A5_A15_Pin 				GPIO_PIN_8
#define M4A5_A15_GPIO_Port 			GPIOA
#define M4A5_A16_Pin 				GPIO_PIN_10
#define M4A5_A16_GPIO_Port 			GPIOA

#define M4A5_DATA0_Pin 				GPIO_PIN_8
#define M4A5_DATA0_GPIO_Port 		GPIOD
#define M4A5_DATA1_Pin 				GPIO_PIN_9
#define M4A5_DATA1_GPIO_Port 		GPIOD
#define M4A5_DATA2_Pin 				GPIO_PIN_10
#define M4A5_DATA2_GPIO_Port 		GPIOD
#define M4A5_DATA3_Pin 				GPIO_PIN_11
#define M4A5_DATA3_GPIO_Port 		GPIOD
#define M4A5_DATA4_Pin 				GPIO_PIN_12
#define M4A5_DATA4_GPIO_Port 		GPIOD
#define M4A5_DATA5_Pin 				GPIO_PIN_13
#define M4A5_DATA5_GPIO_Port 		GPIOD
#define M4A5_DATA6_Pin 				GPIO_PIN_14
#define M4A5_DATA6_GPIO_Port 		GPIOD
#define M4A5_DATA7_Pin 				GPIO_PIN_15
#define M4A5_DATA7_GPIO_Port 		GPIOD

#define M4A5_NVIC_Pin  				GPIO_PIN_3
#define M4A5_NVIC_GPIO_Port 		GPIOB
#define M4A5_NVIC_EXTI_IRQn 		EXTI3_IRQn

//#define NPT_64      64
#define CpldCnt     130
void MX_Cpld_Init(void);
#endif
