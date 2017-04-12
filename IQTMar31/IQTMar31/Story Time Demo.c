#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <errno.h>
#define LENGTH 60
#define ROWS 14


void error_reporting(int currErrno);

int main(void)
{
	FILE * myStory_ptr = fopen("custard-the-dragon.txt", "r");
	char userInput = 0;
	char tempBuff[ROWS][LENGTH] = { 0 };
	char * tempReturn = tempBuff;
	int i = 0;
	int j = 0;
	char currentChar = 0;
	int currentErrno = errno;
	//char *strerror(int  errnum);

	if (!myStory_ptr)
	{
		puts("Could not open the file.");
		return -1;
	}
	else
	{
		// printf("Write a story.\nThe escape character is Ctrl-D.\n\n");
		_flushall();
		i = 0;
		for (i = 0; i <= ROWS; i++)
		{
			tempReturn = fgets(tempBuff[i], LENGTH, myStory_ptr);
		}

		fclose(myStory_ptr);
	}
	i = 0;
	j = 0;
	for (i = 0; i < ROWS; i++)
	{
		printf("%s", tempBuff[i]);
	}
		
	myStory_ptr = fopen("bob-the-builder.txt", "r");

	if (!myStory_ptr)
	{
		error_reporting(currentErrno);
		return currentErrno;
		/*puts("Could not reopen file.");
		return -1;*/
	}
	else
	{
		puts("\n\nFile Contents:");
		while (!feof(myStory_ptr))
		{
			currentChar = getc(myStory_ptr);
			putchar(currentChar);
			/*userInput = getc(myStory_ptr);
			if (userInput == 0x4 || userInput == EOF)
			{
				break;
			}
			putchar(userInput);*/
		}
		fclose(myStory_ptr);
	}

	getchar();
	getchar();
	return 0;
}

void error_reporting(int currErrno)
{
	perror(currErrno);
}