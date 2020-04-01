#pragma once
#ifndef __USART_HPP__
#define __USART_HPP__
#include "settings.hpp"
#include "base.hpp"
#include "api.hpp"
#include "stringFuncs.hpp"
#include "USARTModes.hpp"
#include "customFuncAddr.hpp"

#ifndef EOL
	#pragma message The EOL not defined! Using NULL
	#define EOL 0
#endif

namespace usart
{
	

	template<const size_t N> constexpr bool isUsartNumberValid();

	const uint8_t MAX_BUF_SIZE = 254;


	struct buffers 
	{
		#ifndef NO_USART_RXBUF
		volatile char 		inputBuf[MAX_BUF_SIZE];
		volatile uint8_t 	inputBufCounterInput;
		volatile uint8_t 	inputBufCounterOutput;
		volatile uint8_t 	inputBufEmpty;
		#endif //ifndef NO_USART_RXBUF
	};


	#ifndef NO_USART_RXBUF	//TODO: disabling TX buffering

		extern struct buffers buffers0;

		#ifdef UCSR1A
			extern struct buffers buffers1;
		#endif //ifdef UCSR1A
		#ifdef UCSR2A
			extern struct buffers buffers2;
		#endif //ifdef UCSR2A
		#ifdef UCSR3A
			extern struct buffers buffers3;
		#endif //ifdef UCSR3A


		template<const size_t n>
		constexpr struct buffers* _getBuffers()
		{
			static_assert(isUsartNumberValid<n>(), "Bad USART num");
			
			switch (n)
			{
			case 0:
				return &buffers0;
			#ifdef UCSR1C
			case 1:
				return &buffers1;
			#endif //ifdef UCSR1C
			#ifdef UCSR2C
			case 2:
				return &buffers2;
			#endif //ifdef UCSR2C
			#ifdef UCSR3C
			case 3:
				return &buffers3;
			#endif //ifdef UCSR3C
			default:
				return 0;
			}
		}

	#endif //ifndef NO_USART_RXBUF

	#ifdef NO_USART_RXBUF
		extern volatile char input0Value;
		#ifdef UCSR1A
			extern volatile char input1Value;
		#endif
		#ifdef UCSR2A
			extern volatile char input2Value;
		#endif
		#ifdef UCSR3A
			extern volatile char input3Value;
		#endif

		template<const size_t N>
		constexpr volatile char* _getInputValue()
		{
			static_assert(isUsartNumberValid<N>(), "Bad USART num");

			volatile char* ret = 0;
			switch (N)
			{
			case 0:
				ret = &input0Value;
				break;	
			#ifdef UCSR1A
			case 1:
				ret = &input1Value;
				break;
			#endif
			#ifdef UCSR2A
			case 2:
				ret = &input2Value;
				break;
			#endif
			#ifdef UCSR3A
			case 3:
				ret = &input3Value;
				break;
			#endif
			default:
				break;
			}
			return ret;
		}

	#endif
		

	enum NumSys { DEC, BIN, OCT, HEX };

	enum Modes
	{
		CHAR_5B = 0,
		CHAR_6B = (1 << UCSZ00),
		CHAR_7B = (1 << UCSZ01),
		CHAR_8B = ((1 << UCSZ00) | (1 << UCSZ01)),
		CHAR_9B = ((1 << UCSZ00) | (1 << UCSZ01) | (1 << UCSZ02))
	};


	template<const size_t N>
	constexpr bool isUsartNumberValid()
	{
		size_t maxNum = 0;
		#ifdef UCSR1A
			maxNum = 1;
		#endif //ifdef UCSR1A
		#ifdef UCSR2A
			maxNum = 2;
		#endif //ifdef UCSR2A
		#ifdef UCSR3A
			maxNum = 3;
		#endif //ifdef UCSR3A
		return N <= maxNum;
	}

