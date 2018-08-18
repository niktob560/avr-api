#if USE_USART0 == 1

	#if USE_USART0_OUTPUT == 1
	
		void USARTSend(char data)			//send 1 byte to USART
		{	
			while(!(UCSR0A & (1 << UDRE0))){}
			UDR0 = data;
			/*
			 * The transmit buffer can only be written 
			 * when the UDRE0 Flag in the UCSR0A Register is set 
			 * from atmega328p datasheet
			 */
		}
		
		void USARTPrint(char* _data_)	//send C-string to USART
		{	
			while(*_data != 0x00)
			{
				USARTSend(*_data_);
				_data_++;
			}
		}
		
		#define DEC 0
		#define BIN 1
		
		void USARTPrint(int _data_, byte _mode_)
		{
			switch(_mode_)
			{
				case DEC:
				{
					USARTPrint(int2str(_data_));
					break;
				}
				case BIN:
				{
					USARTPrint(dec2bin(_data_));
					break;
				}
				default:
				{
					USARTPrint(int2str(_data_));
					break;
				}
			}
		}
		
		inline void USARTPrintln(int _data_, byte _mode_)
		{
			USARTPrint(_data_, _mode_);
			USARTSend('\n');
		}
		
		inline void USARTPrintln(char* _data_)
		{
			USARTPrint(_data_);
			USARTSend('\n');
		}
		
		inline void USARTPrintln()
		{
			USARTSend('\n');
		}
		
		ISR(USART0_TX_vect)//interrupt handler called aftar transmitting data
		{			
			if(funcs[USART0_RECIEVE_INTERRUPT_CUSTOMFUNC_ADDR] != NULL)
				funcs[USART0_RECIEVE_INTERRUPT_CUSTOMFUNC_ADDR]();		//call custom function 		
		}
		
	#endif //if USE_USART0_OUTPUT == 1
	
	
	#if USE_USART0_INPUT == 1
		
		#define _MAX_BUF_SIZE_ 256
			
		char _inputBuf_[_MAX_BUF_SIZE_];//buffer for input from USART
		uint8_t _inputBufCounterInput_ = 0;//index of last char placed by system
		uint8_t _inputBufCounterOutput_ = 0;//index of last char gotted by user
		uint8_t _inputBufEmpty_ = true;
		
		
		
		ISR(USART0_RX_vect)		   //interrupt handler called after recieving data
		{					
			if(_inputBufCounterInput_ >= _MAX_BUF_SIZE_	//check that counters are in borders of buf size
					|| _inputBufEmpty_)					//or buf empty
			{
				_inputBufCounterInput_ = 0;				//start writing from zero
			}
			
			_inputBuf_[_inputBufCounterInput_] = UDR0;	//save data
			
			if(_inputBuf_[_inputBufCounterInput_] != NULL)//check for garbage
			{
				_inputBufEmpty_ = false;				//set empty flag down
				_inputBufCounterInput_++;				//go next index for writing
			}
			
			if(funcs[USART0_RECIEVE_INTERRUPT_CUSTOMFUNC_ADDR] != NULL)
				funcs[USART0_RECIEVE_INTERRUPT_CUSTOMFUNC_ADDR]();//call custom function
		}
		
		char USARTRead()//get data from input USART buffer
		{
			if(_inputBufCounterOutput_ >= _MAX_BUF_SIZE_)	//check that counters are in borders of buf size
			{
				_inputBufCounterOutput_ = 0;				//start from zero
				_inputBufEmpty_ = true;						//with empty buf
			}
			else if(_inputBufCounterOutput_ >= _inputBufCounterInput_)//check that counter for output not overtaked input
			{
				char ___ret___ = _inputBuf_[_inputBufCounterOutput_];//save data to temp var
				_inputBufCounterOutput_ = 0;						//set counters to zero
				_inputBufCounterInput_  = 0;
				_inputBufEmpty_ = true;								//empty buf
				return ___ret___;									//return data
			}
			else if(!_inputBufEmpty_)								//if have data
			{
				char ___ret___ = _inputBuf_[_inputBufCounterOutput_];//save data to temp var
				_inputBufCounterOutput_++;							//go to next index for reading
				if(_inputBufCounterOutput_ >= _MAX_BUF_SIZE_)		//check that counter is in borders of buf size
				{
					_inputBufCounterOutput_ = 0;					//start from zero	
					_inputBufEmpty_ = true;							//empty buf
				}
				return ___ret___;									//return data
			}
			else
			{
				return NULL;					//ERROR
			}
		}
		
		bool USARTAvailable()
		{
			if(_inputBufCounterOutput_ >= _inputBufCounterInput_	//check that counter for output not overtaked input
			|| _inputBufCounterOutput_ >= _MAX_BUF_SIZE_)
			{
				_inputBufCounterOutput_ = 0;
				_inputBufCounterInput_  = 0;
				_inputBufEmpty_ = true;								//empty buf
			}
			return !_inputBufEmpty_;
		}

	#endif //if USE_USART0_INPUT == 1


	void USARTBegin(uint64_t _baud)
	{		
		#if USE_USART0_INPUT == 1
		
			for(int i = 0; i < _MAX_BUF_SIZE_; i++)
			{
				_inputBuf_[i] = NULL;
			}
		#endif //if USE_USART0_INPUT == 1
		
		UCSR0A = 1 <<  U2X0;									 //double speed mode
		uint16_t _baudPrescaller =  ((F_CPU / (8 * _baud))) - 1;//((Clock rate / (16 * baudrate))) - 1
															   //for U2X0 mode: 
															  //((Clock rate / (8 * baudrate))) - 1
		#if USE_SERIAL_FASTBAUD == 1
			if (((F_CPU == 16000000UL) && (_baud == 57600)) || (_baudPrescaller > 4095))	//disable double speed mode
			{																				//if prescaller is too high
				UCSR0A = 0;
				_baudPrescaller = (F_CPU / (16 * _baud));
			}
		#endif //if USE_SERIAL_FASTBAUD == 1
		
		UBRR0L = (uint8_t)(_baudPrescaller);//set low bits of baud prescaller
		UBRR0H = (uint8_t)(_baudPrescaller>>8);//set high bits of baud prescaller
		
		#if USE_USART0_INPUT == 1
			UCSR0B |= (1 << RXEN0) | (1 << RXCIE0);//enable recieve and interrupt on recieve
		#endif //if USE_USART0_INPUT == 1
		
		#if USE_USART0_OUTPUT == 1
			UCSR0B |= (1 << TXEN0) | (1 << TXCIE0);//enable trancieve and interrupt on trancieve
		#endif //if USE_USART0_OUTPUT == 1		  //
												 //TODO: changable bit size
		UCSR0C = (1 << UCSZ00) | (1 << UCSZ01); //set USART Character Size to 8 bit
		/*
		 * ATMEGA328P Character Size table:
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
	
	
#endif //if USE_USART0 == 1
