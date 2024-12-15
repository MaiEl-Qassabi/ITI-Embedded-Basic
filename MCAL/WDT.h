/*
 * WDT.h
 *
 *  Created on: Sep 2, 2023
 *      Author: Egypt_Laptop
 */

#ifndef MCAL_WDT_H_
#define MCAL_WDT_H_


#include <avr/io.h>
#include"../StdTypes.h"
#include"../Utils.h"

typedef enum {
	timeOut_16ms,
	timeOut_32ms,
	timeOut_65ms,
	timeOut_130ms,
	timeOut_260ms,
	timeOut_520ms,
	timeOut_1000ms,
	timeOut_2100ms,
}TimeOut_type;

void WDT_set(TimeOut_type time);
void WDT_stop(void);

#endif /* MCAL_WDT_H_ */
