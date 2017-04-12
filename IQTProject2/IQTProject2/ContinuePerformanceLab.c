#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	unsigned int userInput = 0;
	unsigned int count = 0;
	int divCount = 0;
	
	while (userInput != 999)
	{
		printf("Enter a number(999 to exit)  ");
		scanf("%u", &userInput);

		if (userInput == 0)
		{
			continue;
		}
		else if (userInput >= 999)
		{
			break;
		}
		else
		{
			for (; count <= 20; )
			{
				if (divCount % userInput==0)
				{
					printf("%u is divisible by %u.\n", divCount, userInput, divCount % userInput);
					count++;
				}
				divCount++;		
			}
		}
		count = 0;
		divCount = 0;
	}
	return 0;
}