
#include <stdint.h>
#include "modbus.h"
#include "stm32h7xx_hal.h"

extern UART_HandleTypeDef huart3,huart5,huart6;
/*
�������ƣ�pro_crc16
�������ܣ��ַ�����crcУ�鲢����У����
�������룺uint8_t *dat�ַ�������
					uint8_t	num�ַ�������
���������uint16_t ʮ��λУ����
*/
uint16_t pro_crc16(uint8_t *dat, uint8_t num)
{
  uint8_t ram_crc_l=0xff,ram_crc_h=0xff;
  uint16_t temp;
  while (num--)
  {
    temp=ram_crc_l ^ *dat++;
    ram_crc_l=ram_crc_h ^ tab_crc16h[temp];
    ram_crc_h=tab_crc16l[temp];
  }
  return (ram_crc_l<<8|ram_crc_h);
}
/*
�������ƣ�Send_Modbus_Buf
�������ܣ�����MODBUS���ݵ��ӻ�
�������룺uint8_t Device_address,			�ӵ�ַ
					uint8_t Function_code,			������
					uint16_t First_Adress,			��ʼ��ַ
					uint16_t Number_of_registers,	��ַ����
					uint8_t Number,							���ݸ���
					uint8_t *dat								��������
�����������
*/
void Send_Modbus_Buf(uint8_t Device_address,
											uint8_t Function_code,
											uint16_t First_Adress,
											uint16_t Number_of_registers,
											uint8_t Number,
											uint8_t *dat)
{
	static uint8_t send_buf[256];
	uint8_t i;
	uint16_t crc;
	//static uint8_t send_temp_number;
	//static uint8_t temp_number;
	
	//temp_number = Number;
	
	send_buf[0] = Device_address;
	send_buf[1] = Function_code;
	send_buf[2] = (First_Adress >> 8) & 0xff;
	send_buf[3] = (First_Adress) & 0xff;
	send_buf[4] = (Number_of_registers >> 8) & 0xff;
	send_buf[5] = Number_of_registers & 0xff;
	send_buf[6] = Number;
	for(i = 0;i < Number;i ++)
		send_buf[7 + i] = dat[i];
	crc = pro_crc16(send_buf,7 + Number);
	//send_temp_number = 8;//7 + temp_number;
	send_buf[7 + Number] = (crc >> 8) & 0xff;
	//send_temp_number = 9;//8 + temp_number;
	send_buf[8+ Number] = crc & 0xff;
	//send_buf[temp] = 
	
	HAL_UART_Transmit_IT(&huart5,(uint8_t*)send_buf,9 + Number);
}
