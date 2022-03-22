#include "common.h"
#include "Display_Function.h"

void Display_Weight_Page(uint8_t KEY_Cmd)
{
	uint8_t buf1[8] = {0x20};
	//uint8_t KEY_Cmd = 0;
	
	//KEY_Cmd = KEY_ADC_Value();
	switch(KEY_Cmd)
	{
		case KEY_CAL:					//进入校准模式
//			Send_Modbus_Buf(0x02,0x10,0x01,0x01,0x01,buf1);
			//Diplay_Interface_Page = 3;
			//not_weighing_mode = 1;
			//
			//cal_temp_mode = Cal_Display_Interface();
			//if(cal_temp_mode == 1)
			//	Display_Menui(LCD_seg_cal100);
			//else if(cal_temp_mode == 2)
			//	Display_Menui(LCD_seg_cal200);
		
			if(stSysParameter.C_Parameter[2] != 6)
			{
					if(stSysParameter.C_Parameter[0] == 1)//外部校准
					{
							stSysParameterApp.Diplay_Interface_Page = 4;
							stSysParameterApp.weigh_mode = 0;
							stSysParameterApp.stCal_Mode = 1;
					}	
					else if(stSysParameter.C_Parameter[0] == 2)//内校砝码对比校准
					{
							stSysParameterApp.Diplay_Interface_Page = 5;
							stSysParameterApp.weigh_mode = 0;
					}
					else			//内校
					{
						;
					}
			}
			else
			{
					stSysParameterApp.Diplay_Interface_Page = 3;
					stSysParameterApp.weigh_mode = 0;
					stSysParameterApp.stable_count = 0;
					stSysParameterApp.stStable_line = 0;
					stSysParameterApp.cal_sum = 0;
			}
			break;
		case KEY_MODE:				//模式切换（称重模式）
				stSysParameterApp.weigh_unit++;
				if(stSysParameterApp.weigh_unit > 5)	
					stSysParameterApp.weigh_unit = 0;
			break;
		case KEY_SET:					//进入设置界面
			stSysParameterApp.Diplay_Interface_Page = 1;
			stSysParameterApp.weigh_mode = 0;
			stSysParameterApp.weigh_state = 0;
			Lcd_Dispay_Process(LCD_seg_menu);
			break;
		case KEY_TARE:				//去皮
			tare();
			Send_Modbus_Buf(0x02,0x10,0x00,0x01,0x01,buf1);
			break;
		case KEY_POWER:				//屏幕亮灭控制
			if(stSysParameterApp.blance_state == 1)
			{
				HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14, GPIO_PIN_RESET);
				stSysParameterApp.blance_state = 0;
			}
			else
			{
				stSysParameterApp.blance_state = 1;
				HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14, GPIO_PIN_SET);
			}
			break;
//		case KEY_PRINT:			//打印功能
//			key_print_flag = 1;
//			break;
		default:
			break;
	}
}

void Display_Set_Page(uint8_t KEY_Cmd)
{
	uint8_t LCD[16],i;
	//uint8_t KEY_Cmd = 0;
	
	for(i = 0;i < 16;i ++)
		LCD[i] = LCD_menu[i];
	
	//KEY_Cmd = KEY_ADC_Value();
	switch(KEY_Cmd)
	{
		case KEY_CAL:
			break;
		case KEY_MODE:
			stSysParameterApp.Diplay_Interface_Page = 7;
			stSysParameterApp.weigh_mode = 0;
			stSysParameterApp.weigh_state = 0;
			for(i = 0;i < 16;i ++)
					LCD[i] = LCD_Add[i];
			LCD[6] = Display_Num_LCD(stSysParameterApp.add_200g_parameter);
			Lcd_Dispay_Menu(LCD);		
			break;
		case KEY_SET:													//设置界面再次按设置键
			stSysParameterApp.Diplay_Interface_Page = 0;
			stSysParameterApp.weigh_mode = 1;
			stSysParameterApp.weigh_state = 0;			
			break;
		case KEY_TARE:
			break;
		case KEY_POWER:
			stSysParameterApp.Diplay_Interface_Page = 0;
			stSysParameterApp.weigh_mode = 1;
			stSysParameterApp.weigh_state = 0;
			break;
		case KEY_PRINT:
			stSysParameterApp.Diplay_Interface_Page = 2;
			stSysParameterApp.weigh_mode = 0;
			for(i = 0;i < 16;i ++)
				LCD[i] = LCD_menu[i];
			//wt_stable = 1;
			CCountNum = 1;
			LCD[5] = Display_Num_LCD(stSysParameter.C_Parameter[0]);
			Lcd_Dispay_Menu(LCD);
			break;
		
		default:
			break;
	}	
}

