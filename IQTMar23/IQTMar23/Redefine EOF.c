#include <stdio.h>

//#define DEBUG										// Comment it out to skip DEBUG macros
#if !defined (DEBUG) && defined (_INC_STDIO)		// If the DEBUG macro is defined…
#define PRINT_MACRO(x)  printf(#x " is %d \n", x) 
#endif


#ifdef EOF
#undef EOF
#define EOF 66
#endif

int main(void)
{

#ifndef DEBUG
	PRINT_MACRO(FOPEN_MAX);
	PRINT_MACRO(FILENAME_MAX);
	PRINT_MACRO(EOF);
#endif // !DEBUG
	
	getchar();
	return 0;
}