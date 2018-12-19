#include <iostream>
#include "list.h"

void printList(const list& l)
{
	node* pNode = l.mFirst;
	while(pNode)
	{
		std::cout << pNode->mData << std::endl;
		pNode = pNode->next;
	}
}

// using 3 extra pointers to reverse pCurrent -> pNext -> pOther to pCurrent <- pNext <- pOther
void ReverseListLoop1(list& l)
{
	if(l.mFirst == NULL || l.mFirst == l.mLast)
		return;

	node* pCurrent = l.mFirst; 
	node* pNext = pCurrent->next;
	node* pOther = NULL; //ptr for next step
	l.mFirst->next = NULL; // first points to last so next points to NULL
	l.mLast = l.mFirst;

	while(pNext != NULL)
	{
		pOther = pNext->next;
		pNext->next = pCurrent;
		pCurrent = pNext;
		pNext = pOther;
	}
	l.mFirst = pCurrent; // pNext will point to NULL at last so use it as new head
}

// loop all element and insert each one after the first one, at last insert first one to last
// 1) p0 -> p1 -> p2 -> p3 -> p4
// 2) p0 -> p2 -> p1 -> p3 -> p4
// 3) p0 -> p3 -> p2 -> p1 -> p4
// 4) p0 -> p4 -> p3 -> p2 -> p1
// 5) p4 -> p3 -> p2 -> p1 -> p0
void ReverseListLoop2(list& l)
{
    if(l.mFirst == NULL || l.mFirst == l.mLast)
        return;
    
    node* pCurrent = l.mFirst->next;
    node* pNext = NULL;
    
    while(pCurrent->next != NULL)
    {
        pNext = pCurrent->next;
        pCurrent->next = pNext->next;
        pNext->next = l.mFirst->next;
        l.mFirst->next = pNext;
    }
    
    pCurrent->next =l.mFirst;
    l.mFirst = pCurrent->next->next;
    pCurrent->next->next = NULL;
}

// p0 -> p1 -> p2 -> p3 -> p4
// assume p1 -> p2 -> p3 -> p4 has already reversed, so reverse p0 and other
// using this way recursively
void ReverseListRecursive(node* head, node* pNode)
{
    if(pNode->next==NULL)
    {
        head->next=pNode;
        return;//找到最后一个节点
    }
    
    ReverseListRecursive(head, pNode->next);
    pNode->next->next=pNode;//反转节点
    pNode->next=NULL;//第一个节点反转后其后继应该为NULL
}

int main()
{
	list l;
	l.Add(0);
	l.Add(1);
	l.Add(2);
	l.Add(3);
	l.Add(4);
	printList(l);
    
    ReverseListLoop1(l);
	printList(l);
    
    ReverseListLoop2(l);
    printList(l);
    
    ReverseListRecursive(l.mFirst, l.mFirst->next);
    printList(l);
    
    l.Clear();
}