# Lab 8: Kasatkin Alexey 

### Instruction set

1. Complete the conversion table with selected instructions:

   | **Instruction** | **Binary opcode** | **Hex opcode** | **Compiler Hex opcode** |
   | :-- | :-: | :-: | :-: |
   | `add r24, r0` |  |  |  |
   | `com r26` |  |  |  |
   | `eor r26, r27` |  |  |  |
   | `mul r22, r20` |  |  |  |
   | `ret` | `1001_0101_0000_1000` | `95 08` |  |

### 4-bit LFSR

2. Complete table with 4-bit LFSR values for different Tap positions:

   | **Tap position** | **Generated values** | **Length** |
   | :-: | :-- | :-: |
   | 4, 3 | 0 1 3 7 14 13 11 6 12 9 2 5 10 4 8 | 15 |
   | 4, 2 | 0 1 3 6 12 8 | 6 |
   | 4, 1 | 0 1 2 5 10 4 9 3 6 13 11 7 14 12 8 | 15 |

2.2 Change LFSR tap positions in lfsr4_fibonacci_asm function and generate 5-, 6-, and 7-bit versions of pseudorandom sequence.

| **Tap position** |  **Length** |
   | :-: | :-: |
   | &nbsp;4, 2 | 31 |
   | &nbsp;5, 4 | 63 |
   | &nbsp;6, 5 | 127 |

### Variable number of short pulses

3. Draw a flowchart of function `void burst_c(uint8_t number)` which generates a variable number of short pulses at output pin. Let the pulse width be the shortest one. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![your figure]()