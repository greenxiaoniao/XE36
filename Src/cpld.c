#include "common.h"
#include "Cpld.h"

void MX_Cpld_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    HAL_GPIO_WritePin(GPIOC, M4A5_A13_Pin|M4A5_A14_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, M4A5_A15_Pin|M4A5_A16_Pin, GPIO_PIN_RESET);
		
    GPIO_InitStruct.Pin = M4A5_A15_Pin|M4A5_A16_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed =GPIO_SPEED_FREQ_VERY_HIGH;// GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
		
    GPIO_InitStruct.Pin = M4A5_A13_Pin|M4A5_A14_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed =GPIO_SPEED_FREQ_VERY_HIGH;// GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
		
    GPIO_InitStruct.Pin = M4A5_DATA0_Pin|M4A5_DATA1_Pin|M4A5_DATA2_Pin|M4A5_DATA3_Pin
                          |M4A5_DATA4_Pin|M4A5_DATA5_Pin|M4A5_DATA6_Pin|M4A5_DATA7_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = M4A5_NVIC_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(M4A5_NVIC_GPIO_Port, &GPIO_InitStruct);
    HAL_NVIC_SetPriority(EXTI3_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(EXTI3_IRQn);
}

uint16_t HAL_GPIOB_ReadValue(void)
{
    uint16_t ReadValue = 0;
    uint16_t PinState = 0;
    PinState=M4A5_DATA0_Pin|M4A5_DATA1_Pin|M4A5_DATA2_Pin|M4A5_DATA3_Pin|M4A5_DATA4_Pin|
             M4A5_DATA5_Pin|M4A5_DATA6_Pin|M4A5_DATA7_Pin;
    /* Check the parameters */
    assert_param(IS_GPIO_PIN(PinState));
    ReadValue=((GPIOD->IDR&PinState) >> 8) & 0xff;
    return ReadValue;
}


/**
  * @brief This function handles EXTI line4 interrupts.
#define M4A5_NVIC_Pin GPIO_PIN_4
#define M4A5_NVIC_GPIO_Port GPIOc
#define M4A5_NVIC_EXTI_IRQn EXTI4_IRQn
  */