	template<const size_t n>
	constexpr uint8_t* _getUCSRnA()
	{
		static_assert(isUsartNumberValid<n>(), "Bad USART num");

		switch (n)
		{
		case 0:
			return UCSR0A;
		#ifdef UCSR1A
		case 1:
			return UCSR1A;
		#endif //ifdef UCSR1A
		#ifdef UCSR2A
		case 2:
			return UCSR2A;
		#endif //ifdef UCSR2A
		#ifdef UCSR3A
		case 3:
			return UCSR3A;
		#endif //ifdef UCSR3A
		default:
			return 0;
		}
	}

	template<const size_t n>
	constexpr uint8_t* _getUDREn()
	{
		static_assert(isUsartNumberValid<n>(), "Bad USART num");

		switch (n)
		{
		case 0:
			return UDRE0;
		#ifdef UDRE1
		case 1:
			return UDRE1;
		#endif //ifdef UDRE1
		#ifdef UDRE2
		case 2:
			return UDRE2;
		#endif //ifdef UDRE2
		#ifdef UDRE3
		case 3:
			return UDRE3;
		#endif //ifdef UDRE3
		default:
			return 0;
		}
	}

	template<const size_t n>
	constexpr uint8_t* _getUDRn()
	{
		static_assert(isUsartNumberValid<n>(), "Bad USART num");
		
		switch (n)
		{
		case 0:
			return UDR0;
		#ifdef UDR1
		case 1:
			return UDR1;
		#endif //ifdef UDR1
		#ifdef UDR2
		case 2:
			return UDR2;
		#endif //ifdef UDR2
		#ifdef UDR3
		case 3:
			return UDR3;
		#endif //ifdef UDR3
		default:
			return 0;
		}
	}

	template<const size_t n>
	constexpr uint8_t* _getUBRRnL()
	{
		static_assert(isUsartNumberValid<n>(), "Bad USART num");
		
		switch (n)
		{
			case 0:
				return UBRR0L;
			#ifdef UBRR1L
			case 1:
				return UBRR1L;
			#endif //ifdef UBRR1L
			#ifdef UBRR2L
			case 2:
				return UBRR2L;
			#endif //ifdef UBRR2L
			#ifdef UBRR3L
			case 3:
				return UBRR3L;
			#endif //ifdef UBRR3L
			default:
				return 0;
		}
	}

	template<const size_t n>
	constexpr uint8_t* _getUBRRnH()
	{
		static_assert(isUsartNumberValid<n>(), "Bad USART num");
		
		switch (n)
		{
			case 0:
				return UBRR0H;
			#ifdef UBRR1H
			case 1:
				return UBRR1H;
			#endif //ifdef UBRR1H
			#ifdef UBRR2H
			case 2:
				return UBRR2H;
			#endif //ifdef UBRR2H
			#ifdef UBRR3H
			case 3:
				return UBRR3H;
			#endif //ifdef UBRR3H
			default:
				return 0;
		}
	}

	template<const size_t n>
	constexpr uint8_t* _getUCSRnB()
	{
		static_assert(isUsartNumberValid<n>(), "Bad USART num");
		
		switch (n)
		{
			case 0:
				return UCSR0B;
			#ifdef UCSR1B
			case 1:
				return UCSR1B;
			#endif //ifdef UCSR1B
			#ifdef UCSR2B
			case 2:
				return UCSR2B;
			#endif //ifdef UCSR2B
			#ifdef UCSR3B
			case 3:
				return UCSR3B;
			#endif //ifdef UCSR3B
			default:
				return 0;
		}
	}

	template<const size_t n>
	constexpr uint8_t* _getUCSRnC()
	{
		static_assert(isUsartNumberValid<n>(), "Bad USART num");
		
		switch (n)
		{
			case 0:
				return UCSR0C;
			#ifdef UCSR1C
			case 1:
				return UCSR1C;
			#endif //ifdef UCSR1C
			#ifdef UCSR2C
			case 2:
				return UCSR2C;
			#endif //ifdef UCSR2C
			#ifdef UCSR3C
			case 3:
				return UCSR3C;
			#endif //ifdef UCSR3C
			default:
				return 0;
		}
	}

	