uint8_t Display_C_Parameter(uint8_t num)
{
	uint8_t CParameter;
	
	if(num == 1)
	{
		stSysParameter.C_Parameter[0] ++;
		if(stSysParameter.C_Parameter[0] > 2)
			stSysParameter.C_Parameter[0] = 0;
		CParameter = Display_Num_LCD(stSysParameter.C_Parameter[0]);
	}
	else if(num == 2)
	{
		stSysParameter.C_Parameter[1] ++;
		if(stSysParameter.C_Parameter[1] > 4)
			stSysParameter.C_Parameter[1] = 0;
		CParameter = Display_Num_LCD(stSysParameter.C_Parameter[1]);
	}
	else if(num == 3)
	{
		stSysParameter.C_Parameter[2] ++;
		if(stSysParameter.C_Parameter[2] > 6)
			stSysParameter.C_Parameter[2] = 0;
		CParameter = Display_Num_LCD(stSysParameter.C_Parameter[2]);
	}
	else if(num == 4)
	{
		stSysParameter.C_Parameter[3] ++;
		if(stSysParameter.C_Parameter[3] > 3)
			stSysParameter.C_Parameter[3] = 0;
		CParameter = Display_Num_LCD(stSysParameter.C_Parameter[3]);
	}
	else if(num == 5)
	{
		stSysParameter.C_Parameter[4] ++;
		if(stSysParameter.C_Parameter[4] > 3)
			stSysParameter.C_Parameter[4] = 0;
		CParameter = Display_Num_LCD(stSysParameter.C_Parameter[4]);
	}
	else if(num == 6)
	{
		stSysParameter.C_Parameter[5] ++;
		if(stSysParameter.C_Parameter[5] > 1)
			stSysParameter.C_Parameter[5] = 0;
		CParameter = Display_Num_LCD(stSysParameter.C_Parameter[5]);
	}
	else if(num == 7)
	{
		stSysParameter.C_Parameter[6] ++;
		if(stSysParameter.C_Parameter[6] > 1)
			stSysParameter.C_Parameter[6] = 0;
		CParameter = Display_Num_LCD(stSysParameter.C_Parameter[6]);
	}
	else if(num == 8)
	{
		stSysParameter.C_Parameter[7] ++;
		if(stSysParameter.C_Parameter[7] > 3)
			stSysParameter.C_Parameter[7] = 0;
		CParameter = Display_Num_LCD(stSysParameter.C_Parameter[7]);
	}
			
	return CParameter;
}

uint8_t Display_C_Count(uint8_t num)
{
	uint8_t CCount;
	
	if(num == 1)
	{
		CCount = Display_Num_LCD(stSysParameter.C_Parameter[0]);
	}
	else if(num == 2)
	{
		CCount = Display_Num_LCD(stSysParameter.C_Parameter[1]);
	}
	else if(num == 3)
	{
		CCount = Display_Num_LCD(stSysParameter.C_Parameter[2]);
	}
	else if(num == 4)
	{
		CCount = Display_Num_LCD(stSysParameter.C_Parameter[3]);
	}
	else if(num == 5)
	{
		CCount = Display_Num_LCD(stSysParameter.C_Parameter[4]);
	}
	else if(num == 6)
	{
		CCount = Display_Num_LCD(stSysParameter.C_Parameter[5]);
	}
	else if(num == 7)
	{
		CCount = Display_Num_LCD(stSysParameter.C_Parameter[6]);
	}
	else if(num == 8)
	{
		CCount = Display_Num_LCD(stSysParameter.C_Parameter[7]);
	}
	return CCount;
}

void Display_Set_Parameter_Page(uint8_t KEY_Cmd)
{
	uint8_t LCD[16],LCD2[16],i;
	//uint8_t KEY_Cmd = 0;
	
	for(i = 0;i < 16;i ++)
	{
		LCD[i] = LCD_menu[i];
		LCD2[i] = 0;
	}
	//KEY_Cmd = KEY_ADC_Value();
	switch(KEY_Cmd)
	{
		case KEY_CAL:
			break;
		case KEY_MODE:
			break;
		case KEY_SET:													//设置界面再次按设置键
			break;
		case KEY_TARE:
			CCountNum ++;
			if(CCountNum > 8)
			{
					CCountNum = 1;
			}
			LCD[2] = Display_Num_LCD(CCountNum);
			LCD[5] = Display_C_Count(CCountNum);
			Lcd_Dispay_Menu(LCD);
			break;
		case KEY_POWER:
			//M24C64_Write(0,(uint8_t *)&stSysParameter,sizeof(stSysParameter));
			M24C64_Write(SaveSetUPGenserADD,stSysParameter.C_Parameter,13);//写入flash
			stSysParameterApp.zero = zero_index[stSysParameter.C_Parameter[2]];				//零点数据
			stSysParameterApp.baud = baud_value[stSysParameter.C_Parameter[3]];				//串口波特率
			stSysParameterApp.print_time = print_time_table[stSysParameter.C_Parameter[5]];
			stSysParameterApp.filter_value = filter_count_table[stSysParameter.C_Parameter[7]];
			stSysParameterApp.filter_count = filter_count_table[stSysParameter.C_Parameter[7]];
			stSysParameterApp.auto_time = auto_time_table[stSysParameter.C_Parameter[6]];
			LCD2[1] = 0xB5;
			LCD2[2] = 0x20;
			LCD2[3] = 0xF1;
			LCD2[4] = 0x64;
			LCD2[5] = 0xE6;
			Lcd_Dispay_Menu(LCD2);
			HAL_Delay(2000);
			stSysParameterApp.Diplay_Interface_Page = 0;
			stSysParameterApp.weigh_mode = 1;
//			wt_stable = 1;
			break;
		case KEY_PRINT:
			LCD[2] = Display_Num_LCD(CCountNum);
			LCD[5] = Display_C_Parameter(CCountNum);
			Lcd_Dispay_Menu(LCD);
			break;
		default:
			break;
	}	
}

