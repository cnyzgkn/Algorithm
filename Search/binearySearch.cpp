#include <stdlib.h>
#include <iostream>

void printArray(int array[], int length)
{
	for(int i = 0; i < length; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

int binearySearchLoop(const int array[], int begin, int end, int element)
{
	while(begin <= end)
	{
		int middle = (begin + end)/2;
		if(element < array[middle])
			end = middle-1;
		else if (element > array[middle])
			begin = middle+1;
		else return middle;
	}
	return -1;
}

int binearySearchRecursive(const int array[], int begin, int end, int element)
{
	if(begin >= end)
		return begin;

	int middle = (begin + end)/2;
	if(element < array[middle])
		return binearySearchRecursive(array, begin, middle-1, element);
	else if (element > array[middle])
		return binearySearchRecursive(array, middle+1, end, element);
	else return middle;

	return -1;
}

int main()
{
	int array[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
	int m = binearySearchLoop(array, 0, 9, 70);
	std::cout << "n = " << m << std::endl;

	int n = binearySearchRecursive(array, 0, 9, 70);
	std::cout << "n = " << n << std::endl;
}