	//set bit settings of USART, mode on input
	template <const size_t N>
	void setBitSettings(Modes bitness);
	//init function, baudrate on input
	template <const size_t N>
	void begin(uint64_t __baud);

	//send one char function
	template <const size_t N>
	void send(unsigned char __data);

	//send char array function
	template <const size_t N>
	void print(const char* __data);
	template <const size_t N>
	void print(const unsigned char* __data);
	template <const size_t N>
	void print(int num);
	template <const size_t N>
	void print(long num);
	template <const size_t N>
	void print(unsigned long num);
	template <const size_t N>
	void print(int num, NumSys sys);

	template <const size_t N>
	void println();
	template <const size_t N>
	void println(const char* __data);
	template <const size_t N>
	void println(const unsigned char* __data);
	template <const size_t N>
	void println(int num);
	template <const size_t N>
	void println(long num);
	template <const size_t N>
	void println(unsigned long num);
	template <const size_t N>
	void println(int data, NumSys sys);



	//get recieved data
	template <const size_t N>
	char read();
	//get is any data recieved
	template <const size_t N>
	bool available();
	//remove all recieved data
	template <const size_t N>
	void flush();

















	/*
	* Function send
	* Desc     Send byte to USART0
	* Input    _data: byte to send
	* Output   none
	*/
	template <const size_t N>
	void send(unsigned char __data)			//send 1 byte to USART0
	{
		while(!(*_getUCSRnA<N>() & (1 << *_getUDREn<N>()))){asm("NOP");}//TODO: send to buf and get with interrupt
		*_getUDRn<N>() = __data;
		/*
		* The transmit buffer can only be written
		* when the UDRE0 Flag in the UCSR0A Register is set
		* from atmega328p datasheet
		*/
	}

	/*
	* Function print
	* Desc     Send byte array to USART0
	* Input    __data: byte array to send
	* Output   none
	*/
	template <const size_t N>
	void print(const char* __data)	//send C-string to USART0
	{
		while(*__data != 0x00)
		{
			send<N>(static_cast<uint8_t>(*(__data)));
			__data++;
		}
	}

	/*
	* Function print
	* Desc     Send byte array to USART0
	* Input    __data: byte array to send
	* Output   none
	*/
	template <const size_t N>
	void print(const unsigned char* __data)	//send C-string to USART0
	{
		while(*__data != 0x00)
		{
			send<N>(static_cast<uint8_t>(*(__data)));
			__data++;
		}
	}

	/*
	* Function println
	* Desc     Send EndOfLine to USART0
	* Input    none
	* Output   none
	*/
	template <const size_t N>
	void println()
	{
		print<N>(EOL);
	}

	/*
	* Function print
	* Desc     Convert to char array and send dec num to USART0
	* Input    __data: dec num
	* Output   none
	*/
	template <const size_t N>
	void print(int num)
	{
		char* __arr = int2str(num);
		print<N>(__arr);
		free(__arr);
	}

	/*
	* Function print
	* Desc     Convert to char array and send dec num to USART0
	* Input    __data: dec num
	* Output   none
	*/
	template <const size_t N>
	void print(long __data)
	{
		char* __arr = long2str(__data);
		print<N>(__arr);
		free(__arr);
	}

	/*
	* Function print
	* Desc     Convert to char array and send dec num to USART0
	* Input    __data: dec num
	* Output   none
	*/
	template <const size_t N>
	void print(unsigned long __data)
	{
		char* __arr = long2str(__data);
		print<N>(__arr);
		free(__arr);
	}

	/*
	* Function print
	* Desc     Send num to USART0 with mode
	* Input    __data: num to send
	* 			__mode: mode used for sending num
	* Output   none
	*/
	template <const size_t N>
	void print(uint64_t __data, NumSys mode)
	{
		switch(mode)
		{
			case DEC:
			{
				print<N>(static_cast<unsigned long>(__data));
				break;
			}
			case BIN:
			{
				char * ___arr;
				___arr = static_cast<char*>(dec2bin(__data));
				print<N>(___arr);
				free(___arr);
				break;
			}
			default:
			{
				print<N>(static_cast<unsigned long>(__data));
				break;
			}
		}
	}

