#include "common.h"
#include "flash.h"

SysParameter stSysParameter;
SysParameterApp stSysParameterApp;

FL_TYPE hh; 
dFL_TYPE ff;

void M24C64_Read(uint16_t Reg_Addr, uint8_t *pSrc, uint16_t number)
{
	  HAL_I2C_Mem_Read( &hi2c1, ADDR_M24C64_Write, Reg_Addr, I2C_MEMADD_SIZE_16BIT,pSrc,number,1000 ) ;	
}

void  M24C64_Write(uint16_t Reg_Addr, uint8_t *pSrc, uint16_t number)
{

	HAL_I2C_Mem_Write( &hi2c1, ADDR_M24C64_Write, Reg_Addr, I2C_MEMADD_SIZE_16BIT,pSrc, number, 1000 ) ;

}

void M24C64_Write_float(uint16_t Reg_Addr, float pSrc)
{
	hh.x=pSrc;
	HAL_I2C_Mem_Write( &hi2c1, ADDR_M24C64_Write, Reg_Addr, I2C_MEMADD_SIZE_16BIT, hh.s, 4, 1000 );   
	HAL_Delay(100);
}
void M24C64_Write_double(uint16_t Reg_Addr, double pSrc)
{
	ff.f=pSrc;
	HAL_I2C_Mem_Write( &hi2c1, ADDR_M24C64_Write, Reg_Addr, I2C_MEMADD_SIZE_16BIT,  ff.ds, 8, 1000 );  
	HAL_Delay(100);
}
float M24C64_Read_float(uint16_t Reg_Addr)
{
	HAL_I2C_Mem_Read( &hi2c1, ADDR_M24C64_Write, Reg_Addr, I2C_MEMADD_SIZE_16BIT, hh.s, 4, 1000 );  
	return hh.x;
}
double M24C64_Read_double(uint16_t Reg_Addr)
{
	HAL_I2C_Mem_Read( &hi2c1, ADDR_M24C64_Write, Reg_Addr, I2C_MEMADD_SIZE_16BIT,  ff.ds, 8, 1000 );
	//ff.ds[7] = ff.ds[7] & 0x10;
	//if((ff.ds[0]==0xff) && (ff.ds[1]==0xff) && (ff.ds[2]==0xff) && (ff.ds[3]==0xff) && (ff.ds[4]==0xff) && (ff.ds[5]==0xff) && (ff.ds[6]==0xff))
	//{
	//		ff.f = 1000001;
	//}
	if((ff.f < 1000001) && (ff.f > -1000001))
	{}
	else
		ff.f = 1000001;
	return ff.f;
}

