//////////////////////////////
//	Bitwise Shift Right		//
//	Name: Eric Stone		//
//	Date: 16 March 2017		//
//////////////////////////////

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	uint32_t userInput = 0;
	uint32_t bitChecker = 0x01;
	printf("Input a positive number less than ‭2147483648‬:  ");
	_flushall();
	fscanf(stdin,"%u", &userInput);

	printf("Your number was %u (Hex: 0x%08X) \n", userInput, userInput);

	bitChecker = bitChecker << ((sizeof(userInput) * 8) - 1);

	for (int i = 0; i < (sizeof(userInput) * 8); i++)
	{
		fprintf(stdout, "%d", (userInput & (bitChecker >> i)) > 0);
	}

	printf("\n");
	
	getchar();
	return 0;
}