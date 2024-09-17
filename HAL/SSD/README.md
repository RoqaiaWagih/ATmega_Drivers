# 7-Segment Display Driver

The 7-Segment Display Driver is a utility for interfacing with a 7-segment display, facilitating the display of numeric digits. It supports both common cathode and common anode 7-segment displays.

## Constants

### `NUMBERS` Array

- **Description:** Static array containing bit patterns for displaying numbers 0 to 9 on a 7-segment display.
- **Usage:** Internally utilized by the driver to determine segment activation for each numeric digit.

## Functions

### `seven_SEG_voidInit`

- **Description:** Initializes the ports and pins connected to the 7-segment display for output.
- **Usage:** Call this function at the program's start to set up the 7-segment display.

### `seven_SEG_voidDisplayNumber`

- **Description:** Displays a specified numeric digit on the 7-segment display.
- **Parameters:**
  - `copy_u8PortId`: Port ID connected to the 7-segment display.
  - `copy_u8PinId`: Pin ID connected to the 7-segment display.
  - `A_u8Number`: Numeric digit to display (0 to 9).
- **Usage:** Displays a specific number on the 7-segment display.

### `seven_SEG_voidTurnOff`

- **Description:** Turns off the 7-segment display.
- **Parameters:**
  - `copy_u8PortId`: Port ID connected to the 7-segment display.
- **Usage:** Call this function to turn off the 7-segment display.

### `seven_SEG_voidCountUp`

- **Description:** Displays numbers from 0 to 9 in sequence on the 7-segment display.
- **Parameters:**
  - `copy_u8PortId`: Port ID connected to the 7-segment display.
  - `copy_u8PinId`: Pin ID connected to the 7-segment display.
- **Usage:** Displays a count-up sequence on the 7-segment display.

### `seven_SEG_voidCountdown`

- **Description:** Displays numbers from 9 to 0 in sequence on the 7-segment display.
- **Parameters:**
  - `copy_u8PortId`: Port ID connected to the 7-segment display.
  - `copy_u8PinId`: Pin ID connected to the 7-segment display.
- **Usage:** Displays a countdown sequence on the 7-segment display.

## Note

- The driver supports both common cathode (`SSD_Type == 1`) and common anode (`SSD_Type == 2`) 7-segment displays. Ensure the correct type is selected by defining `SSD_Type` appropriately.
- Adjust delay times in the `seven_SEG_voidCountUp` and `seven_SEG_voidCountdown` functions based on display requirements.
- Configure connections and the display type before using the driver.
