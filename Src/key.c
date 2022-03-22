#include "key.h"
#include "common.h"
#include "stdint.h"

uint8_t KEY_ADC_Value(void)
{
		uint16_t uwConvertedValue;
	
		uwConvertedValue = HAL_ADC_GetValue(&AdcHandle);
		if(  uwConvertedValue < 0x2000)
		{
				KEY_DATA = KEY_NULL;
				key_stats = 0;
		}
		if ((uwConvertedValue > 0x2000) && ( key_stats == 0))
		{
				HAL_Delay(60);	
				if ((uwConvertedValue > 0x2A00) && (uwConvertedValue < 0x2EFF))
				{
						KEY_DATA3=KEY_DATA2;
						KEY_DATA2=KEY_DATA1;
						KEY_DATA1 = KEY_POWER;
						if((KEY_DATA1==KEY_DATA2)&&(KEY_DATA2==KEY_DATA3)&&(KEY_DATA1!=KEY_NULL)&&(KEY_DATA2!=KEY_NULL)&&(KEY_DATA3!=KEY_NULL))
						{
								KEY_DATA = KEY_POWER;
								key_stats = 1;
						}
				}
				else if ((uwConvertedValue > 0x5400) && (uwConvertedValue < 0x55FF)&&(stSysParameterApp.blance_state==1))	
				{
						KEY_DATA3=KEY_DATA2;
						KEY_DATA2=KEY_DATA1;
						KEY_DATA1 = KEY_MODE;
						if((KEY_DATA1==KEY_DATA2)&&(KEY_DATA2==KEY_DATA3)&&(KEY_DATA1!=KEY_NULL)&&(KEY_DATA2!=KEY_NULL)&&(KEY_DATA3!=KEY_NULL))
						{
								KEY_DATA = KEY_MODE;
								key_stats = 1;
						}
				}
				else if ((uwConvertedValue > 0xFD00) && (uwConvertedValue < 0xFEFF)&&(stSysParameterApp.blance_state==1))
				{
						KEY_DATA3=KEY_DATA2;
						KEY_DATA2=KEY_DATA1;
						KEY_DATA1 = KEY_SET;
						if((KEY_DATA1==KEY_DATA2)&&(KEY_DATA2==KEY_DATA3)&&(KEY_DATA1!=KEY_NULL)&&(KEY_DATA2!=KEY_NULL)&&(KEY_DATA3!=KEY_NULL))
						{
								KEY_DATA = KEY_SET;
								key_stats = 1;
						}
				}
				else if ((uwConvertedValue > 0x7A00) && (uwConvertedValue < 0x7CFF)&&(stSysParameterApp.blance_state==1))
				{
						KEY_DATA3=KEY_DATA2;
						KEY_DATA2=KEY_DATA1;
						KEY_DATA1 = KEY_PRINT;
						if((KEY_DATA1==KEY_DATA2)&&(KEY_DATA2==KEY_DATA3)&&(KEY_DATA1!=KEY_NULL)&&(KEY_DATA2!=KEY_NULL)&&(KEY_DATA3!=KEY_NULL))
						{
								KEY_DATA = KEY_PRINT;
								key_stats = 1;
						}
				}
				else if ((uwConvertedValue > 0xA100) && (uwConvertedValue < 0xA3FF)&&(stSysParameterApp.blance_state==1))
				{
						KEY_DATA3=KEY_DATA2;
						KEY_DATA2=KEY_DATA1;
						KEY_DATA1 = KEY_TARE;
						if((KEY_DATA1==KEY_DATA2)&&(KEY_DATA2==KEY_DATA3)&&(KEY_DATA1!=KEY_NULL)&&(KEY_DATA2!=KEY_NULL)&&(KEY_DATA3!=KEY_NULL))
						{
								KEY_DATA = KEY_TARE;
								key_stats = 1;
						}
				}
				else if ((uwConvertedValue > 0xCC00) && (uwConvertedValue < 0xCDFF)&&(stSysParameterApp.blance_state==1))
				{
						KEY_DATA3=KEY_DATA2;
						KEY_DATA2=KEY_DATA1;
						KEY_DATA1 = KEY_CAL;
						if((KEY_DATA1==KEY_DATA2)&&(KEY_DATA2==KEY_DATA3)&&(KEY_DATA1!=KEY_NULL)&&(KEY_DATA2!=KEY_NULL)&&(KEY_DATA3!=KEY_NULL))
						{
								KEY_DATA = KEY_CAL;
								key_stats = 1;
						}
				}
		
		}
		else
		{
				KEY_DATA=KEY_NULL;
		}
		return KEY_DATA;
}
