/*
 * Stepper.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Egypt_Laptop
 */

#ifndef HAL_STEPPER_H_
#define HAL_STEPPER_H_

/*************cfg************/
#define COIL1A    PINA00
#define COIL1B    PINA01
#define COIL2A    PINA02
#define COIL2B    PINA03



/***************************/

void STEPPER_Bipolar_CW(void);
void STEPPER_Bipolar_CCW(void);
void STEPPER_Bipolar_STOP(void);
void STEPPER_UniPolar_CW(void);
void STEPPER_UniPolar_CCW(void);


#endif /* HAL_STEPPER_H_ */
