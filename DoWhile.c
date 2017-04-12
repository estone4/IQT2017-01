#include <stdio.h>
#include <ctype.h>


int main(void)
{
	int alphabetCount[26] = {0};
	char input = 0;
	int i = 0;

	
	printf("Enter a phrase:");
	//input = getc(stdin);
	//input = toupper(input);

	do
	{
		input = toupper(getc(stdin));
		if (input >= 65 && input <= 90)
		{
			alphabetCount[input - 65]++;
		}
		printf("%c", input);
		
	} 
	while (input != '\n');

	for (i = 0; i < 26; i++)
	{
		printf("You looped %c times.", i);
	}


}

