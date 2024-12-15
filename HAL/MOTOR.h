/*
 * MOTOR.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Egypt_Laptop
 */

#ifndef HAL_MOTOR_H_
#define HAL_MOTOR_H_

#define IN1_M1    PINB02
#define IN2_M1    PINB03
#define IN1_M2    PINB04
#define IN2_M2    PINB05

void MOTOR_CW(void);
void MOTOR_CCW(void);
void MOTOR_STOP(void);

#endif /* HAL_MOTOR_H_ */
