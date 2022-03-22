#include "common.h"
#include "ical_motor.h"

void Cal_Last_Stable_First_Line(void)
{
		double First;
	
		First=line_x[1][0]/line_x[0][0];
    line_x[1][1]=line_x[1][1]-line_x[0][1]*First;
    line_x[1][2]=line_x[1][2]-line_x[0][2]*First;
    line_x[1][3]=line_x[1][3]-line_x[0][3]*First;
    line_x[1][4]=line_x[1][4]-line_x[0][4]*First;
    line_x[1][5]=line_x[1][5]-line_x[0][5]*First;
	
    First=line_x[2][0]/line_x[0][0];
    line_x[2][1]=line_x[2][1]-line_x[0][1]*First;
    line_x[2][2]=line_x[2][2]-line_x[0][2]*First;
    line_x[2][3]=line_x[2][3]-line_x[0][3]*First;
    line_x[2][4]=line_x[2][4]-line_x[0][4]*First;
    line_x[2][5]=line_x[2][5]-line_x[0][5]*First;
	
    First=line_x[3][0]/line_x[0][0];
		line_x[3][1]=line_x[3][1]-line_x[0][1]*First;
    line_x[3][2]=line_x[3][2]-line_x[0][2]*First;
    line_x[3][3]=line_x[3][3]-line_x[0][3]*First;
    line_x[3][4]=line_x[3][4]-line_x[0][4]*First;
    line_x[3][5]=line_x[3][5]-line_x[0][5]*First;
    First=line_x[4][0]/line_x[0][0];
    line_x[4][1]=line_x[4][1]-line_x[0][1]*First;
    line_x[4][2]=line_x[4][2]-line_x[0][2]*First;
    line_x[4][3]=line_x[4][3]-line_x[0][3]*First;
    line_x[4][4]=line_x[4][4]-line_x[0][4]*First;
    line_x[4][5]=line_x[4][5]-line_x[0][5]*First;

    First=line_x[2][1]/line_x[1][1];
    line_x[2][2]=line_x[2][2]-line_x[1][2]*First;
    line_x[2][3]=line_x[2][3]-line_x[1][3]*First;
    line_x[2][4]=line_x[2][4]-line_x[1][4]*First;
    line_x[2][5]=line_x[2][5]-line_x[1][5]*First;

    First=line_x[3][1]/line_x[1][1];
    line_x[3][2]=line_x[3][2]-line_x[1][2]*First;
    line_x[3][3]=line_x[3][3]-line_x[1][3]*First;
    line_x[3][4]=line_x[3][4]-line_x[1][4]*First;
    line_x[3][5]=line_x[3][5]-line_x[1][5]*First;

    First=line_x[4][1]/line_x[1][1];
    line_x[4][2]=line_x[4][2]-line_x[1][2]*First;
    line_x[4][3]=line_x[4][3]-line_x[1][3]*First;
    line_x[4][4]=line_x[4][4]-line_x[1][4]*First;
    line_x[4][5]=line_x[4][5]-line_x[1][5]*First;

    First=line_x[3][2]/line_x[2][2];
    line_x[3][3]=line_x[3][3]-line_x[2][3]*First;
    line_x[3][4]=line_x[3][4]-line_x[2][4]*First;
    line_x[3][5]=line_x[3][5]-line_x[2][5]*First;
    First=line_x[4][2]/line_x[2][2];
    line_x[4][3]=line_x[4][3]-line_x[2][3]*First;
    line_x[4][4]=line_x[4][4]-line_x[2][4]*First;
    line_x[4][5]=line_x[4][5]-line_x[2][5]*First;

    First=line_x[4][3]/line_x[3][3];
    line_x[4][4]=line_x[4][4]-line_x[3][4]*First;
    line_x[4][5]=line_x[4][5]-line_x[3][5]*First;

    stSysParameterApp.p1[4]=line_x[4][5]/line_x[4][4];
    stSysParameterApp.p1[3]=(line_x[3][5]-line_x[3][4]*stSysParameterApp.p1[4])/line_x[3][3];
    stSysParameterApp.p1[2]=(line_x[2][5]-line_x[2][4]*stSysParameterApp.p1[4]-line_x[2][3]*stSysParameterApp.p1[3])/line_x[2][2];
    stSysParameterApp.p1[1]=(line_x[1][5]-line_x[1][4]*stSysParameterApp.p1[4]-line_x[1][3]*stSysParameterApp.p1[3]-line_x[1][2]*stSysParameterApp.p1[2])/line_x[1][2];
    stSysParameterApp.p1[0]=(line_x[0][5]-line_x[0][4]*stSysParameterApp.p1[4]-line_x[0][3]*stSysParameterApp.p1[3]-line_x[0][2]*stSysParameterApp.p1[2]-line_x[0][1]*stSysParameterApp.p1[1])/line_x[0][0];
}

