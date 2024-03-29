/*
 * LCD_interface.h
 *
 * Created: 3/7/2024 
 *  Author: Roqaia Khalid
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_



#define RS 3
#define EN 2
//data pins
#define D4 0
#define D5 1
#define D6 2
#define D7 4





void LCD_voidInit(void);

void LCD_voidWriteData(u8 copy_u8data);

void LCD_voidWriteCommand(u8 copy_u8Command);



void LCD_voidWriteString(u8 * copy_str);

void LCD_voidGoToXY(u8 copy_u8Row,u8 copy_u8Col);

void LCD_voidClear(void);

void LCD_voidWriteNumber( u32 Copy_u8num );
void LCD_voidWriteStringGoToXY(u8 * copy_u8data , u8 copy_u8Row ,u8 copy_u8Col );







#endif /* LCD_INTERFACE_H_ */
