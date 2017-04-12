/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// DEMONSTRATION LAB I.7.A-2 //////////////////////////////////////////////
//////////////////////////////////////////////// ARRAYS OF STRUCTS //////////////////////////////////////////////////
//////////////////////////////////////////// "Legilimency Structomancy" /////////////////////////////////////////////
///////////////////////////////////////////// Stub Code (bad function) //////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Define a struct to test sorting_hat() from Demonstration Lab I.5.a-5 (see below)
// Only Address Arithmetic is permitted
// Write at least one test to cover the following sorting_hat() requirements:
//     Normal input
//     Alpahbetically ordered strings match
//     stringArray_ptr is NULL
//     At least one NULL pointer within stringArray_ptr
//     numOfStrings is negative
//     numOfStrings is zero (0)
//     numOfStrings is one (1)
// Remember, all non-NULL char pointers must dereference to null-terminated strings
// All tests must display human-readable parameters and results
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////// DEMONSTRATION LAB I.5.A-5 /////////////////////////////////////////////
////////////////////////////////////////////////// POINTER ARRAYS ///////////////////////////////////////////////////
/////////////////////////////////////////////////// "Legilimency" ///////////////////////////////////////////////////
///////////////////////////////////////////// Stub Code (bad function) //////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// The student is required to write tests in main() that will test sorting_hat()
// The version of sorting_hat() in this solution is 100% functional
// The student will write parallel arrays of test parameters for sorting_hat()
//     char ** stringArray_ptr - An array of string arrays (not a typo) is necessary to pass to sorting_hat()
//     int numOfStrings - A parallel integer array of numOfStrings will need to hold the number of strings 
//         each string array holds
//     int * errorCode - No array is needed for the memory address, merely passing the memory address of an
//         integer variable should suffice
// The student must also write parallel arrays to test the expected output of sorting_hat()
//     "character pointer" return value - A parallel array of character pointers is necessary to test the return
//         values of sorting_hat()
//     errorCode - A parallel integer array of expected errorCodes is also necessary to test sorting_hat()
// Execution of the testing should be accomplished by looping through the parallel arrays.  Each iteration of the
//     loop should:
//         1. Invoke sorting_hat() with an array of strings, the number of the strings in that array, and 
//             an integer pointer to store the resulting errorCode.
//         2. Test the return value of sorting_hat() against what is expected.
//         3. Test the errorCode value against what is expected.
//         4. Report the results:
//             Printing "Pass" (and counting it) is sufficient when a test passes.
//             On a failed test, print the test that failed (e.g., Return Value, errorCode), print "FAIL",
//             print the expected output, and print the value that was found/received.
//         5. Count the number of passes and the number of tests (for a summary)
// At the end of all the testing, print (in a human-readable format) the total number of tests that were run and
//     the total number of tests that passed.
// The student will not be testing convert_char_to_lower()
// 
// TESTING SPECIFICATIONS
// Write two tests for each of the following conditions:
//     1. Normal input
//     2. The array of strings passed to sorting_hat() include alphabetically 'first' matching strings 
//         NOTE: The first matching strings should be returned
//     3. Pass a NULL pointer as stringArray_ptr
//     4. Pass a NULL pointer as one of the strings found in the array of strings passed to sorting_hat()
//     5. Pass an normal array of strings but pass a negative number as the number of strings in the array (numOfStrings)
//     6. Pass an normal array of strings but pass a zero (0) as the number of strings in the array (numOfStrings)
//     7. Pass an normal array of strings but pass a one (1) as the number of strings in the array (numOfStrings)
// *ALL* non-NULL char pointers must dereference to null-terminated strings (otherwise sorting_hat() will crash)
// All reference to arrays and the elements of those arrays *MUST* be accomplished utilizing
//     Address Arithmetic (AKA pointer math).  e.g., *NO* "myArray[i]" is permitted.
//
// NOTE:  sorting_hat() has been written with good code *and* bad code so that students can practice both conditions
//     as they write their tests.  This version of sorting_hat() happens to be the version that randomly answers
//     incorrectly more often than it guesses the correct response to a given test.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#elif defined(__linux__) || defined(__unix__)
#include <unistd.h>
#endif


/*
 * FUNCTION:   char * sorting_hat(char ** stringArray_ptr, int numOfStrings, int * errorCode)
 *
 * ARGUMENTS:  stringArray_ptr is a pointer to array of char pointers.  Those char pointers happen to
 *                 be null-terminated strings.
 *             numOfStrings indicates the number of strings that can be found in the array of char pointers
 *                 found at stringArray_ptr
 *             errorCode is an integer pointer to store the errorCode provided by sorting_hat() (see below)
 *
 * RETURNS:	   On success, char pointer to the null-terminated string found within stringArray_ptr that would
 *                 come first, alphabetically.  For example, if stringArray_ptr dereferenced to:
 *                 "A", "B", "C", and "D", then sorting_hat() should return a pointer to "A".
 *             On failure, sorting_hat() returns NULL.  (see errorCode description for examples of
 *                 potential failures)
 *
 * NOTES:      Error Codes:
 *                 0 on success
 *                 -1 if *ANY* pointer is NULL (this includes stringArray_ptr or any of the char pointers
 *                     found within stringArray_ptr)
 *                 -2 if numOfStrings is unrealistic (see: less than 2 strings in stringArray_ptr
 *                 -3 for all other errors (this may not be a testable condtion.  Currently, sorting_hat()
 *                     only utilizes Error Code -3 in the highly unlikely even that convert_char_to_lower() fails
 *                     somehow)
 */
char * sorting_hat(char ** stringArray_ptr, int numOfStrings, int * errorCode);

