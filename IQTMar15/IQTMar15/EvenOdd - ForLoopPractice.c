//
//IQT For Loop Practice
//Name: Eric Stone
//Date: 15-March-2017
//

#define _CRT_SECURE_NO_WARNINGS 1	//Required for scanf in Visual Studio
#include <stdio.h>					//Standard Input/output functions

int main(void)
{
	int number = 0;					//Stores the users number
	int even = 0;					//Stores whether chose even or odd

	printf("Please enter a number: ");
	scanf("%i", &number);
	printf("Please select even or odd: 1=even, 2=odd");
	scanf("%i", &even);

	if (even == 1)
	{
		for (int i = 2; i <= number; i++)
		{
			if (i % 2 == 0)  //Checks if there a remainder??
			{
				printf("%i \n", i);
			}
		}
	}

	if (even == 2)
	{
		for (int i = 1; i <= number; i++)
		{
			if (i % 2 == 1)  //Is looking for a remainder
			{
				printf("%i \n", i);
			}
		}
	}

	getchar();
	return 0;
}