#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{

	int firstNumber;
	int secondNumber;

	printf("Enter 2 integers, separated by an *, to be multiplied: \n");
	scanf("%i%*c%i", &firstNumber, &secondNumber);
	printf("The result of %i and %i is: %i \n", firstNumber, secondNumber, firstNumber*secondNumber);

	return 0;
}