
/*

	COMMAND HANDLER FUNCTIONS
	ARDUINO & STM32
	LAST UPDATE: 21. 4. 2020.
	CREDITS: Pararera (c)

*/


// MODULES
#include 																			"CommandHandler.h"

// LIBRARIES
#include 																			<Arduino.h>


// OBJECT CONSTRUCTOR
CMDHand::CMDHand(const char cmdDelimiter, const char paramDelimiter)
{
	delimiter[CMD_SET][0] = cmdDelimiter;
	delimiter[CMD_SET][1] = '\0';
	delimiter[CMD_PARAM][0] = paramDelimiter;
	delimiter[CMD_PARAM][1] = '\0';

	for (uint8_t i = 0; i < 2; i++)
	{
		next[i] = nullptr;
		last[i] = nullptr;
		constrain[i] = nullptr;
	}
}


// OBJECT DECONSTRUCTOR
CMDHand::~CMDHand()
{
	for (uint8_t i = 0; i < 2; i++)
	{
		delimiter[i][0] = '\0';
		next[i] = nullptr;
		last[i] = nullptr;
		constrain[i] = nullptr;
	}
}

// FIND FUNCTON
char *CMDHand::find(const char *input, uint8_t const type)
{
	char *found = nullptr;

	if (input != nullptr) // FIRST CALL
	{
		constrain[type] = input + strlen(input) - 1;
		next[type] = input;
	}
	else if (next[type] > constrain[type]) return (nullptr);

	found = strtok(next[type], &delimiter[type][0]);
	last[type] = next[type];
	next[type] += strlen(found) + 1;

	return (found);
}

// COUNT FUNCTIONS
uint8_t CMDHand::count(const char *input, uint8_t const type) const
{
	return (countParts(input, type));
}

uint8_t CMDHand::count(uint8_t const type) const
{
	return (countParts(last[type], type));
}

uint8_t CMDHand::countParts(const char *input, uint8_t const type) const
{
	uint16_t len = strlen(input);
	uint16_t lastDelimiter = 0;
	uint8_t totalCount = 0;

	for (uint16_t i = 0; i < len; i++)
	{
		if (input[i] == delimiter[type][0])
		{
			if (i - lastDelimiter < 1) continue;
			else if (i == len - 1) break;

			totalCount++;
			lastDelimiter = i; 
		}
	}

	if (!totalCount)
	{
		if (len) return (1);
			else return (0);
	}
	else return (totalCount + 1);
	
}

// GETNEXT FUNCTION
char *CMDHand::getNext(uint8_t const type) const
{
	return (next[type]);
}

// GETLAST FUNCTION
char *CMDHand::getLast(uint8_t const type) const
{
	return (last[type]);
}