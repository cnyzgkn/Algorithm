#include <stdlib.h>
#include <iostream>
#include <assert.h>

int myStrcmp(const char* str1, const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);

	while((*str1 == *str2) && *str1 != '\0' && *str2 != '\0')
	{
		str1++;
		str2++;
	}

	return *str1 - *str2;
}

int myStrlen(const char* str)
{
	assert(str != NULL);
	int count = 0;
	while(*(str++) != '\0')
		count++;
	return count;
}

char* myStrcpy(const char* src, char* dest)
{
	assert(src != NULL);
	assert(dest != NULL);
	char* ret = dest;
	while(*src != '\0')
	{
		*(dest++) = *(src++);
	}
	*dest = '\0';

	return ret;
}

char* myStrcat(char* dest, const char* src)
{
	assert(src != NULL);
	assert(dest != NULL);
	char* ret = dest;
	while(*(dest++) != '\0')
	{
	}
	while(*dest = *src)
	{
		dest++;
		src++;
	}
	*dest = '\0';
	return ret;
}

int main()
{
	char* str1 = "hello!";
	char* str2 = "world!";
	char* str3 = "hello!";
	char str4[] = "hello!";

	std::cout << "str1 length " << myStrlen(str1) << " str2 length " << myStrlen(str2) << " str3 length " << myStrlen(str3) << " str4 length " << myStrlen(str4) << std::endl ;
	std::cout << "str1 size " << sizeof(str1) << " str2 size " << sizeof(str2) << " str3 size " << sizeof(str3) << " str4 size " << sizeof(str4) << std::endl ;

	std::cout << "compare str1 str3 " << myStrcmp(str1, str3) << std::endl;
	std::cout << "compare str1 str2 " << myStrcmp(str1, str2) << std::endl;
	std::cout << "compare str1 str4 " << myStrcmp(str1, str4) << std::endl;

	char str5[] = "to be replaced";
	std::cout << "copy str1 to str5 " << myStrcpy(str1, str5) << std::endl;
	char* str6 = "to be replaced";
	//std::cout << "copy str1 to str6 " << myStrcpy(str1, str6) << std::endl; // error str6 in const area can't be changed

	char str7[] = "to be added";
	std::cout << "add str1 to str7 " << myStrcat(str7, str1) << std::endl;

	return 1;
}