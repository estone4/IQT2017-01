#include <stdio.h>

int main(void)
{
	int i = 32;

	// Prints all the printable characters of the ascii table
	while (i<=126)
	{
		printf("%c = %d\n", i, i);
		i++;
	}

	getchar();
	return 0;
}