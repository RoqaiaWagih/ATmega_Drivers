/*
 * SSD_interface.c
 *
 * Created: 3/7/2024 
 *  Author:Roqaia Khalid
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

//STATIC array of numbers in 7_segment
static const u8 NUMBERS[10]={
	0b00111111 , //0
	0b00000110 , //1
	0b01011011 , //2
	0b01001111 , //3
	0b01100110 , //4
	0b01101101 , //5
	0b01111101 , //6
	0b00000111 , //7
	0b01111111 , //8
	0b01101111   //9
};


//function to set port direction
void seven_SEG_voidInit(){
	//DIO_voidSetPortDirection(copy_u8PortId,0xff);
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_voidSetPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_OUTPUT);
}

//display number and check if cathode or anode then set port value
void seven_SEG_voidDisplayNumber(u8 copy_u8PortId,u8 copy_u8PinId,u8 A_u8Number){
	if(A_u8Number<=9 && A_u8Number>=0){
		#if SSD_Type==1
		//DIO_voidSetPinValue(copy_u8PortId,copy_u8PinId,NUMBERS[A_u8Number]);
		DIO_voidSetPinValue(PORTA,DIO_PIN3,GET_BIT(NUMBERS[A_u8Number],7));
		DIO_voidSetPinValue(PORTA,DIO_PIN2,GET_BIT(NUMBERS[A_u8Number],6));
		DIO_voidSetPinValue(PORTB,DIO_PIN5,GET_BIT(NUMBERS[A_u8Number],5));
		DIO_voidSetPinValue(PORTB,DIO_PIN6,GET_BIT(NUMBERS[A_u8Number],4));
		//DIO_voidSetPinValue(PA,EN,1);
		_delay_ms(2000);
		//DIO_voidSetPinValue(PA,EN,0);
		_delay_ms(2000);
		DIO_voidSetPinValue(PORTA,DIO_PIN3,GET_BIT(NUMBERS[A_u8Number],3));
		DIO_voidSetPinValue(PORTA,DIO_PIN2,GET_BIT(NUMBERS[A_u8Number],2));
		DIO_voidSetPinValue(PORTB,DIO_PIN5,GET_BIT(NUMBERS[A_u8Number],1));
		DIO_voidSetPinValue(PORTB,DIO_PIN6,GET_BIT(NUMBERS[A_u8Number],0));
		#elif SSD_Type==2
		//DIO_voidSetPinValue(copy_u8PortId,copy_u8PinId,~NUMBERS[A_u8Number]);
		DIO_voidSetPinValue(PORTA,DIO_PIN3,GET_BIT(~NUMBERS[A_u8Number],7));
		DIO_voidSetPinValue(PORTA,DIO_PIN2,GET_BIT(~NUMBERS[A_u8Number],6));
		DIO_voidSetPinValue(PORTB,DIO_PIN5,GET_BIT(~NUMBERS[A_u8Number],5));
		DIO_voidSetPinValue(PORTB,DIO_PIN6,GET_BIT(~NUMBERS[A_u8Number],4));
		DIO_voidSetPinValue(PA,EN,1);
		_delay_ms(2000);
		//DIO_voidSetPinValue(PA,EN,0);
		_delay_ms(2000);
		DIO_voidSetPinValue(PORTA,DIO_PIN3,GET_BIT(~NUMBERS[A_u8Number],3));
		DIO_voidSetPinValue(PORTA,DIO_PIN2,GET_BIT(~NUMBERS[A_u8Number],2));
		DIO_voidSetPinValue(PORTB,DIO_PIN5,GET_BIT(~NUMBERS[A_u8Number],1));
		DIO_voidSetPinValue(PORTB,DIO_PIN6,GET_BIT(~NUMBERS[A_u8Number],0));
		#endif
		
	}
	else{
		//
	}
	
}

//function to turn the 7_segment off if cathode 0x00 if anode 0xff
void seven_SEG_voidTurnOff(u8 copy_u8PortId){
	#if SSD_Type==1
	DIO_voidSetPortDirection(copy_u8PortId,0x00);
	#elif SSD_Type==2
	DIO_voidSetPortDirection(copy_u8PortId,0xff);
	#endif

}


//function to display the numbers from 0 to 9 in a loop
void seven_SEG_voidCountUp(u8 copy_u8PortId,u8 copy_u8PinId,u8 A_u8Number){
	//for
	for (u8 counter=0;counter<=9;counter++)
	{
		seven_SEG_voidDisplayNumber(copy_u8PortId,copy_u8PinId,counter);
		_delay_ms(1000);
	}
}



////function to display the numbers from 9 to 0 in a loop
void seven_SEG_voidCountdown(u8 copy_u8PortId,u8 copy_u8PinId,u8 A_u8Number){
	
	//for
	for (int counter=9;counter>=0;counter++){
		
		
		seven_SEG_voidDisplayNumber(copy_u8PortId,copy_u8PinId,counter);
		_delay_ms(1000);
	}
}