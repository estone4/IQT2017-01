#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#include <errno.h>
#include <assert.h>

int main(void)
{
	int a = 0;
	int b = 0;
	int c = 0;
	float root1 = 0;
	float root2 = 0;
	double realPart = 0;
	double imaginaryPart = 0;
	
	printf("Input a, b, and c to solve a quadratic equation. \n");
	scanf("%ix^2+%ix+%i=0", &a, &b, &c);

	int determinant = b ^ 2 - 4 * a*c;

	if (determinant > 0)
	{
		root1 = (-b + sqrt(determinant)) / (2 * a);
		root2 = (-b - sqrt(determinant)) / (2 * a);

		printf("root1 = %.2lf and root2 = %.2lf\n", root1, root2);
	}
	else if (determinant == 0)
	{
		root1 = root2 = -b / (2 * a);

		printf("root1 = root2 = %.2lf\n", root1);
	}
	else
	{
		realPart = -b / (2 * a);
		imaginaryPart = sqrt(-determinant) / (2 * a);
		printf("root1 = %.2lf+%.2lfi and root2 = %.2lf-%.2lfi\n", realPart, imaginaryPart, realPart, imaginaryPart);
	}

	getchar();
	getchar();
	return 0;
}