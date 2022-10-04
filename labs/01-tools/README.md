
# Lab 1: Kasatkin Alexey **230265**

### Morse code

1. Listing of C code which repeats one "dot" and one "comma" (BTW, in Morse code it is letter `A`) on a LED. Always use syntax highlighting, meaningful comments, and follow C guidelines:

```c
#define LED_GREEN 13  
#define SHORT_DELAY 250     // dot or space
#define LONG_DELAY 500      // comma
#ifndef F_CPU
# define F_CPU 16000000 
#endif
#include <avr/io.h>    
#include <util/delay.h> 
#include "Arduino.h"        

int main(void)
{
    // Set pin where on-board LED is connected as output
    pinMode(LED_GREEN, OUTPUT);

    // Infinite loop
    while (1)
    {
        // Generate a lettre `A` Morse code

      digitalWrite(LED_GREEN, LOW);         //space
        _delay_ms(SHORT_DELAY);                 
        digitalWrite(LED_GREEN, HIGH);      //dot
        _delay_ms(SHORT_DELAY);
        digitalWrite(LED_GREEN, LOW);       //space
        _delay_ms(SHORT_DELAY);
        digitalWrite(LED_GREEN, HIGH);      //comma
        _delay_ms(LONG_DELAY);

    }

    // Will never reach this
    return 0;
}
```

2. Scheme of Morse code application, i.e. connection of AVR device, LED, resistor, and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

   ![image](https://user-images.githubusercontent.com/99397789/193793991-c8b568df-4b79-40f2-b82e-107e97a93a23.png)