void Cal_Last_Stable_Second_Line(void)
{
		double Second;
	
	  Second=line_x2[1][0]/line_x2[0][0];
    line_x2[1][1]=line_x2[1][1]-line_x2[0][1]*Second;
    line_x2[1][2]=line_x2[1][2]-line_x2[0][2]*Second;
    line_x2[1][3]=line_x2[1][3]-line_x2[0][3]*Second;
    line_x2[1][4]=line_x2[1][4]-line_x2[0][4]*Second;
    line_x2[1][5]=line_x2[1][5]-line_x2[0][5]*Second;
	
    Second=line_x2[2][0]/line_x2[0][0];
    line_x2[2][1]=line_x2[2][1]-line_x2[0][1]*Second;
    line_x2[2][2]=line_x2[2][2]-line_x2[0][2]*Second;
    line_x2[2][3]=line_x2[2][3]-line_x2[0][3]*Second;
    line_x2[2][4]=line_x2[2][4]-line_x2[0][4]*Second;
    line_x2[2][5]=line_x2[2][5]-line_x2[0][5]*Second;
	
    Second=line_x2[3][0]/line_x2[0][0];
    line_x2[3][1]=line_x2[3][1]-line_x2[0][1]*Second;
    line_x2[3][2]=line_x2[3][2]-line_x2[0][2]*Second;
    line_x2[3][3]=line_x2[3][3]-line_x2[0][3]*Second;
    line_x2[3][4]=line_x2[3][4]-line_x2[0][4]*Second;
    line_x2[3][5]=line_x2[3][5]-line_x2[0][5]*Second;
		
    Second=line_x2[4][0]/line_x2[0][0];
    line_x2[4][1]=line_x2[4][1]-line_x2[0][1]*Second;
    line_x2[4][2]=line_x2[4][2]-line_x2[0][2]*Second;
    line_x2[4][3]=line_x2[4][3]-line_x2[0][3]*Second;
    line_x2[4][4]=line_x2[4][4]-line_x2[0][4]*Second;
    line_x2[4][5]=line_x2[4][5]-line_x2[0][5]*Second;

    Second=line_x2[2][1]/line_x2[1][1];
    line_x2[2][2]=line_x2[2][2]-line_x2[1][2]*Second;
    line_x2[2][3]=line_x2[2][3]-line_x2[1][3]*Second;
    line_x2[2][4]=line_x2[2][4]-line_x2[1][4]*Second;
    line_x2[2][5]=line_x2[2][5]-line_x2[1][5]*Second;

    Second=line_x2[3][1]/line_x2[1][1];
    line_x2[3][2]=line_x2[3][2]-line_x2[1][2]*Second;
    line_x2[3][3]=line_x2[3][3]-line_x2[1][3]*Second;
    line_x2[3][4]=line_x2[3][4]-line_x2[1][4]*Second;
    line_x2[3][5]=line_x2[3][5]-line_x2[1][5]*Second;

    Second=line_x2[4][1]/line_x2[1][1];
    line_x2[4][2]=line_x2[4][2]-line_x2[1][2]*Second;
    line_x2[4][3]=line_x2[4][3]-line_x2[1][3]*Second;
    line_x2[4][4]=line_x2[4][4]-line_x2[1][4]*Second;
    line_x2[4][5]=line_x2[4][5]-line_x2[1][5]*Second;

    Second=line_x2[3][2]/line_x2[2][2];
    line_x2[3][3]=line_x2[3][3]-line_x2[2][3]*Second;
    line_x2[3][4]=line_x2[3][4]-line_x2[2][4]*Second;
    line_x2[3][5]=line_x2[3][5]-line_x2[2][5]*Second;
						
    Second=line_x2[4][2]/line_x2[2][2];
    line_x2[4][3]=line_x2[4][3]-line_x2[2][3]*Second;
    line_x2[4][4]=line_x2[4][4]-line_x2[2][4]*Second;
    line_x2[4][5]=line_x2[4][5]-line_x2[2][5]*Second;

    Second=line_x2[4][3]/line_x2[3][3];
    line_x2[4][4]=line_x2[4][4]-line_x2[3][4]*Second;
    line_x2[4][5]=line_x2[4][5]-line_x2[3][5]*Second;

    stSysParameterApp.p2[4]=line_x2[4][5]/line_x2[4][4];
    stSysParameterApp.p2[3]=(line_x2[3][5]-line_x2[3][4]*stSysParameterApp.p2[4])/line_x2[3][3];
    stSysParameterApp.p2[2]=(line_x2[2][5]-line_x2[2][4]*stSysParameterApp.p2[4]-line_x2[2][3]*stSysParameterApp.p2[3])/line_x2[2][2];
    stSysParameterApp.p2[1]=(line_x2[1][5]-line_x2[1][4]*stSysParameterApp.p2[4]-line_x2[1][3]*stSysParameterApp.p2[3]-line_x2[1][2]*stSysParameterApp.p2[2])/line_x2[1][1];
    stSysParameterApp.p2[0]=(line_x2[0][5]-line_x2[0][4]*stSysParameterApp.p2[4]-line_x2[0][3]*stSysParameterApp.p2[3]-line_x2[0][2]*stSysParameterApp.p2[2]-line_x2[0][1]*stSysParameterApp.p2[1])/line_x2[0][0];

}
	
