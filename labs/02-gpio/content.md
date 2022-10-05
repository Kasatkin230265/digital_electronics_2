1. Copy/paste [your solution](https://raw.githubusercontent.com/tomas-fryza/digital-electronics-2/master/solutions/lab1-blink_arduino/src/main.c) with two LEDs from Lab1 to `LAB2-GPIO_LIBRARY > src > main.c` source file. Compile (build) the project and note its size in bytes.

   | **Version** | **Size [B]** |
   | :-- | :-: |
   | Arduino-style |  |
   | Registers |  |
   | Library functions |  |

2. Use the datasheet to find out the meaning of the DDRB and PORTB control register values and their combinations. (Let PUD (Pull-up Disable) bit in MCUCR (MCU Control Register) is 0 by default.)

   | **DDRB** | **PORTB** | **Direction** | **Internal pull-up resistor** | **Description** |
   | :-: | :-: | :-: | :-: | :-- |
   | 0 | 0 | input | no | Tri-state, high-impedance |
   | 0 | 1 | | | |
   | 1 | 0 | | | |
   | 1 | 1 | | | |

3. To control individual bits, the following binary and logic operations are used.
   1. `|` OR
   2. `&` AND
   3. `^` XOR
   4. `~` NOT
   5. `<<` binary shift to left

   | **b** | **a** |**b OR a** | **b AND a** | **b XOR a** | **NOT b** |
   | :-: | :-: | :-: | :-: | :-: | :-: |
   | 0 | 0 | 0 | 0 | 0 | 1 |
   | 0 | 1 | 1 | 0 | 1 | 1 |
   | 1 | 0 | 1 | 0 | 1 | 0 |
   | 1 | 1 | 1 | 1 | 0 | 0 |

   ![binary operations](images/binary_operations.png)
