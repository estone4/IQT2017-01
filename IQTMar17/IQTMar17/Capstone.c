//////////////////////////////////////
//	Group:		Eric Stone			//
//				Joel Lafleur		//
//				Lewis Bivins		//
//				Raymond Hernandez	//
//----------------------------------//
//	Date:		17 March 17			//
//	Project:	Capstone			//
//	Included some tweaks to display //
//	the binary before and after		//
//////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <limits.h>
#include <inttypes.h>

int main(void)
{
	uint32_t inputMask = 1 << 31;				//Sets 1 then shifts to the most significant bit
	uint32_t bitMask = 0x01;					//Sets a single bit
	uint32_t arbitraryInt = 0xFFFFFFFF;			//Loads a full 32 bits
	uint32_t userInput = 0;						//Stores user input

	printf("Enter a number between 0 and %d. \n", ((sizeof(inputMask) * 8) - 1), stdout);
	scanf("%u", &userInput);

	bitMask <<= userInput;						//Shifts the bitMask based on the number the user entered
	
	printf("%u \n", arbitraryInt ^ bitMask);	//XOR's a full 32 bits to the shifted bitMask

	printf("Displays full register. \n");
	for (int i = 0; i < (sizeof(arbitraryInt) * 8); i++)
	{
		fprintf(stdout, "%d", (arbitraryInt & (inputMask >> i)) > 0);				//Prints out the full 32 bits
	}

	printf("\n");
	printf("Displays the shifted bit. \n");
	for (int i = 0; i < (sizeof(arbitraryInt) * 8); i++)
	{
		fprintf(stdout, "%d", ((arbitraryInt ^ bitMask) & (inputMask >> i)) > 0);	//Prints out the new binary showing the shifted bit
	}

	printf("\n");

	getchar();									//getchar placed to keep debug window open
	getchar();

	return 0;
}