#include <stdlib.h>

struct node
{
	node(int data): next(NULL), mData(data) {};
	node* next;
	int mData;
};

class list
{
public:
	list(): mFirst(NULL), mLast(NULL) {};
	void Add(int data);
	void Clear();

	node* mFirst;
	node* mLast;
};

void list::Add(int data)
{
	node* pNode = new node(data);
	if(mFirst == NULL)
	{
		mFirst = mLast = pNode;
	}else
	{
		mLast->next = pNode;
		mLast = pNode;
	}
}

void list::Clear()
{
	node* pNode = mFirst;
	while(pNode != NULL)
	{
		node* pNext = pNode->next;
		delete pNode;
		pNode = pNext;
	}
    mFirst = mLast = NULL;
}