#include <stdio.h>;

int main(void)
{
	int userInput = 0;
	printf("Please enter a character: ");
	userInput = getc(stdin);
	//printf("%c ", --userInput);
	putc(--userInput, stdout);

	getchar();
	return 0;

}