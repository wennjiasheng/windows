#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int DLnodetyped;
typedef struct Dlistnode
{
	struct Dlistnode *_pnext;
	struct Dlistnode *_ppre;
	DLnodetyped _data;
}node;

void DlistInit(node **Phead);
void Dlistpushback(node *Phead, DLnodetyped data);
void Dlistpopback(node *Phead);
void Dlistpushfront(node *Phead, DLnodetyped data);
void Dlistpopfront(node *Phead);
void DlistInsert(node *Phead, DLnodetyped pos, DLnodetyped data);
void DlistErase(node *Phead, DLnodetyped data);
void DlistPrint(node *Phead);
void DlistDestroy(node ** Phead);
void test()



