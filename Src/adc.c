#include "stm32h7xx_hal.h"
#include "stm32h7xx_hal_adc.h"
#include "adc.h"
#include "common.h"

ADC_HandleTypeDef             AdcHandle;	//ADC∂Àø⁄
ADC_ChannelConfTypeDef        sConfig;		//ADCÕ®µ¿≈‰÷√

void MX_ADC_Init(void)
{
	  /* ### - 1 - Initialize ADC peripheral #################################### */

  AdcHandle.Instance          = ADC1;

  if (HAL_ADC_DeInit(&AdcHandle) != HAL_OK)
  {
    /* ADC de-initialization Error */
    Error_Handler();
  }

  AdcHandle.Init.ClockPrescaler           = ADC_CLOCK_ASYNC_DIV2;          /* Asynchronous clock mode, input ADC clock divided by 2*/
  AdcHandle.Init.Resolution               = ADC_RESOLUTION_16B;            /* 16-bit resolution for converted data */
  AdcHandle.Init.ScanConvMode             = ENABLE;                       /* Sequencer disabled (ADC conversion on only 1 channel: channel set on rank 1) */
  AdcHandle.Init.EOCSelection             = ADC_EOC_SINGLE_CONV;           /* EOC flag picked-up to indicate conversion end */
  AdcHandle.Init.LowPowerAutoWait         = DISABLE;                       /* Auto-delayed conversion feature disabled */
  AdcHandle.Init.ContinuousConvMode       = ENABLE;                        /* Continuous mode enabled (automatic conversion restart after each conversion) */
  AdcHandle.Init.NbrOfConversion          = 1;                             /* Parameter discarded because sequencer is disabled */
  AdcHandle.Init.DiscontinuousConvMode    = DISABLE;                       /* Parameter discarded because sequencer is disabled */
  AdcHandle.Init.NbrOfDiscConversion      = 1;                             /* Parameter discarded because sequencer is disabled */
  AdcHandle.Init.ExternalTrigConv         = ADC_SOFTWARE_START;            /* Software start to trig the 1st conversion manually, without external event */
  AdcHandle.Init.ExternalTrigConvEdge     = ADC_EXTERNALTRIGCONVEDGE_NONE; /* Parameter discarded because software trigger chosen */
  AdcHandle.Init.ConversionDataManagement = ADC_CONVERSIONDATA_DR;         /* DR register used as output (DMA mode disabled) */
  AdcHandle.Init.LeftBitShift             = ADC_LEFTBITSHIFT_NONE;         /* Left shift of final results */
  AdcHandle.Init.Overrun                  = ADC_OVR_DATA_OVERWRITTEN;      /* DR register is overwritten with the last conversion result in case of overrun */
  AdcHandle.Init.OversamplingMode         = DISABLE;                       /* Oversampling disable */

  /* Initialize ADC peripheral according to the passed parameters */
  if (HAL_ADC_Init(&AdcHandle) != HAL_OK)
  {
    Error_Handler();
  }

  /* ### - 2 - Start calibration ############################################ */
  if (HAL_ADCEx_Calibration_Start(&AdcHandle, ADC_CALIB_OFFSET, ADC_SINGLE_ENDED) != HAL_OK)
  {
    Error_Handler();
  }

  /* ### - 3 - Channel configuration ######################################## */
  sConfig.Channel                = ADC_CHANNEL_5;           /* Sampled channel number */
  sConfig.Rank                   = ADC_REGULAR_RANK_1;         /* Rank of sampled channel number ADCx_CHANNEL */
  sConfig.SamplingTime           = ADC_SAMPLETIME_810CYCLES_5; /* Sampling time (number of clock cycles unit) */
  sConfig.SingleDiff             = ADC_SINGLE_ENDED;           /* Single input channel */
  sConfig.OffsetNumber           = ADC_OFFSET_NONE;            /* No offset subtraction */
  sConfig.Offset                 = 0;                          /* Parameter discarded because offset correction is disabled */
  sConfig.OffsetRightShift       = DISABLE;                    /* No Right Offset Shift */
  sConfig.OffsetSignedSaturation = DISABLE;                    /* No Signed Saturation */
  if (HAL_ADC_ConfigChannel(&AdcHandle, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /* ### - 4 - Start conversion ############################################# */
  if (HAL_ADC_Start(&AdcHandle) != HAL_OK)
  {
    Error_Handler();
  }
}
