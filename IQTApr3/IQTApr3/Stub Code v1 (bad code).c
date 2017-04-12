////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////// PERFORMANCE LAB I.7.A-2 /////////////////////////////////////////////
///////////////////////////////////////////////// ARRAYS OF STRUCTS ////////////////////////////////////////////////
////////////////////////////////////// "Good Order, Discipline, and Structure" /////////////////////////////////////
/////////////////////////////////////////////// Stub Code (bad code) ///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Reaccomplish (or modify) Performance Lab I.5.a-5 (see below) with the following stipulations:
//     Define a struct to test counting_array() (see below) from Performance Lab I.5.a-5
//     Utilize an array of struct pointers to store all of the structs you create as tests
//     Only Address Arithmetic is permitted
//     Write at least one test to cover every requirement
//     Print the human-readable output
//     Use of the dot operator (.) is expressly FORBIDDEN.  You are only allowed to use the arrow (->) operator
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////// PERFORMANCE LAB I.5.A-5 ////////////////////////////////////////////
//////////////////////////////////////////////////// POINTER ARRAYS ////////////////////////////////////////////////
////////////////////////////////////////////// "Good Order and Discipline" /////////////////////////////////////////
/////////////////////////////////////////////// Stub Code (bad code) ///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// The student is required to write tests in main() that will test counting_array()
// The version of counting_array() in this solution will rarely pass tests, if at all
// The student will write parallel arrays of test parameters for counting_array() which, at a minimum, includes:
//     inputStartingNumbers - A parallel integer array of "starting numbers"
//     inputEndingNumbers - A parallel integer array of "ending numbers"
//     expectedErrorCodes - A parallel integer array of expected "error codes"
//     expectedIntArrays - A parallel array of integer arrays which holds the expected output
// Execution of the testing should be accomplished by looping through the parallel arrays.  Each iteration of the
//     loop should:
//         1. Invoke counting_array() with a starting number, an ending number, and an integer pointer to store
//             the resulting errorCode.
//         2. Test the dereferenced value of the integer pointer against what is expected.
//         3. Test the returned integer pointer against what is expected.
//         4. Report the results:
//             Printing "Pass" (and counting it) is sufficient when a test passes.
//             On a failed test, print the test that failed (e.g., Return Value, errorCode), print "FAIL",
//             print the expected output, and print the value that was found/received.
//         5. Count the number of passes and the number of tests (for a summary)
// At the end of all the testing, print (in a human-readable format) the total number of tests that were run and
//     the total number of tests that passed.
// 
// TESTING SPECIFICATIONS
// Write one test for each of the following conditions:
// Test #		startingNumber		endingNumber		expectedErrorCode
// 1.			x					y					0
// 2.			a					y					0
// 3.			a					b					0
// 4.			y					x					-2
// 5.			b					a					-2
// 6.			y					a					-2
// NOTE 1:  If a < b < 0 < x < y
// NOTE 2:  The values of a, b, x, and y don't have to be the same each time.  In fact, it's best for testing
//     if they're not always the same.
// All reference to arrays and the elements of those arrays *MUST* be accomplished utilizing
//     Address Arithmetic (AKA pointer math).  e.g., *NO* "myArray[i]" is permitted.
//
// NOTE:  counting_array() has been written with good code *and* bad code so that students can practice both
//     conditions as they write their tests.  This version of counting_array() happens to be the version that 
//     will likely fail all tests as listed.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#elif defined(__linux__) || defined(__unix__)
#include <unistd.h>
#endif

/*
 * FUNCTION:   int * counting_array(int startingNumber, int endingNumber, int * errorCode)
 *
 * ARGUMENTS:  First, it's important to note that successful execution of counting_array() will result
 *                 in an integer array filled with values starting with "startingNumber" and ending in
 *                 "endingNumber".  The dimension of this integer array is determined by these values.
 *                 Successful execution of counting_array() will result a pointer to an integer array
 *                 with a dimension equal to (endingNumber - startingNumber + 1);
 *			   startingNumber indicates the value of index 0 within the integer array mentioned above
 *             endingnumber indicates the value of the last index within the integer array mentioned above
 *             errorCode is an integer pointer to store the errorCode provided by counting_array() (see NOTES)
 *
 * RETURNS:	   On success, integer pointer to an integer array of dimension (endingNumber - startingNumber + 1).
 *                 The values of the integer array found at the integer pointer will be sequential.
 *                 If the return pointer is stored in int * returnArray_ptr, the following statements 
 *                 will be true:
 *                     returnArray_ptr[0] == startingNumber;
 *                     returnArray_ptr[endingNumber - startingNumber] == endingNumber;
 *                     returnArray_ptr[0] + 1 == returnArray_ptr[1];
 *             On failure, counting_array() returns NULL.  (see errorCode description for examples of
 *                 potential failures)
 *
 * NOTES:      Error Codes:
 *                 0 on success
 *                 -2 if startingNumber is greater than endingNumber
 *                 -3 for all other errors (this may not be a testable condtion.  
 */
