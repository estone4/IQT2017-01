#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define QUOTE_FOR_REAL(x) #x
#define QUOTE(x) QUOTE_FOR_REAL(x)
#define COMBINE_FOR_REAL(x,y) x##y
#define COMBINE(x,y) COMBINE_FOR_REAL (x,y)
#define BUFFERSIZE 64



int main(void)
{
	char myArray[BUFFERSIZE] = { (QUOTE(COMBINE(string, _literal))) };

	puts(myArray);

	getchar();
	return 0;
}
