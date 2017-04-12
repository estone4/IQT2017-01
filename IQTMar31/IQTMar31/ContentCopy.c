#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define LENGTH 60
#define ROWS 14

int main(void)
{
	FILE * myStory_ptr = fopen("custard-the-dragon.txt", "r");
	FILE * myNewFile_ptr = fopen("new_file.txt", "w");
	FILE * myReadFile_ptr = fopen("new_file.txt", "r");
	char userInput = 0;
	char tempBuff[ROWS][LENGTH] = { 0 };
	char * tempReturn = tempBuff;
	int i = 0;
	int j = 0;
	char readFileVar = 0;

	if (!myStory_ptr)
	{
		puts("Could not open the file.");
		return -1;
	}
	else
	{
		_flushall();
		i = 0;
		while ((readFileVar = fgetc(myStory_ptr)) != EOF)
		{
			if (readFileVar)
			{
				fputc(readFileVar, myNewFile_ptr);
			}
		}

		fclose(myStory_ptr);
		fclose(myNewFile_ptr);

		myNewFile_ptr = fopen("new_file.txt", "r");
		
		while ((readFileVar = getc(myNewFile_ptr)) != EOF)
		{
			 putc(readFileVar, stdout);
		}
		fclose(myNewFile_ptr);
		
	}

	getchar();
	getchar();
	return 0;
}