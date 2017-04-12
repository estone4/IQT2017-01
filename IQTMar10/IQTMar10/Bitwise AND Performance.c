#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
	const uint8_t flagAir = 128;	//10000000
	const uint8_t flagEarth = 64;	//01000000
	const uint8_t flagWind = 32;	//00100000
	const uint8_t flagFire = 16;	//00010000
	const uint8_t flagWater = 8;	//00001000
	const uint8_t flagH2O = 4;		//00000100
	const uint8_t flagLava = 2;		//00000010
	const uint8_t flagTornado = 1;	//00000001

	uint8_t flags = 0;

	do
	{
		printf("Enter a number 1-255 which represents the forces of nature \nEnter 0 to exit.\n");
		_flushall();
		scanf("%"SCNu8, &flags);
		printf("Your object:		%"PRIu8"\n", flags);
		printf("Air:			%d 128\n", (flags & flagAir) > 0);
		printf("Earth:			%d 64\n", (flags & flagEarth) > 0);
		printf("Wind:			%d 32\n", (flags & flagWind) > 0);
		printf("Fire:			%d 16\n", (flags & flagFire) > 0);
		printf("Water:			%d 8\n", (flags & flagWater) > 0);
		printf("H2O:			%d 4\n", (flags & flagH2O) > 0);
		printf("Lava:			%d 2\n", (flags & flagLava) > 0);
		printf("Tornado:		%d 1\n\n\n", (flags & flagTornado) > 0);
	} while (flags && flags != 48);
	

	return 0;
}