void Cal_Last_Stable(void)
{
		Cal_Last_Stable_First_Line();
		Cal_Last_Stable_Second_Line();
    stSysParameter.wt_span=1;
    stSysParameter.wt_tare=0;
    stSysParameter.wt_zero=0;
		M24C64_Write_double(wt_spanADD,stSysParameter.wt_span);
		M24C64_Write_double(wt_zeroADD,stSysParameter.wt_zero);
		//M24C64_Write(0,(uint8_t *)&stSysParameter,sizeof(stSysParameter));
		M24C64_Write_double(pl_aADD,stSysParameterApp.p1[0]);
		M24C64_Write_double(pl_bADD,stSysParameterApp.p1[1]);
		M24C64_Write_double(pl_cADD,stSysParameterApp.p1[2]);
		M24C64_Write_double(pl_dADD,stSysParameterApp.p1[3]);
		M24C64_Write_double(pl_eADD,stSysParameterApp.p1[4]);
		M24C64_Write_double(p2_aADD,stSysParameterApp.p2[0]);
		M24C64_Write_double(p2_bADD,stSysParameterApp.p2[1]);
		M24C64_Write_double(p2_cADD,stSysParameterApp.p2[2]);
		M24C64_Write_double(p2_dADD,stSysParameterApp.p2[3]);
		M24C64_Write_double(p2_eADD,stSysParameterApp.p2[4]);
		//HAL_Delay(2000);
		stSysParameterApp.Diplay_Interface_Page = 0;
		stSysParameterApp.weigh_mode = 1;
}

void Display_Stable_Page(void)
{
			switch(stSysParameterApp.stCal_Stable)
			{
				case 0:
            Lcd_Dispay_Menu(load_0);
        break;
        case 2:
            Lcd_Dispay_Menu(load_50);
        break;
        case 4:
            Lcd_Dispay_Menu(load_100);
        break;
        case 6:
            Lcd_Dispay_Menu(load_150);
        break;
        case 8:
            Lcd_Dispay_Menu(load_200);
				break;
        case 10:
            Lcd_Dispay_Menu(load_220);
        break;
        case 12:
						Cal_Last_Stable();
        break;
        default:
            Lcd_Dispay_Menu(LCD_seg_FUNCT);
				break;
			}
}

