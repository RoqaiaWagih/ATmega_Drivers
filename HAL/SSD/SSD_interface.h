/*
 * SSD_interface.h
 *
 * Created: 3/7/2024 
 *  Author: Roqaia Khalid
 */ 


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define Cathode 1
#define Anode   2

#define SSD_Type	Cathode


/*
  //Table for common cathode

Digit	A	B	C	D	E	F	G
0		1	1	1	1	1	1	0
1		0	1	1	0	0	0	0
2		1	1	0	1	1	0	1
3		1	1	1	1	0	0	1
4		0	1	1	0	0	1	1
5		1	0	1	1	0	1	1
6		1	0	1	1	1	1	1
7		1	1	1	0	0	0	0
8		1	1	1	1	1	1	1
9		1	1	1	1	0	1	1
A		1	1	1	0	1	1	1
b		0	0	1	1	1	1	1
C		1	0	0	1	1	1	0
d		0	1	1	1	1	0	1
E		1	0	0	1	1	1	1
F		1	0	0	0	1	1	1

 */

 // macros to define numbers in English

#define zero	0
#define one		1
#define two		2
#define three	3
#define four	4
#define five	5
#define six		6
#define seven	7
#define eight	8
#define nine	9


//void seven_SEG_voidInit(u8 copy_u8PortId);
void seven_SEG_voidInit();

void seven_SEG_voidDisplayNumber(u8 copy_u8PortId,u8 copy_u8PinId,u8 A_u8Number);
void seven_SEG_voidTurnOff(u8 copy_u8PortId);
void seven_SEG_voidCountUp(u8 copy_u8PortId ,u8 copy_u8PinId,u8 A_u8Number);
void seven_SEG_voidCountdown(u8 copy_u8PortId,u8 copy_u8PinId,u8 A_u8Number);




#endif /* SSD_INTERFACE_H_ */