int * counting_array(int startingNumber, int endingNumber, int * errorCode);

/*
 *  INSERT STRUCT HERE
 */

int main(void)
{
	puts("You still need to write struct pointer arrays to test counting_array()"); // Remove this

	return 0;
}

/*
 * FUNCTION:   int * counting_array(int startingNumber, int endingNumber, int * errorCode)
 *
 * ARGUMENTS:  First, it's important to note that successful execution of counting_array() will result
 *                 in an integer array filled with values starting with "startingNumber" and ending in
 *                 "endingNumber".  The dimension of this integer array is determined by these values.
 *                 Successful execution of counting_array() will result a pointer to an integer array
 *                 with a dimension equal to (endingNumber - startingNumber + 1);
 *			   startingNumber indicates the value of index 0 within the integer array mentioned above
 *             endingnumber indicates the value of the last index within the integer array mentioned above
 *             errorCode is an integer pointer to store the errorCode provided by counting_array() (see NOTES)
 *
 * RETURNS:	   On success, integer pointer to an integer array of dimension (endingNumber - startingNumber + 1).
 *                 The values of the integer array found at the integer pointer will be sequential.
 *                 If the return pointer is stored in int * returnArray_ptr, the following statements
 *                 will be true:
 *                     returnArray_ptr[0] == startingNumber;
 *                     returnArray_ptr[endingNumber - startingNumber] == endingNumber;
 *                     returnArray_ptr[0] + 1 == returnArray_ptr[1];
 *             On failure, counting_array() returns NULL.  (see errorCode description for examples of
 *                 potential failures)
 *
 * NOTES:      Error Codes:
 *                 0 on success
 *                 -2 if startingNumber is greater than endingNumber
 *                 -3 for all other errors (this may not be a testable condtion.
 */
