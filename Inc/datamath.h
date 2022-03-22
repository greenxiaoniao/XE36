#ifndef __DATAMATH_H
#define	__DATAMATH_H

#include "stdint.h"

float  unit_para[]= {1,28.3495231,0.2,453.7205,11.6638038,1,1};
float  unit_para_b[]= {1,100,1,100,10,1,1};
float	 COUNT_UNITS[]= {10,20,50,100,1000};
uint8_t Revise_Parameters;
char DOT_POSITION[] = {3,1,3,1,7,5,2};
char LCD1_seg[10]= {0xd7,0x06,0xe3,0xa7,0x36,0xb5,0xf5,0x07,0xf7,0xb7};
void units_LONG_TO_disSEG(uint32_t display_data,uint8_t *dis_num,double wt_poly,uint8_t Mode_Type,double wt_tarack,double count_h1,double count_l,double wt_zero_flag,uint32_t stable_count,uint32_t stable_data,uint8_t unit_pcs_percent,uint32_t COUNT_WEIGHT_DAT,uint32_t PERCENT_WEIGHT_DAT);
#endif
