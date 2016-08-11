#include <stdio.h>
#include <iostream>

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort1(int array[], int length)
{
	for(int i = 0; i < length; i++)
	{
		for(int j = length-1; j > i; j--)
		{
			if(array[j-1] > array[j])
				swap(array[j], array[j-1]);
		}
	}
}

void bubbleSort2(int array[], int length)
{
	for(int i = 0; i < length; i++)
	{
		bool flag = false;
		for(int j = length-1; j > i; j--)
		{
			if(array[j-1] > array[j])
			{
				swap(array[j], array[j-1]);
				flag = true;
			}
		}
		if(!flag) return;
	}
}

void printArray(int array[], int length)
{
	for(int i = 0; i < length; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	int array1[] = {5, 9, 7, 13, 2, 9, 6, 10, 8, 6};
	bubbleSort1(array1, 10);
	printArray(array1, 10);

	int array2[] = {5, 9, 7, 13, 2, 9, 6, 10, 8, 6};
	bubbleSort2(array2, 10);
	printArray(array2, 10);
}