int * counting_array(int startingNumber, int endingNumber, int * errorCode)
{
	/* WRITE SOME BAD CODE HERE */
	int * returnValue_ptr = NULL;	// Return value variable
	int randomErrorCode = 0;		// Return error code variable
	int i = 0;						// Iterating variable
//	int j = 0;						// Iterating variable
	int tempArrayDimension = 0;		// Variable which holds the calculated dimension of the int array to return
	int randomAlgorithm = 0;		// Variable which stores randomized algorithm to execute WRT the int array
	int tempIndexNumber = 0;		// Variable used to temporarily store an index number
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
	randomErrorCode = sign * (rand() % (90318 - 1)) + 1; // Randomize an error code

	if (!errorCode)					// If the int pointer is NULL...
	{
		returnValue_ptr = NULL;		// ...set the return value as NULL and...
//		randomErrorCode = -1;		// ...set the error code variable to -1
	}
	if (startingNumber > endingNumber)	// If the start number is greater than the end number...
	{
		returnValue_ptr = NULL;			// ...set the return value as NULL and...
//		randomErrorCode = -2;			// ...set the error code variable to -2
	}
	else // Otherwise, the parameters are fine (so far)
	{
		tempArrayDimension = endingNumber - startingNumber + 1; // Compute the dimension of the int array to return

		/* Paranoid error check */
		if (tempArrayDimension > 0) // If the calculated dimension is valid...
		{
			/* AVAILABLE ALGORITHMS */
			// 1. NULL Pointer; Error Code 0
			// 2. Unitialized Memory; Random Error Code
			// 3. Pointer to appropriately sized memory, zeroized; Random Error Code
			// 4. Pointer to appropriately sized memory, backwards values; Random Error Code
			// 5. Pointer to appropriately sized memory, random values; Random Error Code
			// 6. Pointer to appropriately sized memory, appropriate values (first element is wrong); Error Code 0
			// 7. Pointer to appropriately sized memory, appropriate values (middle element is wrong); Random Error Code
			// 8. Pointer to appropriately sized memory, appropriate values (last element is wrong); Random Error Code
			// 9. Pointer to appropriately sized memory, appropriate values (random element is wrong); Random Error Code
			// 10. Pointer to appropriately sized memory, appropriate values; Random Error Code
			// 11. Pointer to appropriately sized memory, appropriate values; Appropriate Error Code

			/* RESPONSE CONSTRUCTION */
			/* Randomize an algorithm to use */
			randomAlgorithm = (rand() % 11) + 1; // Randomize from 1 to 10

			/* A. Memory Allocation */
			switch (randomAlgorithm) // To allocate or not to allocate?  That is the question.
			{
			case 1:		// Return a NULL pointer regardless
				returnValue_ptr = NULL;
				randomErrorCode = 0;
				break;
			case 2:		// Return a pointer to unitialized memory
				returnValue_ptr = (int *)malloc((sizeof(int) * tempArrayDimension));
				break;
			default:	// Return a pointer to initiailzed memory
				returnValue_ptr = (int *)calloc(tempArrayDimension, sizeof(int)); // Dynamically allocate initialized memory into an appropriately sized int array
				break;
			}

			if (returnValue_ptr)
			{
				/* B. Memory Values */
				switch (randomAlgorithm) // To assign values or not to assign values?  That is the question.
				{
				case 1:		// NULL pointer so... no values to assign
				case 2:		// Leave the memory unitialized
				case 3:		// Leave the memory zeroized
					break;
				case 4:		// Initialize the array with backwards values

					/* ...initialize that int array with the appropriate values */
					for (i = 0; i < tempArrayDimension; i++)
					{
						*(returnValue_ptr + i) = endingNumber - i;
					}

					break;
				case 5:		// Initialize the memory with random values
					/* ...initialize that int array with the appropriate values */
					for (i = 0; i < tempArrayDimension; i++)
					{
						/* Seed the rand() function */
						srand((unsigned int)i);

						/* Feed a random value into the current element */
						*(returnValue_ptr + i) = (rand() % (i + 1)); // (i + 1) to avoid "divide by 0" errors
					}
					break;
				default:	// Properly initialize memory
					/* ...initialize that int array with the appropriate values */
					for (i = 0; i < tempArrayDimension; i++)
					{
						*(returnValue_ptr + i) = (startingNumber + i);
					}
					break;
				}


				/* C. Value Tweaks */
				switch (randomAlgorithm)
				{
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
					break;
				case 6:
					if (tempArrayDimension > 0)
					{
						if (*(returnValue_ptr) != 0xDEADC0DE)
						{
							*(returnValue_ptr) = 0xDEADC0DE;
						}
						else
						{
							*(returnValue_ptr) = 0xC0DEDEAD;
						}

						randomErrorCode = 0;
					}
					break;
				case 7:
					if (tempArrayDimension > 1)
					{
						tempIndexNumber = (int)(tempArrayDimension / 2);
						if (*(returnValue_ptr + tempIndexNumber) != 0xDEADC0DE)
						{
							*(returnValue_ptr + tempIndexNumber) = 0xDEADC0DE;
						}
						else
						{
							*(returnValue_ptr + tempIndexNumber) = 0xC0DEDEAD;
						}
						tempIndexNumber = 0;
					}
					else
					{
						returnValue_ptr = NULL;
						randomErrorCode = -3;
					}
					break;
				case 8: // Last element is mangled; Random error code
					if (tempArrayDimension > 0)
					{
						tempIndexNumber = (tempArrayDimension - 1);
						if (*(returnValue_ptr + tempIndexNumber) != 0xDEADC0DE)
						{
							*(returnValue_ptr + tempIndexNumber) = 0xDEADC0DE;
						}
						else
						{
							*(returnValue_ptr + tempIndexNumber) = 0xC0DEDEAD;
						}
					}
					else
					{
						returnValue_ptr = NULL;
						randomErrorCode = -3;
					}
					tempIndexNumber = 0;
					break;
				case 9: // Random element is mangled; Random error code
					if (tempArrayDimension)
					{
						tempIndexNumber = (rand() % tempArrayDimension);
						if (tempIndexNumber >= 0 && tempIndexNumber < tempArrayDimension)
						{
							if (*(returnValue_ptr + tempIndexNumber) != 0xDEADC0DE)
							{
								*(returnValue_ptr + tempIndexNumber) = 0xDEADC0DE;
							}
							else
							{
								*(returnValue_ptr + tempIndexNumber) = 0xC0DEDEAD;
							}
						}
					}
					tempIndexNumber = 0;
					break;
				case 10: // Normal behavior; Proper int pointer to an int array; Random error code
					break;
				default: // Normal behavior; Proper int pointer to an int array; Error code 0
					randomErrorCode = 0;
					break;
				}

			}
			else // Otherwise, dynamic memory allocation failed so...
			{
				returnValue_ptr = NULL; // ...return NULL and...
				randomErrorCode = -3;	// ...set the error code to -3 (which should be a very rare occurrence)
			}
		}
		else
		{
			returnValue_ptr = NULL;
		}
	}
	
	if (errorCode) // If errorCode is *NOT* NULL...
	{
		*errorCode = randomErrorCode; // ...set the value at that memory address to the error code variable value
	}
	return returnValue_ptr;
}
