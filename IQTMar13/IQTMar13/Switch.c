///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// DEMONSTRATION LAB X.2.A-4 /////////////////////////////
/////////////////////////////////// Math /////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
// Input an integer from the user
// Create a menu allowing the user to:
//     Print their input as Octal
//     Print their input as Decimal
//     Print their input as Hexadecimal
//     Print their input as a Character
//     Input a new number
//     Exit
///////////////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int firstNumber = 0;
int secondNumber = 0;
char operator=0;

int main(void)
{
	int firstNumber = 0;
	int secondNumber = 0;
	char operator = 0;

	printf("Input a simple math formula separated by an operator:  ");
	_flushall();
	scanf("%d %c %d", &firstNumber, &operator, &secondNumber);
	printf("\n\n");

	switch (operator)
		{
		case '+':			// Addition
			printf("%d%c%d=%d\n", firstNumber,operator, secondNumber, (firstNumber+secondNumber));
			break;
		case '-':			// Subtraction
			printf("%d%c%d=%d\n", firstNumber, operator, secondNumber, (firstNumber - secondNumber));
			break;
		case '*':			// Multiplication
			printf("%d%c%d=%d\n", firstNumber, operator, secondNumber, (firstNumber * secondNumber));
			break;
		case '/':			// Division
			if (secondNumber != 0)
			{
				printf("%d%c%d=%.4lf\n", firstNumber, operator, secondNumber, ((double)firstNumber/secondNumber));
			}
			else
			{
				printf("Division by zero is not possible.\n");
			}
			break;
		default:
			printf("You entered unsupported input. \n");
			break;
		}
	getchar();
	return 0;
}