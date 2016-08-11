#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

typedef std::pair<char, int> StrIntPair;
typedef std::map<char, int> StrIntMap;

std::string loadFileIntoString(const std::string& filename)
{
	std::ifstream file(filename);
	std::stringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}

int CountElementInStr(const char element, const StrIntMap& strMap)
{
	auto iter = strMap.find(element);
	if(iter!= strMap.end()) // find element
		return iter->second;
	else
		return 0;
}

StrIntMap initStrIntMap(const std::string& str)
{
	StrIntMap strMap;
    for(auto i : str){
		if(strMap.count(i) == 0)
			strMap.insert(StrIntPair(i, 0));
		else
		{
			StrIntMap::iterator iter = strMap.find(i);
			(iter->second)++;
		}
	}
    return strMap;
}

int main()
{
	std::string str = loadFileIntoString("/Users/cnyzgkn/Git/Algorithm/ElementInBigFile/content.txt");
	std::cout << str << std::endl;
	StrIntMap strMap = initStrIntMap(str);

	int n = CountElementInStr('a', strMap);
	std::cout << "a appears " << n << " times" << std::endl;

	return 1;
}