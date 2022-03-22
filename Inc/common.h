#ifndef __COMMON_H
#define	__COMMON_H

#include "stm32h7xx_hal.h"
#include "stm32h7xx_hal_adc.h"
#include "stm32h7xx_hal_i2c.h"
#include "stm32h7xx_hal_spi.h"
#include "stm32h7xx_hal_uart.h"
#include "stm32h7xx_hal_adc.h"

#define        FM25CL64_WREN                0x06                //设置写使能锁存器
#define        FM25CL64_WRDI                0x04                //写禁止
#define        FM25CL64_RDSR                0x05                //读状态寄存器
#define        FM25CL64_WRSR                0x01                //写状态寄存器
#define        FM25CL64_READ                0x03                //读存储器数据
#define        FM25CL64_WRITE        		0x02                //写存储器数据

//系统配置参数存储地址
#define pl_aADD              0//pl_a系数存储地址
#define pl_bADD              pl_aADD+8//pl_b系数存储地址
#define pl_cADD              pl_bADD+8//pl_c系数存储地址
#define pl_dADD              pl_cADD+8//pl_d系数存储地址
#define pl_eADD              pl_dADD+8//pl_e系数存储地址
#define p2_aADD              pl_eADD+8//pl_a系数存储地址
#define p2_bADD              p2_aADD+8//pl_b系数存储地址
#define p2_cADD              p2_bADD+8//pl_c系数存储地址
#define p2_dADD              p2_cADD+8//pl_d系数存储地址
#define p2_eADD              p2_dADD+8//pl_e系数存储地址
#define wt_spanADD           p2_eADD+8//wt_span系数存储地址
#define wt_zeroADD           wt_spanADD+8//wt_zero系数存储地址
#define span_wtADD           wt_zeroADD+8//span_wt系数存储地址

#define SaveSetUPGenserADD             span_wtADD+13//C参数存储连续13个uint8_t

//系统配置默认值
#define SYS_COM_ADR                       1//默认通讯地址
//按键值枚举
typedef enum
{
  KEY_NULL = 0x00,
	KEY_CAL,
	KEY_MODE,
	KEY_SET,
	KEY_TARE,
	KEY_POWER,
	KEY_PRINT
} KEYCmd;

typedef struct _Sys_Parameter
{
		uint8_t C_Parameter[13];

		double 	pl_a;
		double 	pl_b;
		double	pl_c;
		double	pl_d;
		double	pl_e;
		double 	p2_a;
		double 	p2_b;
		double	p2_c;
		double	p2_d;
		double	p2_e;
		double 	wt_span;
		double	wt_tare;
		double	wt_zero;
}SysParameter;

