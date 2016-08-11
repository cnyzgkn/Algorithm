#include <stdio.h>
#include <iostream>

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void printArray(int array[], int length)
{
	for(int i = 0; i < length; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

// O(nlg(n))
void quickSort1(int array[], int left, int right)
{
	//std::cout << "quickSort1 Start " << left << " left " << right << " right" << std::endl;
	if(left >= right)
		return;

	int pivot = array[left];
	int m = left;  //m is the position for middle element
	for(int i = left+1; i <= right; i++)
	{
		if(array[i] < pivot)
		{
			swap(array[++m], array[i]);
			//printArray(array, 10);
		}
	}
	swap(array[left], array[m]);
	//std::cout << "quickSort1 End " << left << " left " << right << " right" << std::endl;
	//printArray(array, 10);

	quickSort1(array, left, m-1);
	quickSort1(array, m+1, right);
}

// bi-direction to avoid average element reduce to O(n2) problem
void quickSort2(int array[], int left, int right)
{
	if(left >= right)
		return;

	int pivot = array[left];
	int j = right+1;
	for(int i = left; i <= j; )
	{
		do {
			i++;
		} while(i <= right && array[i] < pivot);
		do {
			j--;
		}while(array[j] > pivot);
		
		if(i > j)
			break;
		swap(array[i],array[j]);
	}
	swap(array[left], array[j]);

	quickSort2(array, left, j-1);
	quickSort2(array, j+1, right);
}

int main()
{
	int array1[] = {5, 9, 7, 13, 2, 15, 6, 10, 8, 6};
	quickSort1(array1, 0, 9);
	printArray(array1, 10);

	int array2[] = {5, 9, 7, 13, 2, 15, 6, 10, 8, 6};
	quickSort2(array2, 0, 9);
	printArray(array2, 10);
}