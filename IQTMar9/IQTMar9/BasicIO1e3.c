#include <stdio.h>;

int main(void)
{
	char buff[10];
	printf("Please enter a string: ");
	fgets(buff, sizeof(buff), stdin);
	printf("Your string was: ");
	puts(buff);

	//getchar();
	return 0;
}