void Cal_Weight_Line_Stable(void)
{
		if((stSysParameterApp.stCal_Stable == 0)&&(stSysParameterApp.stable_count>80))
		{
            stSysParameterApp.stCal_Stable = 2;
            line_x[0][0]=stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,4);//*count_data1*count_data1*count_data1;
            line_x[0][1]=stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,3);//count_data1*count_data1*count_data1;
            line_x[0][2]=stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,2);//count_data1*count_data1;
            line_x[0][3]=stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,1);//count_data1;
            line_x[0][4]=1;
            line_x[0][5]=0;

            line_x2[0][0]=stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,4);//count_data1*count_data1*count_data1*count_data1;
            line_x2[0][1]=stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,3);//count_data1*count_data1*count_data1;
            line_x2[0][2]=stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,2);//count_data1*count_data1;
            line_x2[0][3]=stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,1);//count_data1;
            line_x2[0][4]=1;
            line_x2[0][5]=0;
            stSysParameterApp.stStable_line = stSysParameterApp.count_data+500;
		}
		else if((stSysParameterApp.stCal_Stable == 3)&&(stSysParameterApp.stable_count>80))
		{
            stSysParameterApp.stCal_Stable = 4;
            line_x[1][0]=stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,4);//count_data1*count_data1*count_data1*count_data1;
            line_x[1][1]=stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,3);//count_data1*count_data1*count_data1;
            line_x[1][2]=stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,2);//count_data1*count_data1;
            line_x[1][3]=stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,1);//count_data1;
            line_x[1][4]=1;
            line_x[1][5]=50.0000;

            stSysParameterApp.stStable_line = stSysParameterApp.count_data+500;
    }
    else if((stSysParameterApp.stCal_Stable == 5)&&(stSysParameterApp.stable_count>80))
    {
            stSysParameterApp.stCal_Stable = 6;
            line_x[2][0]=stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,4);//count_data1*count_data1*count_data1*count_data1;
            line_x[2][1]=stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,3);//count_data1*count_data1*count_data1;
            line_x[2][2]=stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,2);//count_data1*count_data1;
            line_x[2][3]=stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,1);//count_data1;
            line_x[2][4]=1;
            line_x[2][5]=100.0000;

            line_x2[1][0]=stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,4);//count_data1*count_data1*count_data1*count_data1;
            line_x2[1][1]=stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,3);//count_data1*count_data1*count_data1;
            line_x2[1][2]=stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,2);//count_data1*count_data1;
            line_x2[1][3]=stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,1);//count_data1;
            line_x2[1][4]=1;
            line_x2[1][5]=100.0000;

            stSysParameterApp.stStable_line = stSysParameterApp.count_data+500;
		}
    else if((stSysParameterApp.stCal_Stable == 7)&&(stSysParameterApp.stable_count>80))
    {
            stSysParameterApp.stCal_Stable = 8;
            line_x[3][0]=stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,4);//count_data1*count_data1*count_data1*count_data1;
            line_x[3][1]=stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,3);//count_data1*count_data1*count_data1;
            line_x[3][2]=stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,2);//count_data1*count_data1;
            line_x[3][3]=stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,1);//count_data1;
            line_x[3][4]=1;
            line_x[3][5]=150.0000;

            line_x2[2][0]=stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,4);//count_data1*count_data1*count_data1*count_data1;
            line_x2[2][1]=stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,3);//count_data1*count_data1*count_data1;
            line_x2[2][2]=stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,2);//count_data1*count_data1;
            line_x2[2][3]=stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,1);//count_data1;
            line_x2[2][4]=1;
            line_x2[2][5]=150.0000;
            stSysParameterApp.stStable_line = stSysParameterApp.count_data+500;
    }
    else if((stSysParameterApp.stCal_Stable == 9)&&(stSysParameterApp.stable_count>80))
    {
            stSysParameterApp.stCal_Stable = 10;
            line_x[4][0]=stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,4);//count_data1*count_data1*count_data1*count_data1;
            line_x[4][1]=stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,3);//count_data1*count_data1*count_data1;
            line_x[4][2]=stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,2);//count_data1*count_data1;
            line_x[4][3]=stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,1);//count_data1;
            line_x[4][4]=1;
            line_x[4][5]=200.0000;

            line_x2[3][0]=stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,4);//count_data1*count_data1*count_data1*count_data1;
            line_x2[3][1]=stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,3);//count_data1*count_data1*count_data1;
            line_x2[3][2]=stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,2);//count_data1*count_data1;
            line_x2[3][3]=stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,1);//count_data1;
            line_x2[3][4]=1;
            line_x2[3][5]=200.0000;

            stSysParameterApp.stStable_line = stSysParameterApp.count_data+500;

    }
    else if((stSysParameterApp.stCal_Stable == 11)&&(stSysParameterApp.stable_count > 80))
    {
            stSysParameterApp.stCal_Stable = 12;
            line_x2[4][0]=stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,4);//count_data1*count_data1*count_data1*count_data1;
            line_x2[4][1]=stSysParameterApp.count_data1*stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,3);//count_data1*count_data1*count_data1;
            line_x2[4][2]=stSysParameterApp.count_data1*stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,2);//count_data1*count_data1;
            line_x2[4][3]=stSysParameterApp.count_data1;//pow(stSysParameterApp.count_data1,1);//count_data1;
            line_x2[4][4]=1;
            line_x2[4][5]=220.0000;
        }
}

