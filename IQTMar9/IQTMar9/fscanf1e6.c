#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{

	int year = 0;
	char month[4] = { 0 };
	int day = 0;

	fprintf(stdout, "Enter the current long format date as YYYY-Mmm-DD \n");
	_flushall();
	fscanf(stdin, "%4i-%3s-%2i", &year, &month, &day);
	fprintf(stdout, "The current date is %i-%s-%i \n", year, month, day);
	fprintf(stdout, "AMURICA: \t%s %i, %i \n", month, day, year);
	fprintf(stdout, "Spain: \t\t%i de %s de %i \n", day, month, year);
	fprintf(stdout, "Japan: \t\t%i%c%s%c%i \n", year, 4, month, 4,day);
	fprintf(stdout, "All Others: \t%i %s %i \n", day, month, year);

	return 0;
}