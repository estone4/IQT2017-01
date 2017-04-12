///////////////////////////////////////////////////////////////////////////
////////////////////// DEMONSTRATION LAB I.1.g-3 //////////////////////////
///////////////////////////////////////////////////////////////////////////
// Initialize two char arrays (input and output) of equal dimension
// Safely read a user-input string into your 'input' char array
// Initialize a different char variable to be your mask
// XOR each element (except the last) against that char mask
// Store the obfuscated XOR results in the output array
// Print both arrays using a safe string function
///////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <limits.h>

int main(void)
{
	printf("Maximum value of char is %d. \n", UCHAR_MAX); // DEBUGGING
	unsigned char inputBuff[256] = { 0 };
	unsigned char outputBuff[256] = { 0 };
	//	unsigned char obfuscationMask = UCHAR_MAX - 0xFE; // Subtract a value from CHAR_MAX to ensure I don't exceed CHAR_MAX
	unsigned char obfuscationMask = 125;
	int i = 0; // Used to iterate through a for loop

	printf("Input a string:  \n");
	fgets((char*)inputBuff, sizeof(inputBuff), stdin);

	for (i = 0; i < sizeof(outputBuff); i++)
	{

		if (inputBuff[i]) // Stops the for loop from XOR'ing any null terminators
		{
			outputBuff[i] = inputBuff[i] ^ obfuscationMask;
			//			printf("%d: %u \n", i, outputBuff[i]); // DEBUGGING
		}
	}
	outputBuff[sizeof(outputBuff) - 1] = 0; // Manually null-terminates this string

	printf("You typed:  \n\t");
	puts((char*)inputBuff);
	printf("Obfuscated:  \n\t");
	puts((char*)outputBuff);

	return 0;
}