void Display_Cal_Page(uint8_t KEY_Cmd)
{
		//uint8_t KEY_Cmd;
	
		//KEY_Cmd = KEY_ADC_Value();
		switch(KEY_Cmd)
		{
				case KEY_CAL:
					break;
				case KEY_MODE:
					break;
				case KEY_SET:													
					break;
				case KEY_TARE:
					if((stSysParameterApp.stCal_Stable == 2)&&(stSysParameterApp.stStable_line < stSysParameterApp.count_data))
					{
							stSysParameterApp.stCal_Stable = 3;
							stSysParameterApp.stable_count = 0;
							stSysParameterApp.cal_sum = 0;
					}
					else if((stSysParameterApp.stCal_Stable == 4)&&(stSysParameterApp.stStable_line < stSysParameterApp.count_data))
					{
							stSysParameterApp.stCal_Stable = 5;
							stSysParameterApp.stable_count = 0;
							stSysParameterApp.cal_sum = 0;
					}
					else if((stSysParameterApp.stCal_Stable == 6)&&(stSysParameterApp.stStable_line < stSysParameterApp.count_data))
					{
							stSysParameterApp.stCal_Stable = 7;
							stSysParameterApp.stable_count = 0;
							stSysParameterApp.cal_sum = 0;
					}
					else if((stSysParameterApp.stCal_Stable == 8)&&(stSysParameterApp.stStable_line < stSysParameterApp.count_data))
					{
							stSysParameterApp.stCal_Stable = 9;
							stSysParameterApp.stable_count = 0;
							stSysParameterApp.cal_sum = 0;
					}
					else if(stSysParameterApp.stCal_Stable == 10)
					{
							stSysParameterApp.stCal_Stable = 11;
							stSysParameterApp.stable_count = 0;
							stSysParameterApp.cal_sum = 0;
					}					
					break;
				case KEY_POWER:
					stSysParameterApp.Diplay_Interface_Page = 0;
					stSysParameterApp.weigh_mode = 0;
					break;
				case KEY_PRINT:
					break;
				default:
					break;
		}
		Display_Stable_Page();
		Cal_Weight_Line_Stable();
}

void Display_Cal_Ex_Page(uint8_t KEY_Cmd)
{	
	if(stSysParameterApp.stCal_Mode == 1)
	{
		Lcd_Dispay_Menu(LCD_seg_cal100);
	}
	else
	{
		Lcd_Dispay_Menu(LCD_seg_cal200);
	}

	switch(KEY_Cmd)
	{
		case KEY_CAL:
			stSysParameterApp.Diplay_Interface_Page = 6;
		  Lcd_Dispay_Menu(LCD_CALin_menu);
			HAL_Delay(3*1000);
			stSysParameterApp.cal_span_count=0;
			stSysParameterApp.cal_span_error=0;
			break;
		case KEY_MODE:
			break;
		case KEY_SET:													//设置界面再次按设置键
			break;
		case KEY_TARE:
			if(stSysParameterApp.stCal_Mode == 1)
				stSysParameterApp.stCal_Mode = 2;
			else
				stSysParameterApp.stCal_Mode = 1;
			break;
		case KEY_POWER:
			stSysParameterApp.Diplay_Interface_Page = 0;
			stSysParameterApp.weigh_mode = 0;
			break;
		case KEY_PRINT:
			break;
		default:
			break;
	}	
}

