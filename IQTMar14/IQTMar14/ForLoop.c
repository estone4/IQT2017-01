#include <stdio.h>

int main(void)
{
	int i = 0;

	for (i = 0; i < 15; i++)
	{
		printf("i=%d\n", i + 1);
	}

	getchar();
	return 0;
}