/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// DEMONSTRATION LAB I.7.A-2 //////////////////////////////////////////////
//////////////////////////////////////////////// ARRAYS OF STRUCTS //////////////////////////////////////////////////
//////////////////////////////////////////// "Legilimency Structomancy" /////////////////////////////////////////////
///////////////////////////////////////// Instructor Solution (bad function) ////////////////////////////////////////
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
///////////////////////////////////////// Instructor Solution (bad function) ////////////////////////////////////////
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

struct TestInput {
	char *** array_of_string_arrays_ptr;	// Holds input for stringArray_ptr
	int number_of_strings;					// Holds input for numOfStrings
	int returned_error_code;				// Holds the error code provided by sorting_hat()
	int * returned_error_code_ptr;			// Holds the input for errorCode
	char * return_value_ptr;				// Holds the return value from sorting_hat()
	char * expected_return_value_ptr;		// Holds the return value expected from sorting_hat()
	int expected_error_code;				// Holds the expected error code provided by sorting_hat()
};

int main(void)
{
	int i = 0; // Iterating variable
	char * tempExpectedOutput = NULL; // Variable used to protect automated tests from dereferencing NULL pointers
	int numTotalTests = 0;  // Overall number of tests
	int numTestsRun = 0;	// Number of tests run
	int numTestsPassed = 0; // Number of tests that passed
	struct TestInput * currentTest_ptr = NULL;

	/*
	 *  TEST INPUT BEGIN
	 */

	/* Normal Input 1 */
	char * testInputArray0[] = { "String one", "String 2", "String three", "String beans", "String him up!" };
	struct TestInput test0;
	test0.array_of_string_arrays_ptr = testInputArray0;
	test0.number_of_strings = sizeof(testInputArray0) / sizeof(*(testInputArray0));
	test0.returned_error_code = 0x90C05;							// Default value
	test0.returned_error_code_ptr = &(test0.returned_error_code);
	test0.return_value_ptr = "90COS";								// Default value to test for NULL pointers
	test0.expected_return_value_ptr = *(testInputArray0 + 1);
	test0.expected_error_code = 0;

	/* Normal Input 2 */
	char * testInputArray1[] = { "Slytherin", "Ravenclaw", "Hufflepuff", "Gryffindor" };
	struct TestInput test1;
	test1.array_of_string_arrays_ptr = testInputArray1;
	test1.number_of_strings = sizeof(testInputArray1) / sizeof(*(testInputArray1));
	test1.returned_error_code = 0x90C05;							// Default value
	test1.returned_error_code_ptr = &(test1.returned_error_code);
	test1.return_value_ptr = "90COS";								// Default value to test for NULL pointers
	test1.expected_return_value_ptr = *(testInputArray1 + 3);
	test1.expected_error_code = 0;

	/* Matching Strings 1 */
	char * testInputArray2[] = { "Not a match", "a match", "A match", "Still not a match", "Testing is fun?", "Who said that?!" };
	struct TestInput test2;
	test2.array_of_string_arrays_ptr = testInputArray2;
	test2.number_of_strings = sizeof(testInputArray2) / sizeof(*(testInputArray2));
	test2.returned_error_code = 0x90C05;							// Default value
	test2.returned_error_code_ptr = &(test2.returned_error_code);
	test2.return_value_ptr = "90COS";								// Default value to test for NULL pointers
	test2.expected_return_value_ptr = *(testInputArray2 + 1);
	test2.expected_error_code = 0;

	/* Matching Strings 2 */
	char * testInputArray3[] = { "X-ray", "Victory", "Uniform", "bubba", "Bubblegum", "bubba", "Something, something dark side." };
	struct TestInput test3;
	test3.array_of_string_arrays_ptr = testInputArray3;
	test3.number_of_strings = sizeof(testInputArray3) / sizeof(*(testInputArray3));
	test3.returned_error_code = 0x90C05;							// Default value
	test3.returned_error_code_ptr = &(test3.returned_error_code);
	test3.return_value_ptr = "90COS";								// Default value to test for NULL pointers
	test3.expected_return_value_ptr = *(testInputArray3 + 3);
	test3.expected_error_code = 0;

	/* NULL String Array 1 */
	char ** testInputArray4 = NULL;
	struct TestInput test4;
	test4.array_of_string_arrays_ptr = testInputArray4;
	test4.number_of_strings = 1337;
	test4.returned_error_code = 0x90C05;							// Default value
	test4.returned_error_code_ptr = &(test4.returned_error_code);
	test4.return_value_ptr = "90COS";								// Default value to test for NULL pointers
	test4.expected_return_value_ptr = NULL;
	test4.expected_error_code = -1;

	/* NULL String Array 2 */
	char ** testInputArray5 = NULL;
	struct TestInput test5;
	test5.array_of_string_arrays_ptr = testInputArray5;
	test5.number_of_strings = 42;
	test5.returned_error_code = 0x90C05;							// Default value
	test5.returned_error_code_ptr = &(test5.returned_error_code);
	test5.return_value_ptr = "90COS";								// Default value to test for NULL pointers
	test5.expected_return_value_ptr = NULL;
	test5.expected_error_code = -1;

	/* One NULL String in the Array 1 */
	char * testInputArray6[] = { "abc", "123", "You and me", "We can be", NULL };
	struct TestInput test6;
	test6.array_of_string_arrays_ptr = testInputArray6;
	test6.number_of_strings = sizeof(testInputArray6) / sizeof(*(testInputArray6));
	test6.returned_error_code = 0x90C05;							// Default value
	test6.returned_error_code_ptr = &(test6.returned_error_code);
	test6.return_value_ptr = "90COS";								// Default value to test for NULL pointers
	test6.expected_return_value_ptr = NULL;
	test6.expected_error_code = -1;

	/* One NULL String in the Array 2 */
	char * testInputArray7[] = { NULL, "One", "Two", "Three", "Four", "I declare a thumb war!" };
	struct TestInput test7;
	test7.array_of_string_arrays_ptr = testInputArray7;
	test7.number_of_strings = sizeof(testInputArray7) / sizeof(*(testInputArray7));
	test7.returned_error_code = 0x90C05;							// Default value
	test7.returned_error_code_ptr = &(test7.returned_error_code);
	test7.return_value_ptr = "90COS";								// Default value to test for NULL pointers
	test7.expected_return_value_ptr = NULL;
	test7.expected_error_code = -1;

	/* Passed an Invalid Number of Strings 1 (negative) */
	char * testInputArray8[] = { "This", "test", "passes", "an", "invalid", "value", "for", "the", "number", "of", "strings that are in this array.", "numOfStrings is negative" };
	struct TestInput test8;
	test8.array_of_string_arrays_ptr = testInputArray8;
	test8.number_of_strings = -1337;
	test8.returned_error_code = 0x90C05;							// Default value
	test8.returned_error_code_ptr = &(test8.returned_error_code);
	test8.return_value_ptr = "90COS";								// Default value to test for NULL pointers
	test8.expected_return_value_ptr = NULL;
	test8.expected_error_code = -2;

	/* Passed an Invalid Number of Strings 2 (negative) */
	char * testInputArray9[] = { "This", "test", "passes", "an", "invalid", "value", "for", "the", "number", "of", "strings that are in this array.", "numOfStrings is negative" };
	struct TestInput test9;
	test9.array_of_string_arrays_ptr = testInputArray9;
	test9.number_of_strings = -42;
	test9.returned_error_code = 0x90C05;							// Default value
	test9.returned_error_code_ptr = &(test9.returned_error_code);
	test9.return_value_ptr = "90COS";								// Default value to test for NULL pointers
	test9.expected_return_value_ptr = NULL;
	test9.expected_error_code = -2;

	/* Passed an Invalid Number of Strings 1 (zero) */
	char * testInputArray10[] = { "This", "test", "passes", "an", "invalid", "value", "for", "the", "number", "of", "strings that are in this array.", "numOfStrings is zero" };
	struct TestInput test10;
	test10.array_of_string_arrays_ptr = testInputArray10;
	test10.number_of_strings = 0x0;
	test10.returned_error_code = 0x90C05;							// Default value
	test10.returned_error_code_ptr = &(test10.returned_error_code);
	test10.return_value_ptr = "90COS";								// Default value to test for NULL pointers
	test10.expected_return_value_ptr = NULL;
	test10.expected_error_code = -2;

	/* Passed an Invalid Number of Strings 2 (zero) */
	char * testInputArray11[] = { 0 };
	struct TestInput test11;
	test11.array_of_string_arrays_ptr = testInputArray11;
	test11.number_of_strings = 0x0;
	test11.returned_error_code = 0x90C05;							// Default value
	test11.returned_error_code_ptr = &(test11.returned_error_code);
	test11.return_value_ptr = "90COS";								// Default value to test for NULL pointers
	test11.expected_return_value_ptr = NULL;
	test11.expected_error_code = -2;

	/* Passed an Invalid Number of Strings 1 (one) */
	char * testInputArray12[] = { "This", "test", "passes", "an", "invalid", "value", "for", "the", "number", "of", "strings that are in this array.", "numOfStrings is one" };
	struct TestInput test12;
	test12.array_of_string_arrays_ptr = testInputArray12;
	test12.number_of_strings = 0x1;
	test12.returned_error_code = 0x90C05;							// Default value
	test12.returned_error_code_ptr = &(test12.returned_error_code);
	test12.return_value_ptr = "90COS";								// Default value to test for NULL pointers
	test12.expected_return_value_ptr = NULL;
	test12.expected_error_code = -2;

	/* Passed an Invalid Number of Strings 2 (one) */
	char * testInputArray13[] = { "One" };
	struct TestInput test13;
	test13.array_of_string_arrays_ptr = testInputArray13;
	test13.number_of_strings = 0x1;
	test13.returned_error_code = 0x90C05;							// Default value
	test13.returned_error_code_ptr = &(test13.returned_error_code);
	test13.return_value_ptr = "90COS";								// Default value to test for NULL pointers
	test13.expected_return_value_ptr = NULL;
	test13.expected_error_code = -2;

	/* Array of Input Values */
	struct TestInput * arrayOfTestStructs[] = { \
		&test0, &test1, &test2, \
		&test3, &test4, &test5, \
		&test6, &test7, &test8, \
		&test9, &test10, &test11, \
		&test12, &test13
	};
	numTotalTests = sizeof(arrayOfTestStructs) / sizeof(*(arrayOfTestStructs));

	/*
	 *  TEST INPUT STOP
	 */


	/*
	 *  TESTING LOOP START
	 */
	for (i = 0; i < numTotalTests; i++) // For each struct
	{
		printf("\n****************\n*** TEST #%02d ***\n****************\n", i); // ...print a human-readable header and...
		/* Define current test input struct */
		currentTest_ptr = *(arrayOfTestStructs + i);

		/* ...call sorting_hat() with the parameters from the array of struct pointers and... */
		currentTest_ptr->return_value_ptr = sorting_hat(currentTest_ptr->array_of_string_arrays_ptr, currentTest_ptr->number_of_strings, currentTest_ptr->returned_error_code_ptr);
		/* ...store the result in a char pointer variable... */

		/* RETURN VALUE TEST */
		numTestsRun++; // ...increment the number of tests run and...
		printf("Return Value:\t"); // ...print more human-readable headers and...

		if (currentTest_ptr->expected_return_value_ptr == currentTest_ptr->return_value_ptr) // If the returned pointer is equivalent to the expected pointer...
		{
			printf("Pass\n"); // ...all is well...
			numTestsPassed++; // ...and this test passed.
		}
		else // Otherise
		{
			printf("FAIL\n\t"); // Print the human-readable result...
			printf("Expected:\t"); // Tell the user what was expected...
			if (currentTest_ptr->expected_return_value_ptr) // If the expected output is a pointer...
			{
				printf("%p\n", currentTest_ptr->expected_return_value_ptr); // ...print the pointer
			}
			else // Otherwise, the expected output is NULL so...
			{
				printf("%p\n", NULL); // ...print NULL
			}
			printf("\tReceived:\t"); // Tell the user what was actually received...
			if (currentTest_ptr->return_value_ptr) // If the returned value is a pointer...
			{
				printf("%p\n", currentTest_ptr->return_value_ptr); // ...print the pointer
			}
			else // Otherwise, the pointer is NULL...
			{
				printf("%p\n", NULL); // ...so print NULL
			}
		}

		/* ERROR CODE TEST */
		numTestsRun++; // Increment the number of tests run
		printf("Error Code:\t"); // Print human-readable header
		if (currentTest_ptr->expected_error_code == currentTest_ptr->returned_error_code) // If the current error code matches what was expected...
		{
			printf("Pass\n"); // ...tell the user and...
			numTestsPassed++; // ...record that fact
		}
		else // Otherise, they don't match so...
		{
			printf("FAIL\n\t"); // ...tell the user and...
			printf("Expected:\t%d\n\t", currentTest_ptr->expected_error_code); // ...tell them what the expected error code is and...
			printf("Received:\t%d\n", currentTest_ptr->returned_error_code); // ...tell them what the actual error code was
		}
		/*
		 *  TESTING LOOP STOP
		 */
	}

	/* HUMAN READABLE TEST SUMMARY */
	if (numTestsRun) // If main() recorded some tests...
	{
		printf("\n\n%d tests were run.\n%d tests passed.\n\n", numTestsRun, numTestsPassed); // ...tell the user how they did
	}

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
