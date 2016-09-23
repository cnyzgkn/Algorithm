
#include <stdlib.h>
#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

const int N = 1000;

int countDuplicateNums(const vector<int>& array)
{
	bitset<N*2> BitSet(0);
	for (int i = 0; i < array.size(); i++)
	{
		if (BitSet[array[i]] == 0)
			BitSet[array[i]] = 1;
		else if (BitSet[array[i]] == 1)
			BitSet[array[i]+N] = 1;
	}
	for (int i = 0; i < N; i++)
		BitSet[i] = 0;
	return BitSet.count();
}

int main()
{
	int intArray[] = {1,2,3,4,5,2,3,2,4,5};
	vector<int> array;
	for(int i = 0; i < sizeof(intArray)/sizeof(int); i++)
	{
		array.push_back(intArray[i]);
	}
	cout << countDuplicateNums(array) << endl;
}