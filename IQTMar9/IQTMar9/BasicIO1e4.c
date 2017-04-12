#include <stdio.h>;

int main(void)
{
	char testCase[] = { 'A','B','C', 'D' };
	double currentTemp[] = { 100.1234, 99.876543, 133.7, 98.6823478961 };
	int numOfRuns[] = { 500, 87, 1354684, 153158468 };
	int testerId[] = { 45, 42, 83, 103 };

	printf("%-12s\t%-9s\t%-12s\t% 12s", "Test Case", "Temp", "# of Runs", "ID of Tester");
	printf("\n------------------------------------------------------------");
	printf("\n");
	printf("%-12c\t%-12.2f\t%-12d\t%04d\n", testCase[0], currentTemp[0], numOfRuns[0], testerId[0]);
	printf("%-12c\t%-12.2f\t%-12d\t%04d\n", testCase[1], currentTemp[1], numOfRuns[1], testerId[1]);
	printf("%-12c\t%-12.2f\t%-12d\t%04d\n", testCase[2], currentTemp[2], numOfRuns[2], testerId[2]);
	printf("%-12c\t%-12.2f\t%-12d\t%04d\n", testCase[3], currentTemp[3], numOfRuns[3], testerId[3]);

	//getchar(); //Uncomment when breakpoint is removed
	return 0;
}