	/*
	* Function println
	* Desc     Send to USART0 converted to char array num and EndOfLine
	* Input    __data: Num to send
	* Output   none
	*/
	template <const size_t N>
	void println(int __data)
	{
		print<N>(__data);
		print<N>(EOL);
	}

	/*
	* Function println
	* Desc     Send to USART0 converted to char array num and EndOfLine
	* Input    __data: Num to send
	* Output   none
	*/
	template <const size_t N>
	void println(long __data)
	{
		print<N>(__data);
		print<N>(EOL);
	}

	/*
	* Function println
	* Desc     Send num and EndOfLine to USART0 with mode
	* Input    __data: num to send
	* 			__mode: mode to send
	* Output   none
	*/
	template <const size_t N>
	void println(int __data, NumSys __mode)
	{
		print<N>(static_cast<uint64_t>(__data), __mode);
		println<N>();
	}

	/*
	* Function println
	* Desc     Send num and EndOfLine to USART0 with mode
	* Input    __data: num to send
	* 			__mode: mode to send
	* Output   none
	*/
	template <const size_t N>
	void println(long __data, NumSys __mode)
	{
		print<N>(static_cast<uint64_t>(__data), __mode);
		println<N>();
	}

	/*
	* Function println
	* Desc     Send num and EndOfLine to USART0 with mode
	* Input    __data: num to send
	* 			__mode: mode to send
	* Output   none
	*/
	template <const size_t N>
	void println(unsigned long __data, NumSys __mode)
	{
		print<N>(static_cast<uint64_t>(__data), __mode);
		println<N>();
	}

	/*
	* Function println
	* Desc     send char array and EndOfLine to USART0
	* Input    __data: char array to send
	* Output   none
	*/
	template <const size_t N>
	void println(const char* __data)
	{
		print<N>(__data);
		print<N>(EOL);
	}

	/*
	* Function println
	* Desc     send char array and EndOfLine to USART0
	* Input    __data: char array to send
	* Output   none
	*/
	template <const size_t N>
	void println(const unsigned char* __data)
	{
		print<N>(__data);
		print<N>(EOL);
	}


	/*
	* Function read
	* Desc     Read byte recieved from USARTN
	* Input    none
	* Output   Recieved byte
	*/
	template <const size_t N>
	char read()
	{
		char ret = '\0';
		#ifndef NO_USART_RXBUF
		if(_getBuffers<N>()->inputBufCounterOutput >= MAX_BUF_SIZE)							//check that counters are in borders of buf size
		{
			_getBuffers<N>()->inputBufCounterOutput = 0;										//start from zero
			_getBuffers<N>()->inputBufEmpty = true;											//with empty buf
		}
		else if(_getBuffers<N>()->inputBufCounterOutput >= _getBuffers<N>()->inputBufCounterInput)//check that counter for output not overtaked input
		{
			ret = _getBuffers<N>()->inputBuf[_getBuffers<N>()->inputBufCounterOutput];			//save data to temp var
			_getBuffers<N>()->inputBufCounterOutput = 0;										//set counters to zero
			_getBuffers<N>()->inputBufCounterInput  = 0;
			_getBuffers<N>()->inputBufEmpty = true;											//empty buf
		}
		else if(!_getBuffers<N>()->inputBufEmpty)												//if have data
		{
			ret = _getBuffers<N>()->inputBuf[_getBuffers<N>()->inputBufCounterOutput];			//save data to temp var
			_getBuffers<N>()->inputBufCounterOutput++;											//go to next index for reading
			if(_getBuffers<N>()->inputBufCounterOutput >= MAX_BUF_SIZE)						//check that counter is in borders of buf size
			{
				_getBuffers<N>()->inputBufCounterOutput = 0;									//start from zero
				_getBuffers<N>()->inputBufEmpty = true;										//empty buf
			}
		}
		#else
			ret = *_getInputValue<N>();
			*_getInputValue<N>() = '\0';
		#endif
		return ret;
	}

