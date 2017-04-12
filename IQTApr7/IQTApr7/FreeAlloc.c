#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>


	// Free malloc exercise

int main(void)
{
	char firstName[255] = { 0 };
	char lastName[255] = { 0 };
	char * full_ptr = NULL;
	int firstLength = 0;
	int lastLength = 0;

	// USER INPUT //
	printf("What is your first name?\n");
	scanf("%s", &firstName);
	printf("What is your last name?\n");
	scanf("%s", &lastName);

	// Set the length 
	firstLength = strlen(firstName);
	lastLength = strlen(lastName);
	
	// Set the memory size
	full_ptr = (char *)calloc(1, firstLength + lastLength + 2);

	// Puts the string together
	strncat(full_ptr, firstName, firstLength);
	strncat(full_ptr, " ", 1);
	strncat(full_ptr, lastName, lastLength);

	// Prints the full name
	printf("The full name: %s", full_ptr);

	// Free's the memory
	free(full_ptr);


	getchar();
	getchar();

	return 0;
}
