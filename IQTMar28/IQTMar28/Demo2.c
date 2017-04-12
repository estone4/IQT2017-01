/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// DEMONSTRATION LAB I.5.A-2 //////////////////////////////////////////////
///////////////////////////////////////////////////// ARRAYS ////////////////////////////////////////////////////////
//////////////////////////////////////////// "Allen Telescope Array" ////////////////////////////////////////////////
////////////////////////////////////////////// Instructor Solution //////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Declare four char arrays of dimension 8 named radioTelescope{1-4}
//     e.g., radioTelescope1[8], radioTelescope2[8], etc.
// Define the char arrays with ATA_042, ATA_098, ATA_206, ATA_350 respectively
// Declare a char pointer variable, named char_ptr
// Set and then dereference the pointer variable to change index 3 to 0x2D in each char array
//     radioTelescope1[3] = 0x2D;  // NOT PERMITTED... dereference a pointer!
// Print all of the char arrays in a human-readable format
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

/* NULL was registering as "undefined" for some reason */
#ifndef NULL
#define NULL ((void*) 0)
#endif /* NULL */

/*
*  #define SOLUTION0   // Easy, yet inefficient, solution; Default implementation lacking *any* #defines
*  #define SOLUTION1	// Moderate, yet inefficient, solution; Utilizes "Address Arithmetic"
*  #define SOLUTION2	// Efficient use of char pointer array
*/
#define SOLUTION2
#define BUFF_SIZE 8 // Standardized buffer size throughout the source code

int main(void)
{
	/********************/
	/* DEFINE VARIABLES */
	/********************/
	char radioTelescope1[BUFF_SIZE] = { "ATA_042" };
	char radioTelescope2[BUFF_SIZE] = { "ATA_098" };
	char radioTelescope3[BUFF_SIZE] = { "ATA_206" };
	char radioTelescope4[BUFF_SIZE] = { "ATA_350" };

	char * char_ptr = NULL; // Character pointer variable defined with NULL

							/*****************/
							/* MODIFY ARRAYS */
							/*****************/
#ifdef SOLUTION1
	char_ptr = radioTelescope1;		// Char pointer variable assigned with address of array
	*(char_ptr + 3) = 0x2D;			// Address arithmetic used to dereference the memory address of index 3 and modify it
	char_ptr = radioTelescope2;		// Char pointer variable assigned with address of array
	*(char_ptr + 3) = 0x2D;			// Address arithmetic used to dereference the memory address of index 3 and modify it
	char_ptr = radioTelescope3;		// Char pointer variable assigned with address of array
	*(char_ptr + 3) = 0x2D;			// Address arithmetic used to dereference the memory address of index 3 and modify it
	char_ptr = radioTelescope4;		// Char pointer variable assigned with address of array
	*(char_ptr + 3) = 0x2D;			// Address arithmetic used to dereference the memory address of index 3 and modify it
#elif defined(SOLUTION2)
							/*
							*  An array of char pointers has been initialized to add eficiency to this process instead of
							*      copy-paste coding
							*/
	char * radioTelescopeArray[4] = { radioTelescope1, radioTelescope2, radioTelescope3, radioTelescope4 };
	int i = 0; // Incremementing variable

	for (i = 0; i < 4; i++)					// Iteratres through the char pointer array...
	{
		char_ptr = radioTelescopeArray[i];	// ...sets the address of each char array to the char pointer in turn and...
		*(char_ptr + 3) = 0x2D;				// ...then utilizes address arithmetic to dereference the memory address of index 3 and modify it 
	}
#else // SOLUTION0
	char_ptr = &radioTelescope1[3];	// Sets the address of index 3 to the char pointer variable			
	*char_ptr = 0x2D;				// Dereferences that memory address and modifies it
	char_ptr = &radioTelescope2[3];	// Sets the address of index 3 to the char pointer variable			
	*char_ptr = 0x2D;				// Dereferences that memory address and modifies it
	char_ptr = &radioTelescope3[3];	// Sets the address of index 3 to the char pointer variable			
	*char_ptr = 0x2D;				// Dereferences that memory address and modifies it
	char_ptr = &radioTelescope4[3];	// Sets the address of index 3 to the char pointer variable			
	*char_ptr = 0x2D;				// Dereferences that memory address and modifies it
#endif

									/*********************/
									/* PRINT CHAR ARRAYS */
									/*********************/
#ifdef SOLUTION2
	for (i = 0; i < 4; i++)							// Iteratres through the char pointer array...
	{
		printf("Radio Telescope #%d:\t", i + 1);	// Print a human-readable header...
		puts(radioTelescopeArray[i]);				// ...then print the null-terminated string listed in the char pointer array
	}
#else // Non-SOLUTION2
	printf("Radio Telescope #1:\t");				// Print a human-readable header
	puts(radioTelescope1);							// Print the null-terminated string listed in the char pointer array
	printf("Radio Telescope #2:\t");				// Print a human-readable header...
	puts(radioTelescope2);							// Print the null-terminated string listed in the char pointer array
	printf("Radio Telescope #3:\t");				// Print a human-readable header...
	puts(radioTelescope3);							// Print the null-terminated string listed in the char pointer array
	printf("Radio Telescope #4:\t");				// Print a human-readable header...
	puts(radioTelescope4);							// Print the null-terminated string listed in the char pointer array
#endif

	return 0;
}