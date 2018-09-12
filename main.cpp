#include <avr/io.h>			//include for base avr funcs
#define F_CPU 16000000		//define with freq
#include <util/delay.h> 		//include for delay func
#include <avr/interrupt.h>	//include interrupt funcs
#include <stdlib.h>

#define NUM_OF_ANALOG_PINS 7
#define ARDUINO_SUPPORT 0
#define USE_ADC 1

//---------TIMERS----------
#define USE_TIMERS 1
#define TIMER0_USE_COMPA 1
#define TIMER5_USE_COMPA 1

//---------USART----------
#define USE_USART 1
#define USE_USART0 1
#define USE_USART0_OUTPUT 1
#define USE_USART0_INPUT 1
#define USE_SERIAL_FASTBAUD 0

//---------CUSTOM_INTERRUPTS----------
#define USE_CUSTOM_INTERRUPTS 1

#include "api.h"//custom api for AVR





int main()
{
	DDRB = ((1 << PB0) | (1 << PB1) | (1 << PB7) | (1 << PB1));//8, 9, 13 output
	DDRC = ((1 << PC5) | (1 << PC4) | (1 << PC3));//A0,1,2 output
	DDRD = ((1 << PD2) | (1 << PD3) | (0 << PD4) | (1 << PD5) | (1 << PD6) | (0 << PD7));//2,3,4,5,6,7 output
	DDRL = 0;
	PORTL = 1 << PL2;
	PORTB &= ~(1 << PB7);
	PORTD |= 1 << PD7;
	
	//PORTB = 0;
	USART0Begin(115200);
	//funcs[USART0_RECIEVE_INTERRUPT_CUSTOMFUNC_ADDR] = USART_RX;
	sei();
	TIMER5Init(TIMER5_MODE_CTC_TOPOCR5A);
	TIMER5SetCLK(TIMER5_CLOCK_EXTERNAL_FALLING);
	TIMER5EnableCOMPAInterrupt();
	TIMER5SetA(1);
	USART0Println("s\r");
	while(1)
	{
		_delay_ms(1);
	}
	return 0;
}