	/*
	* Function available
	* Desc     Return is recieved new byte
	* Input    none
	* Output   Have new state
	*/
	template <const size_t N>
	bool available()
	{
		#ifndef NO_USART_RXBUF
		if(_getBuffers<N>()->inputBufCounterOutput >= _getBuffers<N>()->inputBufCounterInput	//check that counter for output not overtaked input
		|| _getBuffers<N>()->inputBufCounterOutput >= MAX_BUF_SIZE)
		{
			_getBuffers<N>()->inputBufCounterOutput = 0;
			_getBuffers<N>()->inputBufCounterInput  = 0;
			_getBuffers<N>()->inputBufEmpty = true;										//empty buf
		}
		return !_getBuffers<N>()->inputBufEmpty;
		#else 
			return *_getInputValue<N>() != 0;
		#endif
	}

	/*
	* Function flush
	* Desc     Clear USART0 registers
	* Input    none
	* Output   none
	*/
	template <const size_t N>
	void flush()
	{
		#ifndef NO_USART_RXBUF
		uint8_t __temp = 0;
		__temp = __temp;//for bypassing -Wunused-but-set-variable
		while(*_getUCSRnA<N>() & (1 << RXC0))
		{
			__temp = _getUDRn<N>();
			_getBuffers<N>()->inputBufCounterInput = 0;
			_getBuffers<N>()->inputBufCounterInput  = 0;
			_getBuffers<N>()->inputBufEmpty = true;
		}
		#else
			uint8_t __temp = _getUDRn<N>();
			__temp = __temp;//for bypassing -Wunused-but-set-variable
		#endif
	}

	/*
	* Function setBitSettings
	* Desc     Set USART0 packet parameters
	* Input    __bitness: mode for transmitting
	* Output   none
	*/
	template <const size_t N>
	void setBitSettings(uint8_t __bitness)
	{
		*_getUCSRnC<N>() = __bitness;
	}

	/*
	* Function begin
	* Desc     Initialize USART0
	* Input    __baud: baudrate for transmitting
	* Output   none
	*/
	template <const size_t N>
	void begin(uint64_t __baud)
	{
		#ifndef NO_USART_RXBUF
		for(int i = 0; i < MAX_BUF_SIZE; i++)//flush data array
		{
			_getBuffers<N>()->inputBuf[i] = '\0';
		}
		#else
		*_getInputValue<N>() = '\0';
		#endif

		*_getUCSRnA<N>() = 1 << U2X0;									 //double speed mode
		uint16_t __baudPrescaller =  static_cast<uint16_t>((F_CPU / (8 * __baud)) - 1);//((Clock rate / (16 * baudrate))) - 1
															//for U2X0 mode:
															//((Clock rate / (8 * baudrate))) - 1
			if (((F_CPU == 16000000UL) && (__baud == 57600)) || (__baudPrescaller > 4095))	//disable double speed mode
			{																				//if prescaller is too high
				*_getUCSRnA<N>() = 0;
				__baudPrescaller = static_cast<uint16_t>(F_CPU / (16 * __baud));
			}

		*_getUBRRnL<N>() = static_cast<uint8_t>(__baudPrescaller);//set low bits of baud prescaller
		*_getUBRRnH<N>() = static_cast<uint8_t>(__baudPrescaller >> 8);//set high bits of baud prescaller

		*_getUCSRnB<N>() |= (1 << RXEN0) | (1 << RXCIE0);//enable recieve and interrupt on recieve

		*_getUCSRnB<N>() |= (1 << TXEN0) | (1 << TXCIE0);//enable trancieve and interrupt on trancieve
												//TODO: changable bit size
		*_getUCSRnB<N>() = (1 << UCSZ00) | (1 << UCSZ01); //set USART0 Character Size to 8 bit
		/*
		* Character Size table:
		* 000 5-bit
		* 001 6-bit
		* 010 7-bit
		* 011 8-bit
		* 100 Reserved
		* 101 Reserved
		* 110 Reserved
		* 111 9-bit
		*/
	}


} // namespace usart
#endif //ifndef __USART_HPP__