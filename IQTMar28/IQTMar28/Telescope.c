//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// MQT (I.5.A) PERFORMANCE LAB 2 ///////////////////////////////////////////
/////////////////////////////////////////////////////// ARRAYS ///////////////////////////////////////////////////////
//////////////////////////////////////////// "Telescope Array Project" ///////////////////////////////////////////////
///////////////////////////////////////////////////// Stub Code //////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// The following stub code defines four non-null-terminated character arrays
// Each array stores the map coordinates, in Degrees Mintues Seconds (DMS) format, of a 
//     "Telescope Array Project" station (https://en.wikipedia.org/wiki/Telescope_Array_Project)
// The coordinates are not listed complete with degrees (o), minutes ('), and seconds ("")
// The student must modify each char array to change the underscores (_) to the appropriate symbol
// For each array:
//     Index 3 and index 17 must be changed to 0xF8, the degree symbol (or 0xB0, depending on the implementation)
//     Index 7 and index 21 must be changed to 0x27, the apostrophe
//     Index 11 and index 25 must be changed to 0x22, the double apostrophe
// The students may only modify the char arrays using dereferenced pointers
//     (the exact reasoning will become clear later in this objective)
//     (SPOILER:  "pass by reference")
// After the modifications have been made, print all four char arrays in a human-readable format
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

#define BUFF_SIZE 27 // Standard dimension for the four char arrays

int main(void)
{
	/* The four "Telescope Array Project" station char arrays are defined with DMS coordinates */
	// IMPORTANT NOTE:  These char arrays are (purposely) *NOT* null-terminated so take care!
	char blackRockMesaDMS[BUFF_SIZE] = { "039_011_018_N 112_042_042_W" };
	char longRidgeDMS[BUFF_SIZE] = { "039_012_028_N 113_007_017_W" };
	char middleDrumDMS[BUFF_SIZE] = { "039_028_022_N 112_059_037_W" };
	char centralLaserFacilityDMS[BUFF_SIZE] = { "039_017_049_N 112_054_031_W" };
	
	char * char_ptr = NULL;
	char * radioTelescopeArray[4] = { blackRockMesaDMS, longRidgeDMS, middleDrumDMS, centralLaserFacilityDMS };



	///////////////////////
	// MODIFY THE ARRAYS //
	///////////////////////

	char_ptr = blackRockMesaDMS;			// Char pointer variable assigned with address of array
	*(char_ptr + 3) = 0xF8;					// Address arithmetic used to dereference the memory address of index 3 and modify it
	*(char_ptr + 17) = 0xF8;
	*(char_ptr + 7) = 0x27;
	*(char_ptr + 21) = 0x27;
	*(char_ptr + 11) = 0x22;
	*(char_ptr + 25) = 0x22;
	char_ptr = longRidgeDMS;				// Char pointer variable assigned with address of array
	*(char_ptr + 3) = 0xF8;					// Address arithmetic used to dereference the memory address of index 3 and modify it
	*(char_ptr + 17) = 0xF8;
	*(char_ptr + 7) = 0x27;
	*(char_ptr + 21) = 0x27;
	*(char_ptr + 11) = 0x22;
	*(char_ptr + 25) = 0x22;				// Address arithmetic used to dereference the memory address of index 3 and modify it
	char_ptr = middleDrumDMS;				// Char pointer variable assigned with address of array
	*(char_ptr + 3) = 0xF8;					// Address arithmetic used to dereference the memory address of index 3 and modify it
	*(char_ptr + 17) = 0xF8;
	*(char_ptr + 7) = 0x27;
	*(char_ptr + 21) = 0x27;
	*(char_ptr + 11) = 0x22;
	*(char_ptr + 25) = 0x22;				// Address arithmetic used to dereference the memory address of index 3 and modify it
	char_ptr = centralLaserFacilityDMS;		// Char pointer variable assigned with address of array
	*(char_ptr + 3) = 0xF8;					// Address arithmetic used to dereference the memory address of index 3 and modify it
	*(char_ptr + 17) = 0xF8;
	*(char_ptr + 7) = 0x27;
	*(char_ptr + 21) = 0x27;
	*(char_ptr + 11) = 0x22;
	*(char_ptr + 25) = 0x22;				// Address arithmetic used to dereference the memory address of index 3 and modify it
	///////////////////////
	///////////////////////
	///////////////////////



	//////////////////////
	// PRINT THE ARRAYS //
	//////////////////////
	
	printf("Station 1:\t");
	for (int i = 0; i < BUFF_SIZE; i++)							// Iteratres through the char pointer array...
	{
				putchar(blackRockMesaDMS[i]);
	}
	putchar(10);

	printf("Station 2:\t");
	for (int i = 0; i < BUFF_SIZE; i++)							// Iteratres through the char pointer array...
	{
		putchar(longRidgeDMS[i]);
	}
	putchar(10);

	printf("Station 3:\t");
	for (int i = 0; i < BUFF_SIZE; i++)							// Iteratres through the char pointer array...
	{
		putchar(middleDrumDMS[i]);
	}
	putchar(10);

	printf("Station 4:\t");
	for (int i = 0; i < BUFF_SIZE; i++)							// Iteratres through the char pointer array...
	{
		putchar(centralLaserFacilityDMS[i]);
	}
	putchar(10);
	///////////////////////
	///////////////////////
	///////////////////////

	getchar();

	return 0;
}