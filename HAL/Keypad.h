/*
 * Keypad.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Egypt_Laptop
 */

#ifndef HAL_KEYPAD_H_
#define HAL_KEYPAD_H_
#define ROW 4
#define COL 4

#define FRIST_OUTPUT  PINB02
#define FRIST_INPUT   PIND02

#define NO_KEY 'A'

#ifdef   KEYPAD_PROG

static  u8 KeysArray[ROW][COL]={ {'7','8','9','/'},
		                              {'4','5','6','*'},
		                              {'1','2','3','-'},
		                              {'c','0','=','+'}
                                                      };
#endif




void Keypad_Init(void);

u8 Keypad_Getkey(void);



#endif /* HAL_KEYPAD_H_ */
