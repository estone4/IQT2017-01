#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int alphabetCounter[26] = { 0 };
	char inputChar = 0;
	int i = 0;

	printf("Type a sentence and press Enter. \n");
	do
	{
		inputChar = getchar();
		inputChar = toupper(inputChar);
		if (inputChar >= 'A' && inputChar <= 'Z')
		{
			alphabetCounter[inputChar - (char)'A']++;
		}

	} while (inputChar != '\n');

	for ( i = 0; i < (sizeof(alphabetCounter)/sizeof(alphabetCounter[0])); i++)
	{
		printf("%c: %d \n", (char)(i + 'A'), alphabetCounter[i]);
	}
	return 0;
}