/*
 * WDT.c
 *
 *  Created on: Sep 2, 2023
 *      Author: Egypt_Laptop
 */

#include"WDT.h"
#include <avr/io.h>
#include"../StdTypes.h"
#include"../Utils.h"

void WDT_set(TimeOut_type time)
{
	u8 wdt_value=0x08;              //WDE SET && WDTOE CLEAR 0000 1000
	wdt_value|=time;               // 0000 1011
	WDTCR=wdt_value;
}


void WDT_stop(void)
{
	WDTCR|=(1<<WDE)|(1<<WDTOE);
	WDTCR=0;

}
