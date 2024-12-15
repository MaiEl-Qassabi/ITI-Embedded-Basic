/*
 * sensor.h
 *
 *  Created on: Sep 5, 2023
 *      Author: Egypt_Laptop
 */

#ifndef MCAL_SENSOR_H_
#define MCAL_SENSOR_H_
#include"../StdTypes.h"
#include"../Utils.h"
#include"ADC.h"

#define LM_35  CH_0

u16 Temp_Read (void);

#endif /* MCAL_SENSOR_H_ */