void Display_Cal_Span_Page(uint8_t KEY_Cmd)
{
	//uint8_t KEY_Cmd;
	//	KEY_Cmd = KEY_ADC_Value();
		switch(KEY_Cmd)
		{
			case KEY_CAL:
				break;
			case KEY_MODE:
				break;
			case KEY_SET:													//设置界面再次按设置键
				break;
			case KEY_TARE:
				break;
			case KEY_POWER:
				stSysParameterApp.Diplay_Interface_Page = 0;
				stSysParameterApp.weigh_mode = 0;
				tare();
				break;
			case KEY_PRINT:
				break;
			default:
				break;
		}
		if(stSysParameterApp.wt_ok==0)
    {
        stSysParameterApp.wt_poly = wt_line(stSysParameterApp.count_data1,stSysParameterApp.p1,stSysParameterApp.p2);
				wt_filter();
        stSysParameterApp.wt_ok=1;
    }
		if(stSysParameterApp.cal_span_error!=0)
    {
        if(stSysParameterApp.cal_span_error==1)
        {
             Lcd_Dispay_Menu(LCD_CALno_menu0);
        }
        else if(stSysParameterApp.cal_span_error==2)
        {
             Lcd_Dispay_Menu(LCD_CALno_menu1);
        }
        else
        {
             Lcd_Dispay_Menu(LCD_CALno_menu2);
        }
        //HAL_Delay(1000);
//				stSysParameterApp.Diplay_Interface_Page = 0;
//				stSysParameterApp.weigh_mode = 0;
////				tare();
    }
    if(stSysParameterApp.cal_span_count==1)
    {
        Lcd_Dispay_Menu(LCD_CALdn_menu);
    }
    else if(stSysParameterApp.cal_span_count==3)
    {
				Lcd_Dispay_Menu(LCD_CALup_menu);
	
    }
    else if(stSysParameterApp.cal_span_count==5)
    {
        Lcd_Dispay_Menu(LCD_CALend_menu);
				HAL_Delay(1000);
				stSysParameterApp.Diplay_Interface_Page = 0;
				stSysParameterApp.weigh_mode = 1;
//				tare();
		}
    else
		{
        Lcd_Dispay_Menu(LCD_CAL_menu);
    }
    if((stSysParameterApp.cal_span_count==0)&&(stSysParameterApp.stable_count>80))
    {
        stSysParameterApp.cal_span_count=1;
        if(stSysParameterApp.wt_poly-stSysParameterApp.wt_zero_flag>4)
        {
             stSysParameterApp.cal_span_error=1;
        }
        else
        {
						stSysParameter.wt_tare=stSysParameterApp.wt_poly;
            stSysParameter.wt_zero=stSysParameter.wt_tare;
                //FM25CL64_Write_double(0x00,0x5b, wt_zero);
						M24C64_Write_double(wt_zeroADD, stSysParameter.wt_zero);
						//M24C64_Write_double(wt_spanADD, stSysParameter.wt_tare);
        }
            //stable_line=count_data+20000;
    }
    if((stSysParameterApp.cal_span_count==1)&&(stSysParameterApp.wt_poly>50))
    {
				stSysParameterApp.cal_span_error = 0;
        stSysParameterApp.cal_span_count=2;
    }
    if((stSysParameterApp.cal_span_count==2)&&(stSysParameterApp.stable_count>80))
		{
        stSysParameterApp.cal_span_count=3;
        if(stSysParameterApp.stCal_Mode==1)
        {
            if(stSysParameterApp.wt_poly-stSysParameter.wt_tare<98.000)
            {
                stSysParameterApp.cal_span_error=2;
            }
            else if(stSysParameterApp.wt_poly-stSysParameter.wt_tare>102.000)
            {
                stSysParameterApp.cal_span_error=3;
            }
            else
            {
                stSysParameter.wt_span=100.000/(stSysParameterApp.wt_poly-stSysParameter.wt_tare);
                    //FM25CL64_Write_double(0x00,0x53, wt_span);
								M24C64_Write_double(wt_spanADD, stSysParameter.wt_span);
            }
				}
        else
        {
            if(stSysParameterApp.wt_poly-stSysParameter.wt_tare<198.000)
            {
                stSysParameterApp.cal_span_error=2;
            }
            else if(stSysParameterApp.wt_poly-stSysParameter.wt_tare>202.000)
            {
                stSysParameterApp.cal_span_error=3;
            }
            else
            {
                stSysParameter.wt_span=200.000/(stSysParameterApp.wt_poly-stSysParameter.wt_tare);
                    //FM25CL64_Write_double(0x00,0x53, wt_span);
								M24C64_Write_double(wt_spanADD, stSysParameter.wt_span);
            }
        }
            //stable_line=count_data-20000;
    }
    if((stSysParameterApp.cal_span_count==3)&&(stSysParameterApp.wt_poly<20))//(stSysParameterApp.wt_poly<10))
    {
				stSysParameterApp.cal_span_error = 0;
        stSysParameterApp.cal_span_count=4;
    }
    if((stSysParameterApp.cal_span_count==4)&&(stSysParameterApp.stable_count>80))
    {
        stSysParameterApp.cal_span_count=5;
    }
		tare();
}