/*
 * FUNCTION:   char convert_char_to_lower(char letter)
 *
 * ARGUMENTS:  letter is a character to be converted to a lower-case alphabet letter, if appropriate
 *
 * RETURNS:	   On success, convert_char_to_lower() returns the modified character.  If "char letter" is an
 *                 upper-case letter, this function will return the lower-case version of "char letter".  If
 *                 "char letter" is *NOT* an upper-case letter, this function will merely return "letter"
 *                 as a 'pass through', if you will.
 *             On error, convert_char_to_lower() returns 0.  As a consequence, this function will not accept 
 *                 '\0' (0x0) as a value of "letter" and will return 0.
 *
 * NOTES:      This function is very simple and should not provide any errors.
 */
char convert_char_to_lower(char letter);

/*
 *  PLACE STRUCT HERE
 */

int main(void)
{
	puts("You still need to write an array of struct pointers to test sorting_hat()"); // Remove this

	return 0;
}

/*
 * FUNCTION:   char * sorting_hat(char ** stringArray_ptr, int numOfStrings, int * errorCode)
 *
 * ARGUMENTS:  stringArray_ptr is a pointer to array of char pointers.  Those char pointers happen to
 *                 be null-terminated strings.
 *             numOfStrings indicates the number of strings that can be found in the array of char pointers
 *                 found at stringArray_ptr
 *             errorCode is an integer pointer to store the errorCode provided by sorting_hat() (see below)
 *
 * RETURNS:	   On success, char pointer to the null-terminated string found within stringArray_ptr that would
 *                 come first, alphabetically.  For example, if stringArray_ptr dereferenced to:
 *                 "A", "B", "C", and "D", then sorting_hat() should return a pointer to "A".
 *             On failure, sorting_hat() returns NULL.  (see errorCode description for examples of
 *                 potential failures)
 *
 * NOTES:      Error Codes:
 *                 0 on success
 *                 -1 if *ANY* pointer is NULL (this includes stringArray_ptr or any of the char pointers
 *                     found within stringArray_ptr)
 *                 -2 if numOfStrings is unrealistic (see: less than 2 strings in stringArray_ptr
 *                 -3 for all other errors (this may not be a testable condtion.  Currently, sorting_hat()
 *                     only utilizes Error Code -3 in the highly unlikely even that convert_char_to_lower() fails
 *                     somehow)
 */
char * sorting_hat(char ** stringArray_ptr, int numOfStrings, int * errorCode)
{
	char * randomReturnValue_ptr = NULL;	// Variable used to store the function's random return value
	
	/* Attempt to Sleep */
#ifdef _WIN32
	Sleep(1000);
#elif defined(__linux__) || defined(__unix__)
	sleep(1);
#endif
	
	/* Seed the rand() function */
	srand((unsigned int)time(NULL));

	/* Randomize a 'sign' */
	int sign = (rand() % (2));
	if (!sign)
	{
		sign -= 1;
	}

	/* Randomize an Error Code */
	int randomErrorCode = (sign)* (rand() % (90318 - 1)) + 1; // Randomize an error code

	/* Pointers to return if stringArray_ptr is NULL */
	static char * randomResponsePointers[] = { "This isn't working.", "This function is broken!", "Why are you looking at this?", "You shouldn't even be able to read these.", "No." };

	/* Randomize a randomResponsePointer just in case */
	int randomArrayIndex = 0;
	
	if (!stringArray_ptr || !errorCode || (numOfStrings < 2)) // If one of the parameters are 'off'...
	{
		/* Randomize an index from randomResponsePointers */
		randomArrayIndex = (rand() % (sizeof(randomResponsePointers) / sizeof(*(randomResponsePointers))));
		/* Set the return value as a pointer to a randomResponsePointer */
		randomReturnValue_ptr = *(randomResponsePointers + randomArrayIndex);
	}
	else // Otherwise, the function parameters are fine so...
	{
		/* Randomize an index from stringArray_ptr */
		randomArrayIndex = (rand() % (numOfStrings));
		/* Set the return value as a pointer to a random string from stringArray_ptr */
		randomReturnValue_ptr = *(stringArray_ptr + randomArrayIndex);
	}

	/* Set random errorCode */
	if (errorCode)						// If the errorCode pointer is *NOT* NULL...
	{
		*errorCode = randomErrorCode;				// ...set the error code as random...
	}

	return randomReturnValue_ptr;
}

/*
 * FUNCTION:   char convert_char_to_lower(char letter)
 *
 * ARGUMENTS:  letter is a character to be converted to a lower-case alphabet letter, if appropriate
 *
 * RETURNS:	   On success, convert_char_to_lower() returns the modified character.  If "char letter" is an
 *                 upper-case letter, this function will return the lower-case version of "char letter".  If
 *                 "char letter" is *NOT* an upper-case letter, this function will merely return "letter"
 *                 as a 'pass through', if you will.
 *             On error, convert_char_to_lower() returns 0.  As a consequence, this function will not accept
 *                 '\0' (0x0) as a value of "letter" and will return 0.
 *
 * NOTES:      This function is very simple and should not provide any errors.
 */
char convert_char_to_lower(char letter)
{
	char returnValue = 0;	// REturn value variable

	if (!letter)			// If letter is '\0' (0x0)...
	{
		returnValue = 0;	// ...set the return value to 0x0
	}
	else if (letter >= 0x41 && letter <= 0x5A) // Otherwise, if the input letter is a capital alphabet letter...
	{
		returnValue = letter + 0x20; // ...'shift' it to its equivalent lower-case value
	}
	else					// Otherwise, it's not '\0' (0x0) and it's not a capital letter so...
	{
		returnValue = letter; // ...just set the return value to "letter" since the function doesn't need to do anything
	}

	return returnValue;
}
