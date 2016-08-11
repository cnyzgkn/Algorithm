#include <stdio.h>
#include <iostream>

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void insertSort(int array[], int length)
{
	for(int i = 1; i < length; i++)
	{
		for(int j = i ; j > 0 && array[j-1] > array[j]; j--)
		{
			swap(array[j], array[j-1]);
		}
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
	int array[] = {5, 9, 7, 13, 2, 9, 6, 10, 8, 6};
	printArray(array, 10);
	insertSort(array, 10);
	printArray(array, 10);
}