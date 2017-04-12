#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include "MyStringHeader.h"

int main(void)
{
	char inputString[] = {0};
	char reverseString[] = { 0 };
	
	printf("Enter a string.");
	
	//scanf("%c", &inputString);

	for (int i = 0; i < strlen; i++)
	{
		scanf("%c", &inputString);
	}
	
	
	
	
	for (int i = 0; i <= strlen; i++)
	{
		reverseString[i] = _strrev(scanf("%c", &inputString[i]));
	}

	for (int i = 0; i <= strlen; i++)
	{
		printf("%c", (reverseString[i]));
	}
	

	//reverse_it(inputString, sizeof(inputString)/sizeof(inputString[0]));

	//print_the_count(inputString, sizeof(inputString) / sizeof(inputString[0]));
	
	getchar();
	getchar();
	return 0;
}