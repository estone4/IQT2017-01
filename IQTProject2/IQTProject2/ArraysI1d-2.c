#include <stdio.h>

int main(void)
{
	char arrQuote[256] = {0};

	int i = 0;
	arrQuote[i] = 'B';
	arrQuote[i + 1] = 'o';
	arrQuote[i + 2] = 'b';
	arrQuote[i + 3] = 'i';
	arrQuote[i + 4] = 's';
	arrQuote[i + 5] = 'y';
	arrQuote[i + 6] = 'o';
	arrQuote[i + 7] = 'u';
	arrQuote[i + 8] = 'r';
	arrQuote[i + 9] = 'u';
	arrQuote[i + 10] = 'n';
	arrQuote[i + 11] = 'c';
	arrQuote[i + 12] = 'l';
	arrQuote[i + 13] = 'e';
	arrQuote[i + 14] = 0;


	printf("The Brits say %s \n", arrQuote);


	getchar();
	return 0;

}