void Display_Add_Page(uint8_t KEY_Cmd)
{
	uint8_t LCD[16],i,LCD2[16];
	//uint8_t KEY_Cmd = 0;
	
	for(i = 0;i < 16;i ++)
	{
		LCD[i] = LCD_Add[i];
		LCD2[i] = 0x0;
	}
	//KEY_Cmd = KEY_ADC_Value();
	switch(KEY_Cmd)
	{
		case KEY_CAL:
			break;
		case KEY_MODE:
			break;
		case KEY_SET:													//设置界面再次按设置键
			break;
		case KEY_TARE:
			stSysParameterApp.add_200g_parameter ++;
			if(stSysParameterApp.add_200g_parameter > 9)
			{
					stSysParameterApp.add_200g_parameter = 0;
			}
			//LCD[2] = Display_Num_LCD(stSysParameterApp.add_200g_parameter);
			//LCD[5] = Display_C_Count(stSysParameterApp.add_200g_parameter);
			LCD[6] = Display_Num_LCD(stSysParameterApp.add_200g_parameter);
			Lcd_Dispay_Menu(LCD);			
			break;
		case KEY_POWER:
			stSysParameter.C_Parameter[8] = stSysParameterApp.add_200g_parameter;
			M24C64_Write(SaveSetUPGenserADD,stSysParameter.C_Parameter,13);//写入flash
			stSysParameterApp.zero = zero_index[stSysParameter.C_Parameter[2]];
			LCD2[1] = 0xB5;
			LCD2[2] = 0x20;
			LCD2[3] = 0xF1;
			LCD2[4] = 0x64;
			LCD2[5] = 0xE6;
			Lcd_Dispay_Menu(LCD2);
			HAL_Delay(2000);
			stSysParameterApp.Diplay_Interface_Page = 0;
			stSysParameterApp.weigh_mode = 1;
			break;
		case KEY_PRINT:
			break;
		default:
			break;
	}	
}
	
void Function_Selection(void)
{
	uint8_t KEY_Cmd = 0;
	KEY_Cmd = KEY_ADC_Value();
		switch(stSysParameterApp.Diplay_Interface_Page)
		{
			case 0://称重界面
				Display_Weight_Page(KEY_Cmd);
			break;
			
			case 1://设置界面
				Display_Set_Page(KEY_Cmd);
				break;
			
			case 2://设置参数界面
				Display_Set_Parameter_Page(KEY_Cmd);
				break;
			
			case 3://进入校准界面
				Display_Cal_Page(KEY_Cmd);
				break;
			
			case 4:	//外部校准
				Display_Cal_Ex_Page(KEY_Cmd);
				break;
//			
			//			case 5://内校砝码对比校准
//				Display_Cal_In_Page(KEY_Cmd);
//				break;
//			
			case 6://内部校准
				Display_Cal_Span_Page(KEY_Cmd);
				break;
			case 7:
				Display_Add_Page(KEY_Cmd);
				break;
			default:
				break;
		}
}

void Display_Weight_Interface(void)
{
		uint8_t LCD[16];
	
		if(stSysParameterApp.weigh_mode == 1)
		{
			stSysParameterApp.wt_poly = wt_line(stSysParameterApp.count_data1,stSysParameterApp.p1,stSysParameterApp.p2);
			wt_filter();
			wt_track();
			//uint32_t display_data,uint8_t *dis_num,double wt_poly,uint8_t Mode_Type,double wt_tarack,double count_h1,double count_l,double wt_zero_flag,uint32_t stable_count,uint32_t stable_data,uint8_t unit_pcs_percent,uint32_t COUNT_WEIGHT_DAT,uint32_t PERCENT_WEIGHT_DAT)
			units_LONG_TO_disSEG(stSysParameterApp.display_data,LCD,stSysParameterApp.wt_poly,stSysParameterApp.weigh_unit,stSysParameterApp.wt_tarack,stSysParameterApp.count_h1,stSysParameterApp.count_l,stSysParameterApp.wt_zero_flag,stSysParameterApp.stable_count,stSysParameterApp.stable_data,stSysParameterApp.unit_pcs_percent,stSysParameterApp.COUNT_WEIGHT_DAT,stSysParameterApp.PERCENT_WEIGHT_DAT);
			Lcd_Dispay_Process(LCD);
		}
}

