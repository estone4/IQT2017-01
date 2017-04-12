// Write formatted strings to a file
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	FILE * myFile_ptr = fopen("MyFile.txt", "w");


	char userName[40] = { 0 };
	int studentID = 0;
	float studentGPA = 0;

	_flushall();

	printf("Enter a username\n");
	scanf("%s", &userName);

	printf("Enter a studentID\n");
	scanf("%i", &studentID);

	printf("Enter a GPA\n");
	scanf("%f", &studentGPA);


	fprintf(myFile_ptr, "%s, %i, %.2f", userName, studentID, studentGPA);
	fclose(myFile_ptr);
	getchar();
	getchar();
	return 0;
}