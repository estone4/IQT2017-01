#include <stdio.h>
#include "EnglishFunctions.h"


	// Checks if the input is an alphabet character
	
	int is_it_alphabet(signed char inputChar)
	{
		for (int i = 0; i < inputChar; i++)
		{
			if (inputChar >= 65 && inputChar <= 90 || inputChar >= 97 && inputChar <= 122)  // Checks for Upper case or lower case alphabet
				return 1;  // Returns true if alphabet
			else
				return 0;  // Returns False if not alphabet
		}
		return 0;
	}
	
	// Removes anything that is not an upper or lower case alphabet character
	int remove_non_letters(char * sentenceString)
	{
		int charactersRemoved = 0;  // Used to count the number of characters removed

		if (!sentenceString)  // If sentenceString is null return an error
			return -1;
		else 
			for (int i = 0; i < (sizeof(sentenceString)); i++)  // Loops through the sentenceString using the size of the sentence string as the upper limit
			{
				if (sentenceString[i] != 'A-Z' || sentenceString[i] != 'a-z')  // Checks if the index of the sentence string is not an alphabet character.
					sentenceString[i] = sentenceString[i+1];  // Sets the current position to the value of the next position
					charactersRemoved++;  // Increments the number of characters removed
			}
		return charactersRemoved;  // Returns the number of non-alphabet characters removed from the input
	}


	// Clears the buffer
	int clear_a_buffer(char * fullBuff, int buffSize)
	{
		if (!fullBuff)  // Checks if fullBuff is not NULL
			return -1;
		else if (buffSize <= 0)  // Checks if buffSize is empty or a negative value
			return -2;
		else
			for (int i = 0; i < buffSize; i++)  // Loops through each index of fullBuff using buffSize as the upper limit 
			{
				fullBuff[i] += '0';  // Sets each index of fullBuff to 0 to clear the array
			}
		return 0;
	}
