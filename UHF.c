#include <stdio.h>

int main(void)
{
	char arrMovieQuote[256] = "You get to drink from the firehose.";
	float productionYear = 1989;
	float amazonPrice = 9.62;
	int i = 0;

	while (arrMovieQuote[i])
	{
		printf("%c", arrMovieQuote[i]);
		i++;
	}
	//printf("My favorite movie quote is '%s' from %.0f on Amazon for $%.2f", arrMovieQuote, productionYear, amazonPrice);

	getchar();
	return 0;

}