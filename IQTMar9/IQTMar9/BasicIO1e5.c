#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	
	char firstName[20] = { 0 };
	char middleName[20] = { 0 };
	char lastName[20] = { 0 };

	printf("Enter first, middle, and last name separated by tabs: \n");
	_flushall();	//Clears all open input streams and leaves them open
	scanf("%19[A-Za-z ]\t %19[A-Za-z ]\t %19[A-Za-z ]", firstName, middleName, lastName);
	printf("The name you entered is: \n");
	printf("%s\t\n%s\t\n%s\n", firstName, middleName, lastName);

	return 0;
}