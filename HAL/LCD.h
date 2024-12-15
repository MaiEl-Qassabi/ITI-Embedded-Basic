/*
 * LCD.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Egypt_Laptop
 */
/*
 * LCD.h
 *
 *  Created on: Aug 13, 2023
 *      Author: NEW LAP
 */

#ifndef HAL_LCD_H_
#define HAL_LCD_H_

/*********** CFG ********/
#define RS   PINC06
#define EN   PINC07

#define LCD_PORT   PD

/*************** FUNC ***************/
void LCD_Init(void);
void LCD_WriteNumber(s32 num);
void LCD_WriteChar(u8 ch);
void LCD_WriteString(u8 *str);

void LCD_WriteBinary(u8 num);
void LCD_WriteHex(u8 num);

void LCD_SetCursor(u8 line,u8 cell);

void LCD_Clear(void);
void LCD_GoToClear(u8 line ,u8 cell,u8 NumCells);


#endif /* HAL_LCD_H_ */
