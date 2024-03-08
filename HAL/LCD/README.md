# LCD Driver Documentation

## `LCD_voidInit`

```c
void LCD_voidInit(void);
```
Initializes the LCD by configuring the data direction for DIO port A and B, and sending initialization commands.

### LCD_voidWriteData
```c
void LCD_voidWriteData(u8 copy_u8data);
```
Writes data to the LCD.

#### Parameters:
- copy_u8data: The data byte to be written to the LCD.
### LCD_voidWriteCommand
```c
void LCD_voidWriteCommand(u8 copy_u8Command);
```
Writes a command to the LCD.

#### Parameters:
- copy_u8Command: The command byte to be written to the LCD.
### LCD_voidWriteString
```c
void LCD_voidWriteString(u8 * copy_str);
```
Writes a null-terminated string to the LCD.

#### Parameters:
- copy_str: Pointer to the string to be written.
### LCD_voidGoToXY
```c
void LCD_voidGoToXY(u8 copy_u8Row, u8 copy_u8Col);
```
Moves the cursor to the specified position on the LCD.

#### Parameters:
- copy_u8Row: Row number (0 or 1).
- copy_u8Col: Column number (0 to 15).
### LCD_voidClear
```c
void LCD_voidClear(void);
```
Clears the LCD display.

### LCD_voidWriteNumber
```c
void LCD_voidWriteNumber(u32 Copy_u8num);
```
Writes a number to the LCD.

#### Parameters:
- Copy_u8num: The number to be displayed.
### LCD_voidWriteStringGoToXY
```c
void LCD_voidWriteStringGoToXY(u8 * copy_u8data, u8 copy_u8Row, u8 copy_u8Col);
```
Writes a string to the LCD at a specified position.

#### Parameters:
- copy_u8data: Pointer to the string to be written.
- copy_u8Row: Row number (0 or 1).
- copy_u8Col: Column number (0 to 15).
