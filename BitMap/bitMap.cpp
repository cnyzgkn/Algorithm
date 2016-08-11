/*
bitmap适合处理在受限内存中处理极大数字问题，思路是用字符串表示整数，0的位表示不存在，1的位表示存在
如0 1 1 1 0 1 0 0 1 0 0 0 0 1 0 0 0 0 0 0 可表示{1,2,3,5,8,13}，集合中为1的代表整数集合中的该数
条件：
1.输入数据在相对较小的范围内；
2.数据无重复；
3.只有单一整数
*/

// question: 受限内存空间（如1MB）空间里面对m个整数进行排序，并且每个数都小于n
// uncomplete: using template

#include <stdlib.h>
#include <iostream>
#include <set>


// generate a set containing m int elements all smaller than n (m<n)
std::set<long int> initRandomSet(long int m, long int n)
{
	std::set<long int> intSet;
	while(true)
	{
		int value = rand() % n;
		intSet.insert(value);
		if(intSet.size() == m)
			break;
	}
	return intSet;
}

// create a bitset for n element
std::bitset<1000> initBitSet(long int m, long int n, std::set<long int> intSet)
{
	std::bitset<1000> intBitSet;
	for(long int i = 0; i < n; i++)
	{
		if(intSet.count(i) != 0)
		{
			intBitSet.set(i);
		}
	}
	return intBitSet;
}

void printBitSet(std::bitset<1000> intBitSet)
{
	for(long int i = 0; i < intBitSet.size(); i++)
	{
		if(intBitSet[i] == 1)
			std::cout << i << std::endl;
	}
}

int main()
{
	std::set<long int> intSet = initRandomSet(100, 1000);
	std::bitset<1000> intBitSet = initBitSet(100, 1000, intSet);
	printBitSet(intBitSet);
}