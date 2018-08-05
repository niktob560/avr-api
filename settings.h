#ifndef USE_TIMERS
	#define USE_TIMERS 0
#endif //ifndef USE_TIMERS

#if USE_TIMERS == 1
	#define TIMER0_USE_COMPA 1			//TIMER0
	#define TIMER0_USE_COMPB 1
	#define TIMER0_USE_OVF 1
	#define TIMER1_USE_COMPA 1				//TIMER1
	#define TIMER1_USE_COMPB 1
	#define TIMER1_USE_OVF 1
	#define TIMER2_USE_COMPA 1				//TIMER2
	#define TIMER2_USE_COMPB 1
	#define TIMER2_USE_OVF 1
#endif //if USE_TIMERS == 1

#ifndef USE_USART
	#define USE_USART 0
#endif //ifndef USE_USART

#ifndef USE_USART0
	#define USE_USART0 0
#endif //ifndef USE_USART0

#if USE_USART0 == 1

	#define USE_USART0_FASTBAUD 1
	#define USE_USART0_INPUT 1
	#define USE_USART0_OUTPUT 1
	#define USART0_RECIEVE_INTERRUPT_CUSTOMFUNC_ADDR 0
	#define USART0_TRANSMISSION_INTERRUPT_CUSTOMFUNC_ADDR 10

#endif //if USE_USART0 == 1
