#ifndef __FLASH_H
#define	__FLASH_H

#include "stdint.h"

#define ADDR_M24C64_Write     0xA0  //写指令IIC地址


//extern uint8_t g_DM_DisplayMode; // DEF,OFF,TXT
//extern uint8_t g_PWR;            // on/off
//extern uint8_t serial_number_buffer[12];
//extern uint8_t serial_number_length;
float  zero_index[7]= {0.00002,0.00015,0.00025,0.00035,0.00045,0.00055,0};
uint32_t baud_value[7]= {1200,2400,4800,9600,115200};
uint32_t print_time_table[7]= {357,714,1428,2142,2856,3570};
uint16_t filter_count_table[7]= {20,50,80,120};//滤波累加值计算配置数组 环境稳定性不同累加值不同
uint32_t auto_time_table[7]= {1800,3600,5400,7200,28800};

void MX_I2C3_Init(void);//
__packed typedef union  
{    
float x; 
uint8_t s[4];   
}FL_TYPE; 

__packed typedef union  
{    
double f; 
uint8_t ds[8];   
}dFL_TYPE; 


#endif
