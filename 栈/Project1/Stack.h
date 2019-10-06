#pragma once

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>


typedef int Stacktype;
typedef struct Stack
{
	Stacktype* _array;
	int _capacity;
	int _top;

}Stack;


void Stackinit(Stack *pl);
void Stackpushback(Stack *pl, Stacktype data);
void Stackpop(Stack *pl);
int Stacktop(Stack *pl);
int Stackp(Stack *pl);
void Stackdoary(Stack *pl);
int StackSize(Stack *pl);

void test();


