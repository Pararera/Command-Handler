
/*

	COMMAND HANDLER FUNCTIONS
	ARDUINO & STM32
	LAST UPDATE: 21. 4. 2020.
	CREDITS: Pararera (c)

*/

#ifndef _CMDHAND_H
#define _CMDHAND_H

// LIBRARIES
#include 																			<Arduino.h>


// CODES
#define CMD_SET																		0
#define CMD_PARAM 																	1


// CLASS
class CMDHand
{
public:

	// ----- CONSTRUCTOR & DECONSTRUCTOR
	CMDHand(const char, const char);
	~CMDHand();

	// ----- FUNCTIONS
	/*
		Finds command set or command param in given C string and returns address of it
		@params:
			- input: Pointer to the C string of command(s) ; Pass nullptr/NULL to continue with new address from last call 
			- type: Find command set in C string or find command param in command set 
		@return:
			- Pointer to first char in command set or command param
	*/
	char *find(const char*, uint8_t const);

	/*
		Counts number of command sets or command params in C string from "input"
		@params:
			- input: Pointer to the C string of command(s)
			- type: Find command set in C string or find command param in command set
		@return:
			- Number of command sets or command params in given C string
	*/
	uint8_t count(const char*, uint8_t const) const;

	/*
		Counts number of command sets or command params in C strings from "next[type]"
		@params:
			- type: Find command set in C string or find command param in command set
		@return:
			- Number of command sets or command params in given C string
	*/
	uint8_t count(uint8_t const) const;

	/*
		Returns address of next selected command set or command param in find function
		@params:
			- type: Command set or command param
		@return:
			- Address of next command set or command param in given C string
	*/
	char *getNext(uint8_t const) const;

	/*
		Returns address of last command set or command param found in find function
		@params:
			- type: Command set or command param
		@return:
			- Address of last command set or command param in given C string
	*/
	char *getLast(uint8_t const) const;

private:

	// ----- FUNCTIONS
	/*
		Counts number of command sets or command params in given C string
		@params:
			- input: Pointer to the C string of command(s)
			- type: Find command set in C string or find command param in command set
		@return:
			- Number of command sets or command params in given C string
	*/
	uint8_t countParts(const char*, uint8_t const) const;

	// ----- VARIABLES
	char *next[2];
	char *last[2];
	char *constrain[2];
	char delimiter[2][2];
};

#endif // _CMDHAND_H