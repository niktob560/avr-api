#pragma once
#include "base.hpp"

namespace twi
{

	enum Responce { ACK = 1, NACK = 0 };

	// #define _TWI_ACK							1
	// #define _TWI_NACK							0
	const uint8_t _OUT_BUF_LEN		= 40;
	const uint8_t _IN_BUF_LEN		= 60;
	const uint8_t _USR_IN_BUF_LEN	= 40;
	const uint8_t I2C_WRITE			= 0x00;
	const uint8_t I2C_READ			= 0x01;
	const uint8_t I2C_STANDBY		= 0x02;
	const uint8_t I2C_FAIL			= 0x03;
	const uint8_t I2C_RESTART_FAIL	= 0x04;
	const uint8_t I2C_DISABLED		= 0xFF;

	extern uint16_t	_twi_in_len;
	extern uint16_t _twi_out_len;


	/*
	* Function: I2C_SetFreq
	* Desc:     Set working frequency of I2C bus
	* Input:    _freq: what frequency set to
	* Output:   none
	*/
	inline void SetFreq(uint8_t _freq)
	{
		TWBR = _freq;
	}

	/*
	*	Function:	shiftLeft
	*	Desc:		Shift some array to left on N elements
	*	Input:		void* arr: 		ptr to array shift to
					uint8_t size:	size of element
					uint32_t len: 	length of array
					uint32_t el:	num of elements
	*	Output:		none
	*/
	void shiftLeft(uint8_t* arr, uint32_t len, uint32_t el);

	/*
	*	Function:	shiftRight
	*	Desc:		Shift some array to right on N elements
	*	Input:		void* arr: ptr to array shift to
					uint32_t len: length of array
	*	Output:		none
	*/
	void shiftRight(uint8_t* arr, uint32_t len, uint32_t el);

	/*
	*	Function:	addPack
	*	Desc:		Add package to user queue
	*	Input:		uint8_t  addr:			what addr of slave set to
					const uint8_t* data:	pointer to data array
					uint8_t len:			num of bytes in data array
					uint8_t mode:			read or write mode use to
	*	Output:		none
	*/
	void addPack(uint8_t addr, const uint8_t* data, uint8_t len, uint8_t mode);

	/*
	*	Function:	addPack
	*	Desc:		Add package to user queue
	*	Input:		uint8_t  addr:		what addr of slave set to
					uint8_t data:		byte send to
					uint8_t mode:		read or write mode use to
	*	Output:		none
	*/
	void addPack(uint8_t addr, uint8_t data, uint8_t mode);
	/*
	*	Function:	addPack
	*	Desc:		Add package to user queue
	*	Input:		uint8_t  addr:		what addr of slave set to
					uint16_t data:		byte send to
					uint8_t mode:		read or write mode use to
	*	Output:		none
	*/
	void addPack(uint8_t addr, uint16_t data, uint8_t mode);

	/*
	*	Function:	getByte
	*	Desc:		Get byte from input array(if have)
	*	Input:		none
	*	Output:		uint8_t: readed byte (0xFF if nothing to read)
	*/
	uint8_t getByte(void);

	/*
	*	Function: 	write
	*	Desc:		Write a byte to reg on slave device
	*	Input:		uint8_t addr: slave device addr
					uint8_t reg: what reg write to
					uint8_t data: what write to
	*	Output:		none
	*/
	void write(uint8_t addr, uint8_t reg, uint8_t data);


	/*
	*	Function: 	reqRead
	*	Desc:		Request a byte from reg on slave device
	*	Input:		uint8_t addr: slave device addr
					uint8_t reg: what reg read from
					uint8_t len: len of data in bytes
	*	Output:		none
	*/
	void reqRead(uint8_t addr, uint8_t reg, uint8_t len);


	/*
	*	Function:	start
	*	Desc:		Start TWI state machine
	*	Input:		none
	*	Output:		none
	*/
	void start(void);

	/*
	*	Function:	stop
	*	Desc:		Stop TWI state machine
	*	Input:		none
	*	Output:		none
	*/
	void stop(void);


	/*
	*	Function:	hadRead
	*	Desc:		If have new bytes to read return 1(t), else 0(f)
	*	Input:		none
	*	Output:		bool
	*/
	inline bool hadRead(void)
	{
		return (_twi_in_len > 0);
	}

	
} // namespace twi