#include "common.h"
#include "datamath.h"
#include "math.h"

void wt_filter(void)
{
    double wt_sum;
    uint8_t i=0;
    wt_sum=0;
    for(i=119; i>0; i--)
    {
        stSysParameterApp.wt_sp[i] = stSysParameterApp.wt_sp[i-1];
    }
    stSysParameterApp.wt_sp[0]=stSysParameterApp.wt_poly;
    if(stSysParameterApp.wt_poly<180)
    {
        if(stSysParameter.C_Parameter[7]<2)
        {
            if(stSysParameterApp.wt_sp[10]-stSysParameterApp.wt_poly>0.002)
            {
                stSysParameterApp.stable_count1=2;
            }
            else if(stSysParameterApp.wt_poly-stSysParameterApp.wt_sp[10]>0.002)
            {
                stSysParameterApp.stable_count1=2;
            }
        }
        else
        {
            if(stSysParameterApp.wt_sp[30]-stSysParameterApp.wt_poly>0.003)
            {
                stSysParameterApp.stable_count1=2;
            }
            else if(stSysParameterApp.wt_poly-stSysParameterApp.wt_sp[30]>0.003)
            {
                stSysParameterApp.stable_count1=2;
            }
        }
    }
    if(stSysParameterApp.wt_poly<180)
    {
        if(stSysParameterApp.wt_sp[10]-stSysParameterApp.wt_poly>stSysParameterApp.filter_value)
        {
            stSysParameterApp.wt_filter_flag=1;
        }
        else if(stSysParameterApp.wt_poly-stSysParameterApp.wt_sp[10]>stSysParameterApp.filter_value)
        {
            stSysParameterApp.wt_filter_flag=1;
        }
        else
        {
            if(stSysParameterApp.wt_filter_flag<100)
                stSysParameterApp.wt_filter_flag=stSysParameterApp.wt_filter_flag+1;
        }
    }
    else
    {
        if(stSysParameterApp.wt_sp[10]-stSysParameterApp.wt_poly>0.003)
        {
            stSysParameterApp.wt_filter_flag=1;
        }
        else if(stSysParameterApp.wt_poly-stSysParameterApp.wt_sp[10]>0.003)
        {
            stSysParameterApp.wt_filter_flag=1;
        }
        else
        {
            if(stSysParameterApp.wt_filter_flag<100) 
							stSysParameterApp.wt_filter_flag=stSysParameterApp.wt_filter_flag+1;
        }
    }
    if(stSysParameterApp.wt_poly>10)
    {
        stSysParameterApp.wt_filter_flag1=stSysParameterApp.wt_filter_flag;
        if(stSysParameterApp.wt_filter_flag1>stSysParameterApp.filter_count)	  
					stSysParameterApp.wt_filter_flag1=stSysParameterApp.filter_count;
        for(i=0; i<stSysParameterApp.wt_filter_flag1; i++)
        {
            wt_sum=wt_sum+stSysParameterApp.wt_sp[i];
        }
        stSysParameterApp.wt_poly=wt_sum/stSysParameterApp.wt_filter_flag1;
    }
    else
    {
        if(stSysParameterApp.wt_filter_flag<10)	  
					stSysParameterApp.wt_filter_flag1=stSysParameterApp.wt_filter_flag;
        else if(stSysParameterApp.wt_filter_flag<30)   
					stSysParameterApp.wt_filter_flag1=10;
        else 
					stSysParameterApp.wt_filter_flag1=stSysParameterApp.wt_filter_flag1+1;
        if(stSysParameterApp.wt_filter_flag1>100)	  
					stSysParameterApp.wt_filter_flag1=100;
        for(i=0; i<stSysParameterApp.wt_filter_flag1; i++)
        {
            wt_sum=wt_sum+stSysParameterApp.wt_sp[i];
        }
        stSysParameterApp.wt_poly=wt_sum/stSysParameterApp.wt_filter_flag1;
    }


}

