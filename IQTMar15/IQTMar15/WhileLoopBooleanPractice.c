//////////////////////////////
//	IQT While Loop Practice	//
//	Name: Eric Stone		//
//	Date: 15-March-2017		//
//////////////////////////////


#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int number = 0;			//Stores the users number
	int even = 0;			//Stores whether the user chose even or odd
	//bool even = true;

	printf("Please enter a number: ");
	scanf("%i", &number);
	printf("Please select odd or even: 0=odd, 1=even");
	scanf("%d", &even);

	if (even == 1)
	{
		int i = 2;

		while (i <= number)
		{
			if (i % 2 == 0)
			{
				printf("%i \n", i);
			}
			i++;
		}
	}

	if (even == 0)
	{

		int i = 1;

		while (i <= number)
		{
			if (i % 2 == 1)
			{
				printf("%i \n", i);
			}
			i++;
		}
	}


	getchar();
	return 0;
}