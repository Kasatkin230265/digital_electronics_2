/***********************************************************************
 * 
 * Stopwatch by Timer/Counter2 on the Liquid Crystal Display (LCD)
 *
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2017 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 * Components:
 *   16x2 character LCD with parallel interface
 *     VSS  - GND (Power supply ground)
 *     VDD  - +5V (Positive power supply)
 *     Vo   - (Contrast)
 *     RS   - PB0 (Register Select: High for Data transfer, Low for Instruction transfer)
 *     RW   - GND (Read/Write signal: High for Read mode, Low for Write mode)
 *     E    - PB1 (Read/Write Enable: High for Read, falling edge writes data to LCD)
 *     D3:0 - NC (Data bits 3..0, Not Connected)
 *     D4   - PD4 (Data bit 4)
 *     D5   - PD5 (Data bit 5)
 *     D6   - PD6 (Data bit 3)
 *     D7   - PD7 (Data bit 2)
 *     A+K  - Back-light enabled/disabled by PB2
 * 
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <lcd.h>            // Peter Fleury's LCD library
#include <stdlib.h>         // C library. Needed for number conversions


/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Update stopwatch value on LCD screen when 8-bit 
 *           Timer/Counter2 overflows.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    uint8_t customChar1[8] = {
  	0b00000,
	  0b00000,
  	0b10001,
  	0b01010,
  	0b00100,
  	0b01010,
	  0b10001,
    0b00000
};
    uint8_t customChar2[8] = {
  	0b00000,
  	0b00000,
  	0b10001,
  	0b01010,
  	0b00100,
  	0b01000,
	  0b10000,
    0b00000
};
    uint8_t customChar3[8] = {
	  0b01010,
  	0b00100,
  	0b10001,
	  0b10011,
	  0b10101,
	  0b11001,
	  0b10001,
    0b00000
}; 



    lcd_init(LCD_DISP_ON);

    // Set pointer to beginning of CGRAM memory
    lcd_command(1 << LCD_CGRAM);
    for (uint8_t i = 0; i < 8; i++)
    {
        // Store all new chars to memory line by line
        lcd_data(customChar1[i]);
    }
    for (uint8_t i = 0; i < 8; i++)
    {
        // Store all new chars to memory line by line
        lcd_data(customChar2[i]);
    }
    for (uint8_t i = 0; i < 8; i++)
    {
        // Store all new chars to memory line by line
        lcd_data(customChar3[i]);
    }
    // Set DDRAM address to display characters
    lcd_command(1 << LCD_DDRAM);
 
    // Display first custom character at address 0
    lcd_putc(0);
    // Initialize display
    lcd_init(LCD_DISP_ON_CURSOR_BLINK);

    // Put string(s) on LCD screen
    lcd_gotoxy(1, 0);
    lcd_puts("00:00.0");

    lcd_gotoxy(12 ,1);
    lcd_putc(0x00);
   
    lcd_gotoxy(13 ,1);
    lcd_putc(0x01);
  
    lcd_gotoxy(14 ,1);
    lcd_putc(0x02);
    
    // Configuration of 8-bit Timer/Counter2 for Stopwatch update
    GPIO_mode_output(&DDRB, PB2);   // GPIO_write_low(&PORTB, PB2);
    GPIO_write_high(&PORTB, PB2);


    // Set the overflow prescaler to 16 ms and enable interrupt
    TIM2_overflow_16ms();
    TIM2_overflow_interrupt_enable();


    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines, ISRs */
    }

    // Will never reach this
    return 0;
}


/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter2 overflow interrupt
 * Purpose:  Update the stopwatch on LCD screen every sixth overflow,
 *           ie approximately every 100 ms (6 x 16 ms = 100 ms).
 **********************************************************************/
ISR(TIMER2_OVF_vect)
{
    static uint8_t no_of_overflows = 0;
    static uint8_t tenths = 0;  // Tenths of a second
    static uint8_t secs = 0;    // Tenths of a second
    static uint16_t pwr = 0;    // seconds in power of 2
    static uint8_t bar = 1;     // position of bar
    char string[2];             // String for converted numbers by itoa()

    no_of_overflows++;
    if (no_of_overflows >= 6)
    {
        // Do this every 6 x 16 ms = 100 ms
        no_of_overflows = 0;
        
        tenths++;
        
        lcd_gotoxy(bar ,1);
        lcd_putc(0xff);
        lcd_puts(string);
        bar++;
        if(tenths>9)                    
        {
          tenths = 0;
          secs++;

          bar = 1;

          lcd_gotoxy(2 ,1);
          lcd_putc(' ');
          lcd_puts(string);
          lcd_gotoxy(3 ,1);
          lcd_putc(' ');
          lcd_puts(string);
          lcd_gotoxy(4 ,1);
          lcd_putc(' ');
          lcd_puts(string);
          lcd_gotoxy(5 ,1);
          lcd_putc(' ');
          lcd_puts(string);
          lcd_gotoxy(6 ,1);
          lcd_putc(' ');
          lcd_puts(string);
          lcd_gotoxy(7 ,1);
          lcd_putc(' ');
          lcd_puts(string);
          lcd_gotoxy(8 ,1);
          lcd_putc(' ');
          lcd_puts(string);
          lcd_gotoxy(9 ,1);
          lcd_putc(' ');
          lcd_puts(string);
          lcd_gotoxy(10 ,1);
          lcd_putc(' ');
          lcd_puts(string);
          lcd_gotoxy(1 ,1);
          lcd_putc(' ');
          lcd_puts(string);

          if(secs>59)
          {
            secs=0;
            lcd_gotoxy(5 ,0);
            lcd_putc('0');
            lcd_puts(string);            
              
            lcd_gotoxy(11 ,0);
            lcd_putc(' ');
            lcd_puts(string);
            lcd_gotoxy(12 ,0);
            lcd_putc(' ');
            lcd_puts(string);
            lcd_gotoxy(13 ,0);
            lcd_putc(' ');
            lcd_puts(string);
            lcd_gotoxy(14 ,0);
            lcd_putc(' ');
            lcd_puts(string);
          }
          if(secs<10)
          {
            itoa(secs, string, 10);
            lcd_gotoxy(5 ,0);
          }
          if(secs>9)
          {
            itoa(secs, string, 10);
            lcd_gotoxy(4 ,0);
          }
          lcd_puts(0);
          lcd_puts(string);
          
        }

        // Count tenth of seconds 0, 1, ..., 9, 0, 1, ...
       

        itoa(tenths, string, 10);  // Convert decimal value to string
        // Display "00:00.tenths"
        lcd_gotoxy(7, 0);
        lcd_puts(string);
        
        pwr = pow(secs, 2);
        itoa(pwr, string, 10);
        lcd_gotoxy(11 ,0);
        lcd_puts(string);

        lcd_gotoxy(15, 1);
    }
    // Else do nothing and exit the ISR
}