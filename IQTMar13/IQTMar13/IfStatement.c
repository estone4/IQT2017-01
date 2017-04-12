////////////////////////////////////////////////////////////////////////
// Initialize a char array to zero
// Safely store a user-input string in that char array
// Safely print the string *if* the first element is >=32 and <126
////////////////////////////////////////////////////////////////////////


#include <stdio.h>

int main(void)
{
	char userInputString[256] = { 0 };
	printf("Input a string: \n");
	_flushall();
	fgets(userInputString, sizeof(userInputString) -1, stdin);

	if (userInputString[0] >= 32 && userInputString[0] < 126);
	{
		fputs(userInputString, stdout);
	}

	getchar();
	return 0;
}