void EXTI3_IRQHandler(void)
{
  static uint8_t i=0,count_h;
	uint16_t count_value=0;
	uint32_t stable_data2,count_temp,countb,data_sum;
	double data_temp,data_avg;
	double stable_data1;
	
	/* USER CODE BEGIN EXTI4_IRQn 0 */
	HAL_GPIO_WritePin(GPIOC, M4A5_A13_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, M4A5_A14_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, M4A5_A15_Pin, GPIO_PIN_SET);
	count_value=HAL_GPIOB_ReadValue();
	count_h=count_value;
	count_h &=0x3f;
  stSysParameterApp.count_h1=count_h;
	count_temp=count_h;
  count_h=0x00;

	HAL_GPIO_WritePin(GPIOC, M4A5_A13_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, M4A5_A14_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, M4A5_A15_Pin, GPIO_PIN_SET);
	count_value=HAL_GPIOB_ReadValue();
	stSysParameterApp.count_l=count_value;
		//count_l=0xff;
	countb=stSysParameterApp.count_l;
	countb=countb<<16;
	count_temp<<=24;
	countb |=count_temp;
	if((stSysParameterApp.count_h1*256+stSysParameterApp.count_l)<200)
	{
		stSysParameterApp.wt_low=1;
		stSysParameterApp.wt_over=0;
	}
	else if((stSysParameterApp.count_h1*256+stSysParameterApp.count_l)>16500)
	{
		stSysParameterApp.wt_low=0;
		stSysParameterApp.wt_over=1;
	}
	else
	{
		stSysParameterApp.wt_low=0;
		stSysParameterApp.wt_over=0;
	}
	stSysParameterApp.count_sum = stSysParameterApp.count_sum+stSysParameterApp.count_h1*256+stSysParameterApp.count_l;
	stSysParameterApp.get_wt = stSysParameterApp.get_wt-1;
	if(stSysParameterApp.get_wt==0)
	{
		stSysParameterApp.count_data=stSysParameterApp.count_sum;
		data_temp=stSysParameterApp.count_data*0.01;
		stSysParameterApp.stable_data=data_temp*0.01;
		data_sum=0;
		data_sum=data_temp*24;
		data_sum=data_sum+stSysParameterApp.data_sp1[0]*8;
		data_sum=data_sum+stSysParameterApp.data_sp1[1]*16;
		data_sum=data_sum+stSysParameterApp.data_sp1[2]*6;
		data_sum=data_sum+stSysParameterApp.data_sp1[3]*4;
		data_sum=data_sum+stSysParameterApp.data_sp1[4]*6;

    for(i=4;i>0;i--)
		 {
		 	stSysParameterApp.data_sp1[i]=stSysParameterApp.data_sp1[i-1];
		 }
		 stSysParameterApp.data_sp1[0]=data_temp;
	//	stable_data1=data_sp1[4]*0.01; 
		 //count_data=data_sum/20; 
		stable_data1 =stSysParameterApp.data_sp1[0]*0.002 + 
									stSysParameterApp.data_sp1[1]*0.002 + 
									stSysParameterApp.data_sp1[2]*0.002 + 
									stSysParameterApp.data_sp1[3]*0.002 + 
									stSysParameterApp.data_sp1[4]*0.002;
	//	stable_data1=data_sp1[4]*0.01;
		if(stable_data1>=stSysParameterApp.stable_data)
		{
			stable_data2=stable_data1-stSysParameterApp.stable_data;
			if(stable_data2 < 2)
			{
				if(stSysParameterApp.stable_count < 100) 
					stSysParameterApp.stable_count = stSysParameterApp.stable_count+1;
			}
			else
			{
				if (stable_data2 > 2)
				{
					stSysParameterApp.data_sp1[0]=data_temp;
				  stSysParameterApp.data_sp1[1]=data_temp; 
				  stSysParameterApp.data_sp1[2]=data_temp;
				  stSysParameterApp.data_sp1[3]=data_temp;
				  stSysParameterApp.data_sp1[4]=data_temp;
					
					stSysParameterApp.count_data=stSysParameterApp.count_sum;
					data_temp=stSysParameterApp.count_data*0.01;
					stSysParameterApp.stable_data=data_temp*0.01;
					data_sum=0;
					data_sum=data_temp*24;
					data_sum=data_sum+stSysParameterApp.data_sp1[0]*8;
					data_sum=data_sum+stSysParameterApp.data_sp1[1]*16;
					data_sum=data_sum+stSysParameterApp.data_sp1[2]*6;
					data_sum=data_sum+stSysParameterApp.data_sp1[3]*4;
					data_sum=data_sum+stSysParameterApp.data_sp1[4]*6;					
				}
				stSysParameterApp.stable_count=1;	
			}
		}
		else
		{
			stable_data2=stSysParameterApp.stable_data-stable_data1;
			if(stable_data2<2)
			{
				if(stSysParameterApp.stable_count<100) 
					stSysParameterApp.stable_count=stSysParameterApp.stable_count+1;
			}
			else
			{
				if (stable_data2 > 2)
				{
					stSysParameterApp.data_sp1[0]=data_temp;
				  stSysParameterApp.data_sp1[1]=data_temp; 
				  stSysParameterApp.data_sp1[2]=data_temp;
				  stSysParameterApp.data_sp1[3]=data_temp;
				  stSysParameterApp.data_sp1[4]=data_temp;
					
					stSysParameterApp.count_data=stSysParameterApp.count_sum;
					data_temp=stSysParameterApp.count_data*0.01;
					stSysParameterApp.stable_data=data_temp*0.01;
					data_sum=0;
					data_sum=data_temp*24;
					data_sum=data_sum+stSysParameterApp.data_sp1[0]*8;
					data_sum=data_sum+stSysParameterApp.data_sp1[1]*16;
					data_sum=data_sum+stSysParameterApp.data_sp1[2]*6;
					data_sum=data_sum+stSysParameterApp.data_sp1[3]*4;
					data_sum=data_sum+stSysParameterApp.data_sp1[4]*6;
				}
				stSysParameterApp.stable_count=1;
			}
		}
		if(stSysParameterApp.stable_count<5)	  
			stSysParameterApp.stable_count1=stSysParameterApp.stable_count;
		else if(stSysParameterApp.stable_count<30)  
			stSysParameterApp.stable_count1=5;
		//else if(stable_count<50)   stable_count1=20;
		else 
			stSysParameterApp.stable_count1=stSysParameterApp.stable_count1+1;
		if(stSysParameterApp.stable_count1>stSysParameterApp.filter_count)	  
			stSysParameterApp.stable_count1=stSysParameterApp.filter_count;


	 	data_temp=data_sum/16;
	 	data_temp=data_temp*5;
		
			 //data_temp =  count_sum*0.01*20
   			data_sum=0;
   			for(i=119;i>0;i--)
			{
		 		stSysParameterApp.data_sp[i]=stSysParameterApp.data_sp[i-1];
		 	}
			 stSysParameterApp.data_sp[0]=data_temp;
	
		 for(i=0;i<stSysParameterApp.stable_count1;i++)
		 {
		 	data_sum=data_sum+stSysParameterApp.data_sp[i];
		 }
		data_avg=data_sum/stSysParameterApp.stable_count1;

		stSysParameterApp.count_data1=data_avg*0.001; //系数修改
		stSysParameterApp.count_sum=0;
		//count_sum1=0;
		//count_sum2=0;
		stSysParameterApp.wt_ok=0;
		stSysParameterApp.get_wt=150;
	}
	if(stSysParameterApp.print_time!=0) //自动打印输出时间
	{
		stSysParameterApp.print_time--;
	}
	if(stSysParameterApp.sencond_set==0)
	{
		stSysParameterApp.sencond_set=714;
		if((stSysParameterApp.lcd_time!=0)&&(stSysParameterApp.lcd_time_flag==1))
		{
			stSysParameterApp.lcd_time--;
		}
	}
	else
	{
		stSysParameterApp.sencond_set--;
	}
    /* USER CODE END EXTI4_IRQn 0 */
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_3);
    /* USER CODE BEGIN EXTI4_IRQn 1 */
}


