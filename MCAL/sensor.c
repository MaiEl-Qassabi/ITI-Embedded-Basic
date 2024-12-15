/*
 * sensor.c
 *
 *  Created on: Sep 5, 2023
 *      Author: Egypt_Laptop
 */


#include "sensor.h"


u16 Temp1_Read (void) // return degree
{
	u16 adc = ADC_ReadVolt (LM_35);  // return mv

	u16 temp =adc/10; // if u want return correct degree don't multiply of 10

	return temp;
}