typedef struct _Sys_Parameter_App
{
		uint8_t stCal_Mode;			
		uint8_t stCal_Stable;			//校验步骤
		uint8_t stStable_count;
		uint32_t stStable_line;//新称重计数值
		uint32_t stCount;				//前次当前校验重量
		uint32_t stCount_data;	//当前校验重量
		double 	stfirst;				//第一组校准系数
		double stSecond;				//第二组校准系数
		double wt_zero_flag;
		double wt_poly;					//当前重量值(g)
		double wt_poly1;				//记忆重量值(g)
		double wt_tare_add;			//称重加数据
		double wt_tarack;				//微量调整
		double wt_last;
		uint8_t wt_ok;					//称重完成
    uint8_t cal_span_count;	//校验计数器
    uint8_t cal_span_error;	//校验错误
		uint8_t wt_over;				//超重
		uint8_t zero_num;
		uint32_t baud;
		double zero;
		uint8_t add_200g_parameter;
		double zw;							//
		uint8_t stable_not_num;
		uint8_t wt_stable;
		uint32_t print_time;
		uint8_t wt_low;
		float filter_value;
		float wt_sp[150];
		uint16_t stable_count;//CPLD数值稳定性计数值  初判断值
		uint16_t stable_count1;//CPLD数值稳定性计数值  终值
		uint16_t wt_filter_flag;//数据滤波处理稳定性计数值    初判断值
		uint16_t wt_filter_flag1;//数据滤波处理稳定性计数值   终值
		uint16_t filter_count;//滤波数组窗口
		uint32_t auto_time;
		uint8_t weigh_mode;//称重状态 1称重  0未称重
		uint8_t weigh_unit;//0 g/克  1 mg/毫克  2  ct 克拉，3 lb  英镑，4  oz/盎司
		uint8_t weigh_language;// 0, 汉语   1；英语
		uint8_t weigh_state;	//0,稳定  1，超重  2，低重
		uint8_t Diplay_Interface_Page;//工作页面 0,称重页面 
		uint8_t blance_state;//屏幕点亮1   屏幕不亮0
		double p1[6];					//第一维系数
		double p2[6];					//第二维洗刷
		float count_data1;		//数据
		uint32_t display_data;	//显示重量
		uint8_t count_h1;
		uint8_t count_l;
		//double wt_zero_flag;
		//uint32_t stable_count;
		double stable_data;
		uint8_t unit_pcs_percent;
		uint32_t COUNT_WEIGHT_DAT;
		uint32_t PERCENT_WEIGHT_DAT;
		uint32_t count_sum;			//重量值累计
		uint8_t  get_wt;				//次数计算
		uint32_t  count_data;
		double data_sp1[10];
		double data_sp[300];
		uint8_t lcd_time_flag;
		uint32_t zero_time;
		uint32_t lcd_time;		//显示平亮灭时间控制
		uint32_t sencond_set;
		double wt_tare;
		float cal_sum;
		//double wt_tare_add;
		//uint8_t stable_not_num;
}SysParameterApp;
extern uint8_t   LCD_seg_FUNCT[];
extern SysParameter stSysParameter;
extern SysParameterApp stSysParameterApp;

extern UART_HandleTypeDef huart2,huart3,huart4,huart5,huart6,huart7,huart8;//串口
extern ADC_HandleTypeDef             AdcHandle;	//ADC端口
extern ADC_ChannelConfTypeDef        sConfig;		//ADC通道配置
extern I2C_HandleTypeDef 							hi2c1;		//存储flash接口
extern SPI_HandleTypeDef hspi6;

extern float  zero_index[7];
extern uint32_t baud_value[7];
extern uint32_t print_time_table[7];
extern uint16_t filter_count_table[7];
extern uint32_t auto_time_table[7];

void Error_Handler(void);
void INTflash(void);
uint8_t Display_Num_LCD(uint8_t num);//字符转LCD显示
uint8_t KEY_ADC_Value(void);
void Function_Selection(void);
extern void Lcd_Dispay_Process(uint8_t p[]);

void units_LONG_TO_disSEG(uint32_t display_data,uint8_t *dis_num,double wt_poly,uint8_t Mode_Type,
													double wt_tarack,double count_h1,double count_l,double wt_zero_flag,
														uint32_t stable_count,uint32_t stable_data,
													uint8_t unit_pcs_percent,uint32_t COUNT_WEIGHT_DAT,uint32_t PERCENT_WEIGHT_DAT);
double wt_line(double count_data1,double *p1,double *p2);
void Lcd_Dispay_Menu(uint8_t p[]);
void  M24C64_Write(uint16_t Reg_Addr, uint8_t *pSrc, uint16_t number);
void M24C64_Write_float(uint16_t Reg_Addr, float pSrc);
void M24C64_Write_double(uint16_t Reg_Addr, double pSrc);
void Send_Modbus_Buf(uint8_t Device_address,
											uint8_t Function_code,
											uint16_t First_Adress,
											uint16_t Number_of_registers,
											uint8_t Number,
											uint8_t *dat);
void Display_Cal_Page(uint8_t KEY_Cmd);
void Display_Cal_In_Page(uint8_t KEY_Cmd);
void Display_Cal_Span_Page(uint8_t KEY_Cmd);
void tare(void);
void wt_filter(void);
void wt_track(void);
void Display_Weight_Interface(void);
void Lcd_On_off_function(void);
void Display_Cal_Ex_Page(uint8_t KEY_Cmd);
#endif
