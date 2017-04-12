////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// DEMONSTRATION LAB X.2.A-3 //////////////////////////////////////
/////////////////////////////// "WHAT'S THE DIFFERENCE?" ///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
// Initialize three (and only three) int variables to 0
// Safely scan user input into the variable #1 and #2 utilizing a single line
// Using a single ELSE-IF statement:
//     If variable #1 is equal to variable #2, assign 0 to variable #3
//     Otherwise, subtract the smallest from the largest (e.g., 3 - 2, 42 - -455, -11 - -1337)
//         and assign the result to variable #3
// Print the value of variable #3 if it is positive, otherwise print an error
////////////////////////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	/* Initialize three (and only three) int variables to 0 */
	unsigned int myNum1 = 0;
	unsigned int myNum2 = 0;
	unsigned int myNum3 = 0;

	/* Safely scan user input into the variable #1 and #2 utilizing a single line */
	printf("Enter two integers separated by a single space. \n");
	printf("(e.g., -17 1932 \n");
	_flushall();
	scanf("%u %u", &myNum1, &myNum2);

	/* Using a single ELSE-IF statement */
	/* If variable #1 is equal to variable #2, error */
	if (myNum1 == myNum2) // Executes this block if the two input variables are equal
	{
		printf("Error. Your variables were equal. \n");
	}
	/* If variable #1 is larger, subtract variable #2 from it */
	else if (myNum1 > myNum2) // Executes this block if myNum1 is the largest
	{
		// myNum1 is larger so this statement subtracts variable2 and assigns the result to variable3
		/*myNum3 = myNum1; 
		myNum1 = 0;*/

		// Uses XOR to perform the swap
		myNum1 = myNum1 ^ myNum3;
		myNum3 = myNum1 ^ myNum3;
		myNum1 = myNum1 ^ myNum3;
	}
	/* Otherise variable #2 is larger, subtract variable #1 from it */
	else							// Executes this block if variable 2 is the largest
	{
		// myNum2 is larger so this statement subtracts variable1 and assigns the result to variable3
		//myNum3 = myNum2; 
		//myNum2 = 0;

		// Uses XOR to perform the swap
		myNum2 = myNum2 ^ myNum3;
		myNum3 = myNum2 ^ myNum3;
		myNum2 = myNum2 ^ myNum3;
	}

	/* Print the value of variable #3 if it is positive, otherwise print an error */
	/* Print the value of variable #3 if it is positive... */
	
	if (myNum1+myNum2+myNum3 > 2)
	{
		printf("Variable 1:  %d \n", myNum1);
		printf("Variable 2:  %d \n", myNum2);
		printf("Variable 3:  %d \n", myNum3);
	}
	/* ...otherwise print an error code. */
	
	else
	{
		printf("Something bad happened because variable 3 was not positive. \n");
		printf("Instead, variable 3 turned out to be %d. \n", myNum3);
	}

	getchar();
	return 0;
}