#include <stdlib.h>
#include <iostream>

/* use an array for a heap
root: a[0] 
i node: a[i] 
father node: a[(i-1)/2]
left child node: a[2i+1]
right child node: a[2i+2]
if want incremental, use max top heap
if want decremental, use min top heap
*/

/*
algorithm: sort an array a[n] with elements a[0, n-1]
1). create a max top heap in a[0, n-1] while root a[0] is biggest in a[0, n-1]
2). swap a[0] and a[n-1] so a[0, n-2] is disorder while a[n-1] is biggest and order
3). create a max top heap in a[0, n-2] while a[0] is biggest in a[0, n-2] 
4). swap a[0] and a[n-2] so a[0, n-3] is disorder while a[n-2, n-1] is biggest and order
...
*/

// assume a[start+1, end] is already a heap
// headpAdjust() let a[start, end] become a maxisum heap
void heapAdjust(int a[], int start, int end)
{
	int temp = a[start];
	for(int i = 2*start+1; i <= end; i*=2)
	{
		if(i<end && a[i] < a[i+1])
			++i; // let i point to biggest child

		if(temp > a[i])
			break; // if already bigger than child, no need to continue

		a[start] = a[i];
		start = i;
	}

	a[start] = temp;
}

void buildMaxHeap(int a[], int n)
{
	if(n <= 0 )
		return;

	for(int i = n/2; i >= 0; --i) // n/2 is the last node that has child
		heapAdjust(a, i, n);
}

void swap(int& a, int& b)
{
	a = a^b;
	b = b^a;
	a = a^b;
}

void heapSort(int a[], int n)
{
	buildMaxHeap(a, n);

	for(int i = n-1; i > 0; --i)
	{
		swap(a[0], a[i]);
		heapAdjust(a, 0, i-1);
	}
}

void printArray(int a[], int length)
{
	for(int i = 0; i < length; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	int a[] = {5, 9, 7, 13, 2, 9, 6, 10, 8, 6};
	heapSort(a, 10);
	printArray(a, 10);
}