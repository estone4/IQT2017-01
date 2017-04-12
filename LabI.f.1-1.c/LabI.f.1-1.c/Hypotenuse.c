#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

int main(void)
{
	double legA = 0;
	double legB = 0;
	double hypotenuse = 0;

	fprintf(stdout, "Input values for legs A and B of a right triangle: \n");
	fscanf(stdin,"%s, %s", legA, legB);
	_flushall();
	fscanf(stdin,"%lf %lf", legA, legB);

	hypotenuse = sqrt((legA*legA) + (legB*legB));
	printf("The hypotenuse is %.2lf", hypotenuse);
	
	getchar();
	return 0;

}