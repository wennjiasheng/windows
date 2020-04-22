#include<iostream>

using namespace std;
struct ListNode
{
	int val;
	struct ListNode* next;
};


class solution
{
public:
	ListNode* ReverseList(ListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;
		ListNode* pCurent, *pPrev, *pNext;
		pCurent = pHead;
		pPrev = NULL;

		while (pCurent != NULL)
		{
			pNext = pCurent->next;
			if (pNext == NULL)
			{
				pCurent->next = pPrev;
				return pCurent;
			}
			pCurent->next = pPrev;
			pPrev = pCurent;
			pCurent = pNext;
		}
	}
};

int main()
{
	ListNode *L;
	ListNode *r, *p;
	L = new ListNode;
	r = L;
	for (int i = 0; i<5; i++)
	{
		p = new ListNode;
		p->val = i;
		r->next = p;
		r = p;
	}
	r->next = NULL;
	solution s;
	s.ReverseList(L);
	system("pause");
	return 0;
}