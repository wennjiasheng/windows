#define _CRT_SECURE_NO_WARNINGS

#include"Stack.h"

void Stackinit(Stack *pl)
{
	assert(pl);
	pl->_array = (Stacktype *)malloc(sizeof(Stack)* 3);
	if (pl->_array == NULL)
	{
		assert(0);
		return;




	}
	pl->_capacity = 3;
	pl->_top = 0;
}

void cheakStack(Stack *pl)
{
	assert(pl);
	if (pl->_top == pl->_capacity)
	{
		int ret = pl->_capacity * 2;
		Stack *_new = (Stack *)malloc(sizeof(Stack)* ret);
		if (_new == NULL)
		{
			assert(0);
			return;
		}
		memcpy(_new, pl->_array, sizeof(Stack)*pl->_capacity);
		pl->_capacity = ret;
	}
}
void Stackpushback(Stack *pl, Stacktype data)
{
	assert(pl);
	cheakStack(pl);
	pl->_top++;
	pl->_array[pl->_top-1] = data;
}
void Stackpop(Stack *pl)
{
	assert(pl);
	pl->_top--;
}
int Stacktop(Stack *pl)
{
	assert(pl);
	return pl->_array[pl->_top - 1];
}
int Stackp(Stack *pl)
{
	assert(pl);
	if (pl->_top == 0)
	{
		return 0;
	}
	return 1;
}
int StackSize(Stack *pl)
{
	assert(pl);
	return pl->_capacity;
}
void Stackdestroy(Stack *pl)
{
	assert(pl);
	pl->_top = 0;
	free(pl->_array);
	pl->_array = NULL;
}

void test()
{
	Stack s;
	Stackinit(&s);
	Stackpushback(&s, 1);
	Stackpushback(&s, 2);
	Stackpushback(&s, 3);
	printf("top = %d  Size = %d\n", Stacktop(&s), StackSize(&s));
	Stackpushback(&s, 4);
	Stackpushback(&s, 5);
	printf("top = %d  Size = %d\n", Stacktop(&s), StackSize(&s));
	Stackpop(&s);
	printf("top = %d  Size = %d\n", Stacktop(&s), StackSize(&s));
	int ret = Stackp(&s);
	if (ret == 0)
	{
		printf("Õ»Îª¿Õ£º>\n");
	}
	else
	{
		printf("Õ»²»Îª¿Õ£º>\n");
	}
	Stackdestroy(&s);
}