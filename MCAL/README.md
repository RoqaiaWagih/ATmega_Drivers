# DIO (Digital Input/Output) Library Documentation
The DriverVoid module provides a set of functions for configuring and manipulating digital Input/Output (DIO) pins and ports on an AVR microcontroller. It includes functions to set pin direction, pin value, get pin value, toggle pin value, set port direction, set port value, get port value, toggle port value, and activate pull-up resistance on a port.

### `DIO_voidSetPinDirection`

```c
void DIO_voidSetPinDirection(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection);
```
Sets the direction (input or output) of a specific pin on a specified port.

#### Parameters:
- copy_u8PortId: The ID of the target port (e.g., DIO_PORTA, DIO_PORTB, etc.).
- copy_u8PinId: The ID of the target pin within the specified port.
- copy_u8PinDirection: The desired direction for the pin (DIO_PIN_INPUT or DIO_PIN_OUTPUT).
### DIO_voidGetPinValue
```c
void DIO_voidGetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8* copy_pu8PinValue);
```
Reads and retrieves the current value of a specific pin on a specified port.

#### Parameters:
- copy_u8PortId: The ID of the target port (e.g., DIO_PORTA, DIO_PORTB, etc.).
- copy_u8PinId: The ID of the target pin within the specified port.
- copy_pu8PinValue: A pointer to store the read pin value.
### DIO_voidTogglePinValue
```c
void DIO_voidTogglePinValue(u8 copy_u8PortId, u8 copy_u8PinId);
```
Toggles (inverts) the current value of a specific pin on a specified port.

#### Parameters:
- copy_u8PortId: The ID of the target port (e.g., DIO_PORTA, DIO_PORTB, etc.).
- copy_u8PinId: The ID of the target pin within the specified port.
### DIO_voidActivePinInPullUpResistance
```c
void DIO_voidActivePinInPullUpResistance(u8 copy_u8PortId, u8 copy_u8PinId);
```


### DIO_voidSetPortDirection
```c
void DIO_voidSetPortDirection(u8 copy_u8PortId, u8 copy_u8PortDirection);
```
Sets the direction (input or output) for all pins of a specified port.

#### Parameters:
- copy_u8PortId: The ID of the target port (e.g., DIO_PORTA, DIO_PORTB, etc.).
- copy_u8PortDirection: The desired direction for the entire port (DIO_PORT_INPUT or DIO_PORT_OUTPUT).
### DIO_voidSetPortValue
```c
void DIO_voidSetPortValue(u8 copy_u8PortId, u8 copy_u8PortValue);
```
Sets the value (high or low) for all pins of a specified port.

#### Parameters:
- copy_u8PortId: The ID of the target port (e.g., DIO_PORTA, DIO_PORTB, etc.).
- copy_u8PortValue: The desired value for the entire port (DIO_PORT_HIGH or DIO_PORT_LOW).
### DIO_voidGetPortValue
```c
void DIO_voidGetPortValue(u8 copy_u8PortId, u8* copy_pu8PortValue);
```
Reads and retrieves the current value of all pins on a specified port.

#### Parameters:
- copy_u8PortId: The ID of the target port (e.g., DIO_PORTA, DIO_PORTB, etc.).
- copy_pu8PortValue: A pointer to store the read port value.
### DIO_voidTogglePortValue
```c
void DIO_voidTogglePortValue(u8 copy_u8PortId);
```
toggles (inverts) the current value of all pins on a specified port.

#### Parameters:
- copy_u8PortId: The ID of the target port (e.g., DIO_PORTA, DIO_PORTB, etc.).
### DIO_voidActivePortInPullUpResistance
```c
void DIO_voidActivePortInPullUpResistance(u8 copy_u8PortId);
```