void tare(void)
{
    while(stSysParameterApp.stable_count<20)
    {
        Lcd_Dispay_Menu(LCD_seg_FUNCT);
        if(stSysParameterApp.wt_ok==0)
        {
            stSysParameterApp.wt_poly = wt_line(stSysParameterApp.count_data1,stSysParameterApp.p1,stSysParameterApp.p2);
            wt_filter();
            stSysParameterApp.wt_ok=1;
        }
    }
    stSysParameterApp.wt_poly = wt_line(stSysParameterApp.count_data1,stSysParameterApp.p1,stSysParameterApp.p2);
    wt_filter();
    stSysParameter.wt_tare = stSysParameterApp.wt_poly;
    stSysParameterApp.wt_tare_add=0;
    //zero_display = 0;
    if(stSysParameterApp.wt_poly-stSysParameter.wt_zero<4)
    {
        stSysParameterApp.wt_zero_flag=stSysParameterApp.wt_poly;
    }
    stSysParameterApp.wt_tare_add=0;
}

double wt_line(double count_data1,double *p1,double *p2)
{
		double wt_poly;
    //wt_poly=/*pow(count_data1,4)*p1[0] + pow(count_data1,3)*p1[1]+pow(count_data1,2)*p1[2] + pow(count_data1,1)*p1[3];// + p1[4];*///count_data1*count_data1*count_data1*count_data1*pl_a+count_data1*count_data1*count_data1*pl_b+count_data1*count_data1*pl_c+count_data1*pl_d+pl_e;
		wt_poly = count_data1*count_data1*count_data1*count_data1*p1[0];
		wt_poly = wt_poly + count_data1*count_data1*count_data1*p1[1];
		wt_poly = wt_poly + count_data1*count_data1*p1[2];
		wt_poly = wt_poly + count_data1*p1[3];
		wt_poly = wt_poly +	p1[4];
	  if((wt_poly > 220.2) | (wt_poly < -220.2))
    {
        wt_poly=pow(count_data1,4)*p2[0] + pow(count_data1,3)*p2[1]+pow(count_data1,2)*p2[2] + pow(count_data1,1)*p2[3] + p2[4];
    }
		return wt_poly;
}

void wt_track(void)
{
	//double wt_tarack;
	
//    if(stSysParameterApp.wt_poly>224.4)
//    {
//        stSysParameterApp.wt_over=1;
//        return;
//    }
    stSysParameterApp.wt_over=0;
    stSysParameterApp.zw=stSysParameterApp.wt_poly-stSysParameterApp.wt_poly1;
    stSysParameterApp.wt_poly1=stSysParameterApp.wt_poly;
//-------------------------------------------------------------
    if((stSysParameterApp.zw<0.0002)&&(stSysParameterApp.zw>-0.0002))
    {
        //wt_poly = wt_poly1; //yhb add
        if(stSysParameterApp.stable_not_num!=0)
        {
            stSysParameterApp.stable_not_num--;
        }
        if(stSysParameterApp.stable_not_num<25)
        {
            stSysParameterApp.weigh_state = 0;//wt_stable=1;  //稳定0显示
        }
        if((stSysParameterApp.stable_not_num==0)&&(stSysParameter.C_Parameter[7]>1)&&(stSysParameterApp.wt_poly>0.1))
        {
            stSysParameterApp.wt_tare_add = stSysParameterApp.wt_tare_add+stSysParameterApp.zw;
            stSysParameterApp.wt_poly = stSysParameterApp.wt_poly - stSysParameterApp.wt_tare_add;
        }
        stSysParameterApp.lcd_time_flag=1;
    }
    else
    {
//        if(stSysParameterApp.zw > 0.0004)
//        {
//            stSysParameterApp.zero_display = 0;
//        }
        stSysParameterApp.wt_tare_add=0;
        stSysParameterApp.weigh_state=0;
        stSysParameterApp.stable_not_num=40;
        stSysParameterApp.lcd_time_flag=0;
        stSysParameterApp.lcd_time = 15;

    }
//-------------------------------------------------------------
    stSysParameterApp.wt_tarack=stSysParameterApp.wt_poly-stSysParameterApp.wt_tare;
//		wt_tarack=wt_tarack-wt_tare_add;
//if((count_h1*256+count_l) > 13400)
//	wt_tarack=wt_tarack;
//else
    if(stSysParameterApp.wt_poly > 199)
      stSysParameterApp.wt_tarack = ( stSysParameterApp.wt_tarack + 0.0001*stSysParameterApp.add_200g_parameter);   

    stSysParameterApp.wt_tarack=stSysParameterApp.wt_tarack*stSysParameter.wt_span;
//-------------------------------------------------------------
    if(stSysParameterApp.wt_tarack<0)   //正负显示
    {
        //dis_num[0]|=0x40;
				stSysParameterApp.weigh_state = 2;
        stSysParameterApp.wt_tarack=0-stSysParameterApp.wt_tarack;
    }
    else
    {
        //dis_num[0]&=0xbf;
			stSysParameterApp.weigh_state = 0;
    }
//-------------------------------------------------------------
    if(stSysParameterApp.wt_tarack<=stSysParameterApp.zero)  //自动零位比对
    {
        if(stSysParameterApp.zero_num==0)
        {
            stSysParameterApp.wt_tare=stSysParameterApp.wt_poly;
            stSysParameterApp.wt_tarack=0;
            stSysParameterApp.wt_tare_add=0;
            stSysParameterApp.lcd_time_flag=1;
            stSysParameterApp.zero_time++;
            stSysParameterApp.zero_num=10;
        }
        else
        {
            stSysParameterApp.zero_num--;
        }

    }
    else
    {
        stSysParameterApp.zero_num=10;
    }
//-------------------------------------------------------------
    if(stSysParameterApp.wt_tarack<0.001)
    {
        stSysParameterApp.zero_time++;
    }
    else
    {
        stSysParameterApp.zero_time=0;
    }
//-------------------------------------------------------------
    stSysParameterApp.wt_last=stSysParameterApp.wt_tarack*10000;
    stSysParameterApp.display_data=/*stSysParameterApp.wt_poly;*/stSysParameterApp.wt_last;
}

