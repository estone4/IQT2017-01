//#include "student_header.h"

int sort_int_array(int * intArray, int arrayLen)
{

	if (!intArray)
	{
		
		return -1;
	}
	else
	{
		if (arrayLen < 2)
		{
			return -2;
		}

		int temp = 0;
		for (int i = 0; i < arrayLen; i++)
		{
			for (int j = 0; j < (arrayLen - i - 1); j++)
			{
				if (intArray[j] < intArray[j + 1])
				{
					temp = intArray[j];
					intArray[j] = intArray[j + 1];
					intArray[j + 1] = temp;
				}
			}
		}
		return 0;
	}
}