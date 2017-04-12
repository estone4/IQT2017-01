#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	float inputTemp = 0;			// Stores input temerature
	int tempConversion = 0;
	float convertedTemp = 0;

	printf("Please enter a temperature for conversion: ");
	scanf("%f", &inputTemp);
	printf("Enter 1 for F, 2 for C ");
	scanf("%d", &tempConversion);

	if (tempConversion == 1)
	{
		convertedTemp = ((inputTemp * 9) / 5) + 32;
	}
	else if (tempConversion == 2)
	{
		convertedTemp = ((inputTemp - 32) * 5) / 9;
	}
	else
	{
		printf("Invalid selection. \n");
	}

	printf("The converted temperature is: %.3f \n", convertedTemp);

	getchar();
	getchar();
	return 0;
}