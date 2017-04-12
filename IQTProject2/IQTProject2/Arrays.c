#include <stdio.h>


int main(void)
{
	int arrClassAges[9] = {0};
	char arrQuote[4] = {0};

	int i = 0;
	arrClassAges[i] = 24;
	arrClassAges[i + 1] = 41;
	arrClassAges[i + 2] = 25;
	arrClassAges[i + 3] = 23;
	arrClassAges[i + 4] = 20;
	arrClassAges[i + 5] = 27;
	arrClassAges[i + 6] = 29;
	arrClassAges[i + 7] = 35;
	arrQuote[i] = 'T';
	arrQuote[i + 1] = 'i';
	arrQuote[i + 2] = 'm';

	printf(" %d \n", arrClassAges[i]);
	printf(" %d \n", arrClassAges[i + 1]);
	printf(" %d \n", arrClassAges[i + 2]);
	printf(" %d \n", arrClassAges[i + 3]);
	printf(" %d \n", arrClassAges[i + 4]);
	printf(" %d \n", arrClassAges[i + 5]);
	printf(" %d \n", arrClassAges[i + 6]);
	printf(" %d \n", arrClassAges[i + 7]);
	printf(" %c \n", arrQuote[0]);
	printf(" %c \n", arrQuote[1]);
	printf(" %c \n", arrQuote[2]);

	getchar();
	return 0;
}
