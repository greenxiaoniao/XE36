#include "common.h"
#include "Lcd.h"

uint8_t MAX_RANGE[3] = {2,2,0};
uint8_t MIN_RANGE[2] = {0,1};

void Lcd_Delay(uint32_t ui32Count)
{
    while(ui32Count--);
}

void Lcd_Int(void)
{
    HAL_GPIO_WritePin(GPIOE, LCD_WR_Pin, GPIO_PIN_RESET);
    Lcd_Delay(20);
    HAL_GPIO_WritePin(GPIOE, LCD_WR_Pin, GPIO_PIN_RESET);
    Lcd_Delay(20);
}

void Lcd_Send_Buf(uint8_t id,uint8_t n)
{
    uint8_t i;
    for(i=0; i<n; i++)
    {
        if(id>=0x80)
            HAL_GPIO_WritePin(GPIOE, LCD_DATA_Pin, GPIO_PIN_SET);
        else
            HAL_GPIO_WritePin(GPIOE, LCD_DATA_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOE, LCD_WR_Pin, GPIO_PIN_SET);
        Lcd_Delay(20);
        HAL_GPIO_WritePin(GPIOE, LCD_WR_Pin,GPIO_PIN_RESET);
        Lcd_Delay(20);
        id<<=1;
    }
}

void Lcd_Send_Commond(uint8_t command)
{
    uint8_t a=0x80,i=4,d=8;
    HAL_GPIO_WritePin(GPIOE, LCD_CS_Pin, GPIO_PIN_RESET);
    Lcd_Send_Buf(a,i);
    Lcd_Send_Buf(command,d);// 4+8 bit command
    HAL_GPIO_WritePin(GPIOE, LCD_CS_Pin, GPIO_PIN_SET);
}
void Lcd_INT1621(void)
{
    uint8_t command;
    HAL_GPIO_WritePin(GPIOE, LCD_CS_Pin, GPIO_PIN_RESET);
    Lcd_Int();

    Lcd_Delay(20);
    command=BIAS;
    Lcd_Send_Commond(command);
    //command=RC256;
    //sendcom(command);
    command=SYSTEN;
    Lcd_Send_Commond(command);
    command=LCDON;
    Lcd_Send_Commond(command);
    HAL_GPIO_WritePin(GPIOE, LCD_DATA_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOE, LCD_WR_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOE, LCD_CS_Pin, GPIO_PIN_SET);
}
void Lcd_Send_1621data(uint8_t p[],uint8_t num)
{
    uint8_t j,k;
    HAL_GPIO_WritePin(GPIOE, LCD_CS_Pin, GPIO_PIN_RESET);
    Lcd_Int();
    Lcd_Send_Buf(0xa0,3);
    Lcd_Send_Buf(0,6);   //101000000
    for(j=0; j<num; j++)
    {
        k=p[j];
        Lcd_Send_Buf(k,8);
    }
    HAL_GPIO_WritePin(GPIOE, LCD_CS_Pin, GPIO_PIN_SET);
}
void LCD_DISPAY_CHANGE(uint8_t p[],uint8_t num)
{
    Lcd_INT1621();
    Lcd_Send_1621data(p,num);
}

void Lcd_Display_Range(uint8_t *buf)
{
	uint8_t temp;
	
	buf[15] = 0x80;			//S6
	buf[12] = 0x80;			//S7
	temp = Display_Num_LCD(MAX_RANGE[0]);
	buf[12] |= (temp >> 4);
	buf[13] |= ((temp & 0x0f) << 4);
	temp = Display_Num_LCD(MAX_RANGE[1]);
	buf[13] |= (temp >> 4);
	buf[14] |= ((temp & 0x0f) << 4);
	temp = Display_Num_LCD(MAX_RANGE[2]);
	buf[14] |= (temp >> 4);
	buf[15] |= ((temp & 0x0f) << 4);
	temp = Display_Num_LCD(MIN_RANGE[0]);
	buf[10] |= (temp >> 4);
	buf[11] |= ((temp & 0x0f) << 4);
	temp = Display_Num_LCD(MIN_RANGE[1]);
	buf[11] |= (temp >> 4);
	buf[12] |= ((temp & 0x0f) << 4);
}

void Lcd_Display_Uint(uint8_t *buf)
{
	switch(stSysParameterApp.weigh_unit)
	{
			case 0:
					buf[9] |= 0x20;
					buf[9] |= 0x01;
					break;
			case 1:
          buf[9] |= 0x80;
          buf[9] |= 0x01;
					break;
			case 2:
					buf[9] |= 0x08;
					buf[9] |= 0x01;
					break;
			case 3:
					buf[9] |= 0x10;
					buf[9] |= 0x01;
					break;
			case 4:
					buf[8] = 0x80;
					buf[10] |= 0x10;
					break;
			case 5:
          buf[8] |= 0x08;
          buf[10] |= 0x20;				
				break;
			default:
					break;
	}
}

void Lcd_Display_State(uint8_t *buf)
{
	switch(stSysParameterApp.weigh_state)
	{
		case 0://ÎÈ¶¨
			buf[0] |= 0x02;
			break;
		case 1://³¬ÖØ
			buf[0] |= 0x10;
			break;
		case 2://µÍÖØ
			buf[0] |= 0x01;
			break;
		default:
			break;
	}
}
	
void Lcd_Dispay_Process(uint8_t p[])
{
	uint8_t buf[16] = {0},i;
	
	for(i = 1;i < 8;i ++)
	{
		buf[i] = p[i];
	}
	if(stSysParameterApp.weigh_mode == 1)
	{
		if(buf[1] == 0xD7)
			buf[1] = 0x0;
		if((buf[2] == 0xD7) && (buf[1] == 0x0))
			buf[2] = 0x0;
		if((buf[3] == 0xD7) && (buf[1] == 0x0)&& (buf[2] == 0x0))
			buf[3] = 0x0;
		if((buf[4] == 0xD7) && (buf[1] == 0x0)&& (buf[2] == 0x0)&& (buf[3] == 0x0))
			buf[4] = 0x0;
		if((buf[5] == 0xD7) && (buf[1] == 0x0) && (buf[2] == 0x0)&& (buf[3] == 0x0)&& (buf[4] == 0x0))
			buf[5] = 0x0;
		if((buf[6] == 0xD7) && (buf[1] == 0x0) && (buf[2] == 0x0)&& (buf[3] == 0x0)&& (buf[4] == 0x0)&& (buf[5] == 0x0))
			buf[6] = 0x0;
		Lcd_Display_Range(buf);
		Lcd_Display_Uint(buf);
		Lcd_Display_State(buf);
	}
  LCD_DISPAY_CHANGE(buf,16);
}

void Lcd_Dispay_Menu(uint8_t p[])
{
//	uint8_t buf[16] = {0},i;
	
  LCD_DISPAY_CHANGE(p,16);
}

void MX_Lcd_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
	GPIO_InitStruct.Pin = GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
		//HAL_Delay(100);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14, GPIO_PIN_SET);
}

void Lcd_On_off_function(void)
{
	if(stSysParameterApp.blance_state == 1)
	{
			if(stSysParameterApp.lcd_time==0)			
			{
				HAL_GPIO_WritePin(GPIOC, LCD_LIGHT_Pin, GPIO_PIN_RESET);
			}
			else if(stSysParameterApp.lcd_time!=0)
			{
			 HAL_GPIO_WritePin(GPIOC, LCD_LIGHT_Pin, GPIO_PIN_SET);
			}
	}
}

