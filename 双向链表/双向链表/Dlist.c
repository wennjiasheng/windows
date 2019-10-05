#define _CRT_SECURE_NO_WARNINGS

#include"Dlist.h"


void DlistInit(node **Phead)
{
	assert(*Phead);
	(*Phead)->_pnext = (*Phead);
	(*Phead)->_ppre = (*Phead);
	(*Phead) = NULL;
}


node *buyDlist(int data)
{
	node *phead = (node *)malloc(sizeof(node));
	if (NULL == phead)
	{
		assert(0);
		return;
	}
	phead->_pnext = NULL;
	phead->_ppre = NULL;
	phead->_data = data;
	return phead;
}
void Dlistpushback(node *Phead, DLnodetyped data)
{
	assert(Phead);
	node* newphead = buyDlist(data);
	Phead->_ppre->_pnext = newphead;
	newphead->_ppre = Phead->_ppre->_pnext;
	Phead->_ppre = newphead;
	newphead->_pnext = Phead;

}

void Dlistpopback(node *Phead)
{
	node* delnode = NULL;
	assert(Phead);
	if (Phead == Phead->_pnext)
	{
		return;
	}
	delnode = Phead->_ppre;
	delnode->_ppre->_pnext = Phead;
	Phead->_ppre = delnode->_ppre;
	free(delnode);
	delnode = NULL;
}

void Dlistpushfront(node *Phead, DLnodetyped data)
{
	node *newnode = NULL;
	assert(Phead);
	newnode = buyDlist(data);
	newnode->_pnext = Phead->_pnext;
	newnode->_ppre = Phead;
	Phead->_pnext = newnode;
	newnode->_pnext->_ppre = newnode;
}

void Dlistpopfront(node *Phead)
{
	node* delnode = NULL;
	assert(Phead);
	if (NULL == Phead)
	{
		assert(0);
		return;
	}
	delnode = Phead->_pnext;
	Phead->_pnext = delnode->_pnext;
	delnode->_pnext->_ppre = Phead;
}


node *DlistFind(node *Phead, DLnodetyped pos)
{
	node *pcur = NULL;
	assert(Phead);
	if (NULL == Phead)
	{
		assert(0);
		return;
	}
	pcur = Phead->_pnext;
	while (pcur != Phead)
	{
		if (pcur->_data == pos)
		{
			return pcur;
		}
		pcur = pcur->_pnext;
	}
	return;
}
void DlistInsert(node *Phead, DLnodetyped pos, DLnodetyped data)
{
	node *pcur = NULL;
	node *newnode = NULL;
	assert(Phead);
	pcur = DlistFind(Phead, pos);
	newnode = buyDlist(data);
	newnode->_ppre = pcur->_ppre;
	newnode->_pnext = pcur;
	pcur->_ppre->_pnext = newnode;
	pcur->_ppre = newnode;

}

void DlistErase(node *Phead, DLnodetyped data)
{
	node *pcur = NULL;
	assert(Phead);
	pcur = DlistFind(Phead, data);
	pcur->_ppre->_pnext = pcur->_pnext;
	pcur->_pnext->_ppre = pcur->_ppre;
	free(pcur);
	pcur = NULL;
}

void DlistPrint(node *Phead)
{
	assert(Phead);
	while (Phead->_pnext != Phead)
	{
		printf("<-%d->", Phead->_data);
		Phead = Phead->_pnext;
	}
	printf("<-%d->", Phead->_data);

}
void DlistDestroy(node ** Phead)
{
	node *pcur = (*Phead)->_pnext;
	assert(*Phead);
	while (pcur != (*Phead))
	{
		free(pcur);
		pcur = pcur->_pnext;
	}
	free(*Phead);
	(*Phead) = NULL;
}

void test()
{
	node *con = NULL;
	DlistInit(&con);
	Dlistpushback(con,0);
	Dlistpushback(con, 0);
	Dlistpushback(con, 0);
	Dlistpushback(con, 0);
	Dlistpushback(con, 0);
	DlistPrint(con);
	Dlistpopback(con);
	DlistPrint(con);
	Dlistpushfront(con, 1);
	Dlistpushfront(con, 1);
	Dlistpushfront(con, 1);
	Dlistpushfront(con, 1);
	Dlistpushfront(con, 1);
	DlistPrint(con);
	Dlistpopfront(con);
	DlistPrint(con);
	DlistInsert(con, 3, 2);
	DlistPrint(con);
	DlistErase(con,3);
	DlistPrint(con);
	DlistDestroy(&con);
}