#include <stdio.h>

int main(void)
{
	int myInteger = 6;
	float myFloat = 3.1234567890;
	double myDouble = 3.1234567890;
	char myChar = 'E';

	printf("Integer as float: %d \n", (float)myInteger);
	printf("Integer as char: %d \n", (char)myInteger);
	printf("Float as double %f \n", (double)myFloat);
	printf("Double as float: %lf \n", (float)myDouble);
	printf("First char as int: %c \n", (int)myChar);
	printf("33 as char: %c \n", (char)33);
	//printf("\n");
	//printf("Size of Integer is: %d \n", sizeof(myInteger));
	//printf("Size of Float is %d \n", sizeof(fltInteger));
	//printf("Size of Double is: %d \n", sizeof(dblInteger));
	//printf("Size of First char: %d \n", sizeof(character1));
	//printf("Size of Second char: %d \n", sizeof(character2));
	getchar();
	return 0;
}