uint32_t MODE_DATA_PROCESS(uint32_t display_data,uint8_t Mode_Type,uint8_t unit_pcs_percent,uint32_t COUNT_WEIGHT_DAT,uint32_t PERCENT_WEIGHT_DAT)
{
    float i;
    i=display_data;					//公共参数
    if(Mode_Type == 4)
    {
        if(unit_pcs_percent)
        {
            unit_pcs_percent=0;
            stSysParameterApp.COUNT_WEIGHT_DAT=display_data;
            //wzb FM25CL64_Write_float(0x00,0x2f, wt_last);
        }
        i=i*COUNT_UNITS[stSysParameter.C_Parameter[1]];
        i=i/stSysParameterApp.COUNT_WEIGHT_DAT;
        i=i+0.5f;
    }
    else if(Mode_Type == 5)
    {
        if(unit_pcs_percent)
        {
            unit_pcs_percent=0;
            stSysParameterApp.PERCENT_WEIGHT_DAT=display_data;
            //wzb FM25CL64_Write_float(0x00,0x2b, wt_last);
        }
        i=i/stSysParameterApp.PERCENT_WEIGHT_DAT;
        i=i*10000;
    }
    else
    {
        i=i/unit_para[Mode_Type];
        i=i*unit_para_b[Mode_Type];
    }
    display_data=i;
		return display_data;
}

