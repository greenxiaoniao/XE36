/**
  ******************************************************************************
  * @file    I2C/I2C_EEPROM_fast_mode_plus/Src/stm32h7xx_it.c 
  * @author  MCD Application Team
  * @brief   Main Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32h7xx_it.h"
#include "common.h"
/** @addtogroup STM32H7xx_HAL_Examples
  * @{
  */

/** @addtogroup I2C_EEPROM_fast_mode_plus
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* I2C handler declared in "main.c" file */
extern I2C_HandleTypeDef I2cHandle;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M7 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
  HAL_IncTick();
}

/******************************************************************************/
/*                 STM32H7xx Peripherals Interrupt Handlers                  */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32h7xx.s).                                               */
/******************************************************************************/
/**
  * @brief  This function handles I2C event interrupt request.
  * @param  None
  * @retval None
  * @Note   This function is redefined in "main.h" and related to I2C data transmission
  */
void I2Cx_EV_IRQHandler(void)
{
  HAL_I2C_EV_IRQHandler(&I2cHandle);
}

/**
  * @brief  This function handles I2C error interrupt request.
  * @param  None
  * @retval None
  * @Note   This function is redefined in "main.h" and related to I2C error
  */
void I2Cx_ER_IRQHandler(void)
{
  HAL_I2C_ER_IRQHandler(&I2cHandle);
}

/**
  * @brief  This function handles DMA interrupt request.
  * @param  None
  * @retval None
  * @Note   This function is redefined in "main.h" and related to DMA handle
  *         used for I2C data transmission
  */
void I2Cx_DMA_RX_IRQHandler(void)
{
  HAL_DMA_IRQHandler(I2cHandle.hdmarx);
}

/**
  * @brief  This function handles DMA interrupt request.
  * @param  None
  * @retval None
  * @Note   This function is redefined in "main.h" and related to DMA handle
  *         used for I2C data reception
  */
void I2Cx_DMA_TX_IRQHandler(void)
{
  HAL_DMA_IRQHandler(I2cHandle.hdmatx);
}
/**
  * @}
  */
void USART2_IRQHandler(void)
{
  /* USER CODE BEGIN USART6_IRQn 0 */
//    uint8_t	uart2RxData;
		if(__HAL_UART_GET_FLAG(&huart2,UART_FLAG_RXNE)!=RESET)
    {
//			uart2RxData=(USART2->RDR & (uint16_t)0x00FF);
			//Uart2_Receive(uart2RxData);
    }
  /* USER CODE END USART6_IRQn 0 */
  HAL_UART_IRQHandler(&huart2);
  /* USER CODE BEGIN USART6_IRQn 1 */

  /* USER CODE END USART6_IRQn 1 */
}
void USART3_IRQHandler(void)
{
  /* USER CODE BEGIN USART6_IRQn 0 */
//    uint8_t	uart3RxData;
		if(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_RXNE)!=RESET)
    {
//			uart3RxData=(USART3->RDR & (uint16_t)0x00FF);
			//Uart3_Receive(uart3RxData);
    }
  /* USER CODE END USART6_IRQn 0 */
  HAL_UART_IRQHandler(&huart3);
  /* USER CODE BEGIN USART6_IRQn 1 */

  /* USER CODE END USART6_IRQn 1 */
}
void UART5_IRQHandler(void)
{
  /* USER CODE BEGIN USART6_IRQn 0 */
 //   uint8_t	uart5RxData;
		if(__HAL_UART_GET_FLAG(&huart5,UART_FLAG_RXNE)!=RESET)
    {
//			uart5RxData=(UART5->RDR & (uint16_t)0x00FF);
			//Uart5_Receive(uart5RxData);
    }
  /* USER CODE END USART6_IRQn 0 */
  HAL_UART_IRQHandler(&huart5);
  /* USER CODE BEGIN USART6_IRQn 1 */

  /* USER CODE END USART6_IRQn 1 */
}
void UART7_IRQHandler(void)
{
  /* USER CODE BEGIN USART6_IRQn 0 */
 //   uint8_t	uart7RxData;
		if(__HAL_UART_GET_FLAG(&huart7,UART_FLAG_RXNE)!=RESET)
    {
//			uart7RxData=(UART7->RDR & (uint16_t)0x00FF);
			//Uart7_Receive(uart7RxData);
    }
  /* USER CODE END USART6_IRQn 0 */
  HAL_UART_IRQHandler(&huart7);
  /* USER CODE BEGIN USART6_IRQn 1 */

  /* USER CODE END USART6_IRQn 1 */
}
void UART8_IRQHandler(void)
{
  /* USER CODE BEGIN USART6_IRQn 0 */
//    uint8_t	uart8RxData;
		if(__HAL_UART_GET_FLAG(&huart8,UART_FLAG_RXNE)!=RESET)
    {
//			uart8RxData=(UART8->RDR & (uint16_t)0x00FF);
			//Uart8_Receive(uart8RxData);
    }
  /* USER CODE END USART6_IRQn 0 */
  HAL_UART_IRQHandler(&huart8);
  /* USER CODE BEGIN USART6_IRQn 1 */

  /* USER CODE END USART6_IRQn 1 */
}
/**
  * @brief This function handles UART4 global interrupt.
  */
void UART4_IRQHandler(void)
{
  /* USER CODE BEGIN UART4_IRQn 0 */
 //  uint8_t	uart4RxData;
	if(__HAL_UART_GET_FLAG(&huart4,UART_FLAG_RXNE)!=RESET)
    {
//			uart4RxData=(UART4->RDR & (uint16_t)0x00FF);
////			UART_Queue_Push1(uart3RxData);		
//		 if((uUSARTCOM.sRxLength < UART_RECV_LEN) && (!(uUSARTCOM.State_flag & BIT1)))
//		 {
//			 uUSARTCOM.sRS232Cmd[uUSARTCOM.sRxLength++] = uart4RxData;
//		 }
//		 uUSARTCOM.UartRecvTimeout = UART_RECV_TIMEROUT_VAL;
    }
  /* USER CODE END UART4_IRQn 0 */
  HAL_UART_IRQHandler(&huart4);
  /* USER CODE BEGIN UART4_IRQn 1 */

  /* USER CODE END UART4_IRQn 1 */
}
/**
  * @brief This function handles USART6 global interrupt.
  */
void USART6_IRQHandler(void)
{
  /* USER CODE BEGIN USART6_IRQn 0 */
//    uint8_t	uart6RxData;
	if(__HAL_UART_GET_FLAG(&huart6,UART_FLAG_RXNE)!=RESET)
    {
//			uart6RxData=(USART6->RDR & (uint16_t)0x00FF);
////			UART_Queue_Push1(uart3RxData);		
//		 if((uUSARTCOM.sRxLength1 < UART_RECV_LEN) && (!(uUSARTCOM.State_flag & BIT3)))
//		 {
//			 uUSARTCOM.sRS232Cmd1[uUSARTCOM.sRxLength1++] = uart6RxData;
//		 }
//		 uUSARTCOM.UartRecvTimeout1 = UART_RECV_TIMEROUT_VAL;
    }
  /* USER CODE END USART6_IRQn 0 */
  HAL_UART_IRQHandler(&huart6);
  /* USER CODE BEGIN USART6_IRQn 1 */

  /* USER CODE END USART6_IRQn 1 */
}
/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
