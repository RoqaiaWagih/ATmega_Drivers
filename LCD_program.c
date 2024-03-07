/*
 * LCD_program.c
 *
 * Created: 3/7/2024 
 *  Author: Roqaia Khalid
 */ 
#define F_CPU 16000000Ul
/*********************MCAL*********************/
#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_register.h"
/*********************HAL*********************/
#include "LCD_interface.h"
/*********************UTILTES_TYPES*********************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include <util/delay.h>

void LCD_voidInit(void){
	
	//PIN direction of DIO portA---&---portB
	DIO_voidSetPortDirection(DIO_PORTA, DIO_PORT_OUTPUT);
	DIO_voidSetPortDirection(DIO_PORTB, DIO_PORT_OUTPUT);
	_delay_ms(20);


LCD_voidWriteCommand(0x02);//SET FUNCTION
_delay_ms(10);
LCD_voidWriteCommand(0x28);//DISPLAY
_delay_ms(1);
LCD_voidWriteCommand(0x0e);
_delay_ms(2);
LCD_voidWriteCommand(0x01);//CLEAR
_delay_ms(10);

LCD_voidWriteCommand(0x06);//SHIFTE
_delay_ms(1);

	
	
}

void LCD_voidWriteData(u8 copy_u8data){
	//CONTROL PINS --- RW write ---RS data
	//sent  HIGH EN pulse
	//RW |= 0;
	     //0 by default in kit      
	//RS |=1;
	
	//EN |=1
	
	DIO_voidSetPinValue(DIO_PORTA,RS,DIO_PIN_HIGH);
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,GET_BIT(copy_u8data,7));
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,GET_BIT(copy_u8data,6));
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,GET_BIT(copy_u8data,5));
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,GET_BIT(copy_u8data,4));

	DIO_voidSetPinValue(DIO_PORTA,EN,DIO_PIN_HIGH);
	_delay_us(1);
	DIO_voidSetPinValue(DIO_PORTA,EN,DIO_PIN_LOW);
	_delay_us(200);
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,GET_BIT(copy_u8data,3));
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,GET_BIT(copy_u8data,2));
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,GET_BIT(copy_u8data,1));
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,GET_BIT(copy_u8data,0));
	//DIO_voidSetPinValue(DIO_PORTA,RS,DIO_PIN_HIGH);
	DIO_voidSetPinValue(DIO_PORTA,EN,DIO_PIN_HIGH);
	
	_delay_us(2);
	DIO_voidSetPinValue(DIO_PORTA,EN,DIO_PIN_LOW);
	_delay_ms(2);
	//sent LOW EN pulse
	//EN |=0
	
}

void LCD_voidWriteCommand(u8 copy_u8Command){
	//control pins --- RW write ---RS commend
	//sent  HIGH EN pulse
	//RW |= 0;
	     //0 by default in kit 
	//RS |=0;
	
	//EN |=1

	//sent Commend=u8command
	DIO_voidSetPinValue(DIO_PORTA,RS,DIO_PIN_LOW);
 
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,GET_BIT(copy_u8Command,7));
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,GET_BIT(copy_u8Command,6));
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,GET_BIT(copy_u8Command,5));
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,GET_BIT(copy_u8Command,4));
	
	DIO_voidSetPinValue(DIO_PORTA,EN,DIO_PIN_HIGH);
	_delay_us(1);
	DIO_voidSetPinValue(DIO_PORTA,EN,DIO_PIN_LOW);
	_delay_us(200);
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,GET_BIT(copy_u8Command,3));
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,GET_BIT(copy_u8Command,2));
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,GET_BIT(copy_u8Command,1));
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,GET_BIT(copy_u8Command,0));	
	//sent LOW EN pulse
	//EN |=0
	
	DIO_voidSetPinValue(DIO_PORTA,EN,DIO_PIN_HIGH);
	_delay_us(1);
	DIO_voidSetPinValue(DIO_PORTA,EN,DIO_PIN_LOW);
	_delay_ms(2);
	
}



void LCD_voidWriteString(u8 * copy_str){
	
	while(*copy_str !='\0'){
		LCD_voidWriteData(*copy_str);
		copy_str++;
	}
}

void LCD_voidGoToXY(u8 copy_u8Row,u8 copy_u8Col){
	//u8 postion;
	switch(copy_u8Row){
		
		case 0:
		    //SET_CURSOR_LOCATION 0x80
			 LCD_voidWriteCommand(copy_u8Col | 0x80);
		break;
		
		case 1:
		    copy_u8Col+=0x40;
			//SET_CURSOR_LOCATION 0x80
		    LCD_voidWriteCommand(copy_u8Col | 0x80);
		break;
		default:
		//invaled
		break;
		
	}
}

void LCD_voidClear(void){
	LCD_voidWriteCommand(0x01);//CLEAR
}

void LCD_voidWriteNumber( u32 Copy_u8num ){
	if (Copy_u8num == 0) {
		LCD_voidWriteData('0');
	}else{

	// Buffer to store the reversed number as a string
	char reversedNumber[20];  // Adjust the size based on your requirements
	u8 index = 0;

	// Reverse the Number and Convert to String
	while (Copy_u8num > 0) {
		reversedNumber[index++] = (Copy_u8num % 10) + '0';
		Copy_u8num /= 10;
	}

	// Print Reversed Number
	for (u8 i = index; i > 0; i--) {
		LCD_voidWriteData(reversedNumber[i - 1]);
	}
}
	}




void LCD_voidWriteStringGoToXY(u8 * copy_u8data , u8 copy_u8Row ,u8 copy_u8Col ){
	LCD_voidGoToXY(copy_u8Row,copy_u8Col);
	LCD_voidWriteString(copy_u8data);
}

