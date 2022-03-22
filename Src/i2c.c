#include "common.h"
#include "i2c.h"


I2C_HandleTypeDef hi2c1;
/**
  * @brief I2C3 Initialization Function
  * @param None
  * @retval None
  */
void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C3_Init 0 */

  /* USER CODE END I2C3_Init 0 */

  /* USER CODE BEGIN I2C3_Init 1 */

  /* USER CODE END I2C3_Init 1 */
	

  hi2c1.Instance = I2C1;
  //hi2c1.Init.ClockSpeed = 100000;
  //hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
	hi2c1.Init.Timing = 0x10810915;			/* This example use TIMING to 0x0020098E to reach 400Khz speed (Rise time = 50ns, Fall time = 10ns) */
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C3_Init 2 */

  /* USER CODE END I2C3_Init 2 */

}
