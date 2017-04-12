#include <stdio.h>

int main(void)
{
	int i = 0;

	// Prints all the printable characters of the ascii table
	for (i = 32; i <= 126; i++)
	{
		printf("%c=%d\n", i,i);
	}

	getchar();
	return 0;
}