void INTflash(void)
{
	//	uint16_t i;
		//读第一组线性系数
		stSysParameterApp.p1[0]=M24C64_Read_double(pl_aADD);
		if(stSysParameterApp.p1[0] >100000)
		{
			stSysParameterApp.p1[0] = -1.51939531616E-17;
		}

		stSysParameterApp.p1[1]=M24C64_Read_double(pl_bADD);
		if(stSysParameterApp.p1[1] >100000)
		{
			stSysParameterApp.p1[1] = 5.502797156602E-12;
		}
		stSysParameterApp.p1[2]=M24C64_Read_double(pl_cADD);
		if(stSysParameterApp.p1[2] >100000)
		{
			stSysParameterApp.p1[2] = 0.000254942844395;
		}

		stSysParameterApp.p1[3]=M24C64_Read_double(pl_dADD);
		if(stSysParameterApp.p1[3] >100000)
		{
			stSysParameterApp.p1[3] = -8.679135140817f;
		}
		//stSysParameterApp.p1[4]=M24C64_Read_double(pl_eADD);
		stSysParameterApp.p1[4]=M24C64_Read_double(pl_eADD);
		if(stSysParameterApp.p1[4] >100000) 
		{
			//stSysParameterApp.p1[4] = -1.51939531616E-17;
		}
		//读取第二组线性系数
		stSysParameterApp.p2[0]=M24C64_Read_double(p2_aADD);
		if(stSysParameterApp.p2[0] >100000)
		{
			stSysParameterApp.p2[0] = -1.51939531616E-17;
		}

		stSysParameterApp.p2[1]=M24C64_Read_double(p2_bADD);
		if(stSysParameterApp.p2[1] >100000)
		{
			stSysParameterApp.p2[1] = 5.502797156602E-12;
		}
		stSysParameterApp.p2[2]=M24C64_Read_double(p2_cADD);
		if(stSysParameterApp.p2[2] >100000)
		{
			stSysParameterApp.p2[2] = 0.000254942844395;
		}

		stSysParameterApp.p2[3]=M24C64_Read_double(p2_dADD);
		if(stSysParameterApp.p2[3] >100000)
		{
			stSysParameterApp.p2[3] = -8.679135140817f;
		}
		//stSysParameterApp.p1[4]=M24C64_Read_double(pl_eADD);
		stSysParameterApp.p2[4]=M24C64_Read_double(p2_eADD);
		if(stSysParameterApp.p2[4] >100000) 
		{
			stSysParameterApp.p1[4] = -1.51939531616E-17;
		}
		
		stSysParameter.wt_span=M24C64_Read_double(wt_spanADD);
		if(stSysParameter.wt_span >100000)
		{
			stSysParameter.wt_span = 1;
		}

		stSysParameter.wt_tare=0;
		
		M24C64_Read(SaveSetUPGenserADD,stSysParameter.C_Parameter,13);
		if(stSysParameter.C_Parameter[0] > 2)
			stSysParameter.C_Parameter[0] = 1;

		if(stSysParameter.C_Parameter[1] > 4)
			stSysParameter.C_Parameter[1] = 0;

		if(stSysParameter.C_Parameter[2] > 6)
			stSysParameter.C_Parameter[2] = 2;

		if(stSysParameter.C_Parameter[3] > 3)
			stSysParameter.C_Parameter[3] = 3;

		if(stSysParameter.C_Parameter[4] > 4)
			stSysParameter.C_Parameter[4] = 3;

		if(stSysParameter.C_Parameter[5] > 6)
			stSysParameter.C_Parameter[5] = 3;

		if(stSysParameter.C_Parameter[6] > 3)
			stSysParameter.C_Parameter[6] = 0;

		if(stSysParameter.C_Parameter[7] > 3)
			stSysParameter.C_Parameter[7] = 2;
		if(stSysParameter.C_Parameter[8] > 9)
			stSysParameter.C_Parameter[8] = 0;
		//M24C64_Write(SaveSetUPBalanceADD,stSysParameter.C_Parameter,13);
		stSysParameterApp.zero = zero_index[stSysParameter.C_Parameter[2]];				//零点数据
		stSysParameterApp.baud = baud_value[stSysParameter.C_Parameter[3]];				//串口波特率
		stSysParameterApp.print_time = print_time_table[stSysParameter.C_Parameter[5]];
		stSysParameterApp.filter_value = filter_count_table[stSysParameter.C_Parameter[7]];
		stSysParameterApp.filter_count = filter_count_table[stSysParameter.C_Parameter[7]];
		stSysParameterApp.auto_time = auto_time_table[stSysParameter.C_Parameter[6]];
		//M24C64_Read(SaveSetUPBalanceADD,stSysParameter.C_Parameter,13);
		stSysParameterApp.add_200g_parameter = stSysParameter.C_Parameter[8];
		
		stSysParameterApp.weigh_mode = 1;
		stSysParameterApp.weigh_unit = 0;
		stSysParameterApp.weigh_language = 0;
		stSysParameterApp.weigh_state = 0;
		stSysParameterApp.Diplay_Interface_Page = 0;
		stSysParameterApp.blance_state = 1;
		stSysParameterApp.zero_time = 0;
		stSysParameterApp.lcd_time = 30;
		stSysParameterApp.sencond_set = 0;
}

