#include <stdio.h>

#define DEBUG
#ifdef DEBUG
#define DEBUG_INT(x) printf(#x " is %d", x)
#endif /* DEBUG */

int main(void)
{
	int someNum = 42;

#ifdef DEBUG
		DEBUG_INT(someNum);
#endif /* DEBUG */

	return 0;
}