void units_LONG_TO_disSEG(uint32_t display_data,uint8_t *dis_num,double wt_poly,uint8_t Mode_Type,double wt_tarack,double count_h1,double count_l,double wt_zero_flag,uint32_t stable_count,uint32_t stable_data,uint8_t unit_pcs_percent,uint32_t COUNT_WEIGHT_DAT,uint32_t PERCENT_WEIGHT_DAT)
{
    uint8_t n,i,BCD_CODE[8],zero_flag=0;
    //uint8_t Mode_Type=0;
    uint32_t  RESULT1_DAT;
	
    RESULT1_DAT = display_data;
    n=RESULT1_DAT/10000000;
    RESULT1_DAT=RESULT1_DAT % 10000000;
    BCD_CODE[0]=n;
    n=RESULT1_DAT/1000000;
    RESULT1_DAT=RESULT1_DAT % 1000000;
    BCD_CODE[1]=n;
    n=RESULT1_DAT/100000;
    RESULT1_DAT=RESULT1_DAT % 100000;
    BCD_CODE[2]=n;
    n=RESULT1_DAT/10000;
    RESULT1_DAT=RESULT1_DAT % 10000;
    BCD_CODE[3]=n;
    n=RESULT1_DAT/1000;
    RESULT1_DAT=RESULT1_DAT % 1000;
    BCD_CODE[4]=n;
    n=RESULT1_DAT/100;
    RESULT1_DAT=RESULT1_DAT % 100;
    BCD_CODE[5]=n;
    n=RESULT1_DAT/10;
    RESULT1_DAT=RESULT1_DAT % 10;
    BCD_CODE[6]=n;
    n=RESULT1_DAT;
    BCD_CODE[7]=n;//整形转字符串

    if((BCD_CODE[6]==0)&&(BCD_CODE[4]==0)&&(BCD_CODE[5]==0)&&(stSysParameter.C_Parameter[2]!=6))
    {
        if((wt_poly<49.2)&&(display_data>20))
        {
            if(BCD_CODE[7] == 1)
            {
                if(Revise_Parameters == 1)
                {
                    display_data=display_data-1;
                }
                else
                    Revise_Parameters = 1;
            }
            else if(BCD_CODE[7] == 2)
            {
                if(Revise_Parameters == 2)
                {
                    display_data=display_data-2;
                }
                else  if(Revise_Parameters == 1)
                {
                    display_data=display_data-1;
                    Revise_Parameters = 2;
                }
                else
                    Revise_Parameters = 1;
            }
            else
            {
                display_data=display_data-2;
            }
        }
        else if((wt_poly>49.2)&&(wt_poly<122.2))
        {
            if(BCD_CODE[7] == 1)
            {
                if(Revise_Parameters == 1)
                {
                    display_data=display_data-1;
                }
                else
                    Revise_Parameters = 1;
            }
            else if(BCD_CODE[7] == 2)
            {
                if(Revise_Parameters == 2)
                {
                    display_data=display_data-2;
                }
                else  if(Revise_Parameters == 1)
                {
                    display_data=display_data-1;
                    Revise_Parameters = 2;
                }
                else
                    Revise_Parameters = 1;
            }
            else if(BCD_CODE[7] == 3)
            {
                if(Revise_Parameters == 3)
                {
                    display_data=display_data-3;
                }
                else if(Revise_Parameters == 2)
                {
                    display_data=display_data-2;
                    Revise_Parameters = 3;
                }
                else  if(Revise_Parameters == 1)
                {
                    display_data=display_data-1;
                    Revise_Parameters = 2;
                }
                else
                    Revise_Parameters = 1;
            }
            else
            {
                display_data=display_data-2;
            }

        }
        else if((wt_poly>122.2)&&(wt_poly<182.2))
        {
            if(BCD_CODE[7] == 1)
            {
                if(Revise_Parameters == 1)
                {
                    display_data=display_data-1;
                }
                else
                    Revise_Parameters = 1;
            }
            else if(BCD_CODE[7] == 2)
            {
                if(Revise_Parameters == 2)
                {
                    display_data=display_data-2;
                }
                else  if(Revise_Parameters == 1)
                {
                    display_data=display_data-1;
                    Revise_Parameters = 2;
                }
                else
                    Revise_Parameters = 1;
            }
            else if(BCD_CODE[7] == 3)
            {
                if(Revise_Parameters == 3)
                {
                    display_data=display_data-3;
                }
                else if(Revise_Parameters == 2)
                {
                    display_data=display_data-2;
                    Revise_Parameters = 3;
                }
                else  if(Revise_Parameters == 1)
                {
                    display_data=display_data-1;
                    Revise_Parameters = 2;
                }
                else
                    Revise_Parameters = 1;
            }
            else if(BCD_CODE[7] == 4)
            {
                if(Revise_Parameters == 4)
                {
                    display_data=display_data-4;
                }
                else if(Revise_Parameters == 3)
                {
                    display_data=display_data-3;
                    Revise_Parameters = 4;
                }
                else if(Revise_Parameters == 2)
                {
                    display_data=display_data-2;
                    Revise_Parameters = 3;
                }
                else  if(Revise_Parameters == 1)
                {
                    display_data=display_data-1;
                    Revise_Parameters = 2;
                }
                else
                    Revise_Parameters = 1;
            }
            else
            {
                display_data=display_data-2;
            }
        }
        else if((wt_poly>182.2)&&(wt_poly<222.2))
        {
            if(BCD_CODE[7] == 1)
            {
                if(Revise_Parameters == 1)
                {
                    display_data=display_data-1;
                }
                else
                    Revise_Parameters = 1;
            }
            else if(BCD_CODE[7] == 2)
            {
                if(Revise_Parameters == 2)
                {
                    display_data=display_data-2;
                }
                else  if(Revise_Parameters == 1)
                {
                    display_data=display_data-1;
                    Revise_Parameters = 2;
                }
                else
                    Revise_Parameters = 1;
            }
            else if(BCD_CODE[7] == 3)
            {
                if(Revise_Parameters == 3)
                {
                    display_data=display_data-3;
                }
                else if(Revise_Parameters == 2)
                {
                    display_data=display_data-2;
                    Revise_Parameters = 3;
                }
                else  if(Revise_Parameters == 1)
                {
                    display_data=display_data-1;
                    Revise_Parameters = 2;
                }
                else
                    Revise_Parameters = 1;
            }
            else if(BCD_CODE[7] == 4)
            {
                if(Revise_Parameters == 4)
                {
                    display_data=display_data-4;
                }
                else if(Revise_Parameters == 3)
                {
                    display_data=display_data-3;
                    Revise_Parameters = 4;
                }
                else if(Revise_Parameters == 2)
                {
                    display_data=display_data-2;
                    Revise_Parameters = 3;
                }
                else  if(Revise_Parameters == 1)
                {
                    display_data=display_data-1;
                    Revise_Parameters = 2;
                }
                else
                    Revise_Parameters = 1;
            }
            else if(BCD_CODE[7] == 5)
            {
                if(Revise_Parameters == 5)
                {
                    display_data=display_data-5;
                }
                else if(Revise_Parameters == 4)
                {
                    display_data=display_data-4;
                    Revise_Parameters = 5;
                }
                else if(Revise_Parameters == 3)
                {
                    display_data=display_data-3;
                    Revise_Parameters = 4;
                }
                else if(Revise_Parameters == 2)
                {
                    display_data=display_data-2;
                    Revise_Parameters = 3;
                }
                else  if(Revise_Parameters == 1)
                {
                    display_data=display_data-1;
                    Revise_Parameters = 2;
                }
                else
                    Revise_Parameters = 1;
            }
            else
            {
                display_data=display_data-2;
            }
        }
    }
    else if((BCD_CODE[6]==9)&&(BCD_CODE[4]==9)&&(BCD_CODE[5]==9)&&(stSysParameter.C_Parameter[2]!=6))
    {
        if((wt_poly<49.2)&&(display_data>20))
        {

            if(BCD_CODE[7] == 9)
            {
                if(Revise_Parameters == 1)
                {
                    display_data=display_data+1;
                }
                else
                    Revise_Parameters = 1;
            }
            else if(BCD_CODE[7] == 8)
            {
                if(Revise_Parameters == 2)
                {
                    display_data=display_data+2;
                }
                else  if(Revise_Parameters == 1)
                {
                    display_data=display_data+1;
                    Revise_Parameters = 2;
                }
                else
                    Revise_Parameters = 1;
            }
            else
            {
                display_data=display_data+2;
            }
        }
        else if((wt_poly>49.2)&&(wt_poly<122.2))
        {
            if(BCD_CODE[7] == 9)
            {
                if(Revise_Parameters == 1)
                {
                    display_data=display_data+1;
                }
                else
                    Revise_Parameters = 1;
            }
            else if(BCD_CODE[7] == 8)
            {
                if(Revise_Parameters == 2)
                {
                    display_data=display_data+2;
                }
                else  if(Revise_Parameters == 1)
                {
                    display_data=display_data+1;
                    Revise_Parameters = 2;
                }
                else
                    Revise_Parameters = 1;
            }
            else if(BCD_CODE[7] == 7)
            {
                if(Revise_Parameters == 3)
                {
                    display_data=display_data+3;
                }
                else if(Revise_Parameters == 2)
                {
                    display_data=display_data+2;
                    Revise_Parameters = 3;
                }
                else  if(Revise_Parameters == 1)
                {
                    display_data=display_data+1;
                    Revise_Parameters = 2;
                }
                else
                    Revise_Parameters = 1;
            }
            else
            {
                display_data=display_data+2;
            }

        }
        else if((wt_poly>122.2)&&(wt_poly<182.2))
        {
            if(BCD_CODE[7] == 9)
            {
                if(Revise_Parameters == 1)
                {
                    display_data=display_data+1;
                }
                else
                    Revise_Parameters = 1;
            }
            else if(BCD_CODE[7] == 8)
            {
                if(Revise_Parameters == 2)
                {
                    display_data=display_data+2;
                }
                else  if(Revise_Parameters == 1)
                {
                    display_data=display_data+1;
                    Revise_Parameters = 2;
                }
                else
                    Revise_Parameters = 1;
            }
            else if(BCD_CODE[7] == 7)
            {
                if(Revise_Parameters == 3)
                {
                    display_data=display_data+3;
                }
                else if(Revise_Parameters == 2)
                {
                    display_data=display_data+2;
                    Revise_Parameters = 3;
                }
                else  if(Revise_Parameters == 1)
                {
                    display_data=display_data+1;
                    Revise_Parameters = 2;
                }
                else
                    Revise_Parameters = 1;
            }
            else if(BCD_CODE[7] == 6)
            {
                if(Revise_Parameters == 4)
                {
                    display_data=display_data+4;
                }
                else if(Revise_Parameters == 3)
                {
                    display_data=display_data+3;
                    Revise_Parameters = 4;
                }
                else if(Revise_Parameters == 2)
                {
                    display_data=display_data+2;
                    Revise_Parameters = 3;
                }
                else  if(Revise_Parameters == 1)
                {
                    display_data=display_data+1;
                    Revise_Parameters = 2;
                }
                else
                    Revise_Parameters = 1;
            }
            else
            {
                display_data=display_data+2;
            }
        }
        else if((wt_poly>182.2)&&(wt_poly<222.2))
        {
            if(BCD_CODE[7] == 9)
            {
                if(Revise_Parameters == 1)
                {
                    display_data=display_data+1;
                }
                else
                    Revise_Parameters = 1;
            }
            else if(BCD_CODE[7] == 8)
            {
                if(Revise_Parameters == 2)
                {
                    display_data=display_data+2;
                }
                else  if(Revise_Parameters == 1)
                {
                    display_data=display_data+1;
                    Revise_Parameters = 2;
                }
                else
                    Revise_Parameters = 1;
            }
            else if(BCD_CODE[7] == 7)
            {
                if(Revise_Parameters == 3)
                {
                    display_data=display_data+3;
                }
                else if(Revise_Parameters == 2)
                {
                    display_data=display_data+2;
                    Revise_Parameters = 3;
                }
                else  if(Revise_Parameters == 1)
                {
                    display_data=display_data+1;
                    Revise_Parameters = 2;
                }
                else
                    Revise_Parameters = 1;
            }
            else if(BCD_CODE[7] == 6)
            {
                if(Revise_Parameters == 4)
                {
                    display_data=display_data+4;
                }
                else if(Revise_Parameters == 3)
                {
                    display_data=display_data+3;
                    Revise_Parameters = 4;
                }
                else if(Revise_Parameters == 2)
                {
                    display_data=display_data+2;
                    Revise_Parameters = 3;
                }
                else  if(Revise_Parameters == 1)
                {
                    display_data=display_data+1;
                    Revise_Parameters = 2;
                }
                else
                    Revise_Parameters = 1;
            }
            else if(BCD_CODE[7] == 5)
            {
                if(Revise_Parameters == 5)
                {
                    display_data=display_data+5;
                }
                else if(Revise_Parameters == 4)
                {
                    display_data=display_data+4;
                    Revise_Parameters = 5;
                }
                else if(Revise_Parameters == 3)
                {
                    display_data=display_data+3;
                    Revise_Parameters = 4;
                }
                else if(Revise_Parameters == 2)
                {
                    display_data=display_data+2;
                    Revise_Parameters = 3;
                }
                else  if(Revise_Parameters == 1)
                {
                    display_data=display_data+1;
                    Revise_Parameters = 2;
                }
                else
                    Revise_Parameters = 1;
            }
            else
            {
                display_data=display_data+2;
            }
        }
    }
    else
    {
        Revise_Parameters = 0;
    }
    if((BCD_CODE[1]==0)&&(BCD_CODE[2]==0)&&(BCD_CODE[3]==0)&&(BCD_CODE[4]==0)&&(BCD_CODE[5]==0)&&(BCD_CODE[6]==0)&&(BCD_CODE[7]==0))
    {
        display_data = 0;
    }

    MODE_DATA_PROCESS(display_data,Mode_Type,unit_pcs_percent,COUNT_WEIGHT_DAT,PERCENT_WEIGHT_DAT);
    //-----------------------------------工厂测试数据-----------------------
    if(stSysParameter.C_Parameter[2]==6)
    {
        if(Mode_Type==0)
        {
            RESULT1_DAT=wt_tarack*10000;
        }
        else if(Mode_Type==1)
        {
//		 RESULT1_DAT =display_data;
            RESULT1_DAT=count_h1*256+count_l;
//			RESULT1_DAT=count_data/10000;
        }
        else if(Mode_Type==2)
        {
            RESULT1_DAT=wt_poly*10000;
        }
        else if(Mode_Type==3)
        {
            RESULT1_DAT=wt_zero_flag*10000;
        }
        else
        {
            RESULT1_DAT=stable_count;
            //RESULT1_DAT=count_data%10000;
        }
    }
    //-------------------------------------------------------------------------------
    else
    {
        //RESULT1_DAT =display_data;
			  if(Mode_Type==0)
        {
            RESULT1_DAT=wt_tarack*10000;
        }
        else if(Mode_Type==1)
        {
//		 RESULT1_DAT =display_data;
            RESULT1_DAT=count_h1*256+count_l;
//			RESULT1_DAT=count_data/10000;
        }
        else if(Mode_Type==2)
        {
            RESULT1_DAT=wt_poly*10000;
        }
        else if(Mode_Type==3)
        {
            RESULT1_DAT=wt_zero_flag*10000;
        }
        else
        {
            RESULT1_DAT=stable_count;
            //RESULT1_DAT=count_data%10000;
        }
    }

    //RESULT1_DAT=count_data/100;
    n=RESULT1_DAT/10000000;
    RESULT1_DAT=RESULT1_DAT % 10000000;
    BCD_CODE[0]=n;
    n=RESULT1_DAT/1000000;
    RESULT1_DAT=RESULT1_DAT % 1000000;
    BCD_CODE[1]=n;
    n=RESULT1_DAT/100000;
    RESULT1_DAT=RESULT1_DAT % 100000;
    BCD_CODE[2]=n;
    n=RESULT1_DAT/10000;
    RESULT1_DAT=RESULT1_DAT % 10000;
    BCD_CODE[3]=n;
    n=RESULT1_DAT/1000;
    RESULT1_DAT=RESULT1_DAT % 1000;
    BCD_CODE[4]=n;
    n=RESULT1_DAT/100;
    RESULT1_DAT=RESULT1_DAT % 100;
    BCD_CODE[5]=n;
    n=RESULT1_DAT/10;
    RESULT1_DAT=RESULT1_DAT % 10;
    BCD_CODE[6]=n;
    n=RESULT1_DAT;
    BCD_CODE[7]=n;//长整型转字符串

    if(BCD_CODE[0]==1)
    {
        dis_num[0] |= 0x04;
    }
    else
    {
        dis_num[0] &= 0xfb;
    }
//    if(DOT_POSITION[Mode_Type]==0)
//    {
//        dis_num[0] |= 0x08;
//    }
    for(i=1; i<8; i++)
    {
        if(i<DOT_POSITION[Mode_Type])
        {
            if(zero_flag)
            {
                dis_num[i]=LCD1_seg[BCD_CODE[i]];
            }
            else
            {
                if(BCD_CODE[i]!=0||((dis_num[0]&0x02)!=0))
                {
                    dis_num[i]=LCD1_seg[BCD_CODE[i]];
                    zero_flag=0xFF;
                }
                else	dis_num[i]=0;
            }
        }
        else if(i==DOT_POSITION[Mode_Type])
            dis_num[i]=LCD1_seg[BCD_CODE[i]] | 0x08;
        else
            dis_num[i]=LCD1_seg[BCD_CODE[i]];
    }
}
