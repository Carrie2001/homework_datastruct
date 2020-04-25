#pragma once
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define n 10
typedef struct
{
	int x;
	int y;
}Coordinate;



typedef struct
{
	int ord;
	Coordinate seat; //зјБъ
	int di;
}SElemType ,node;

typedef struct
{
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;

int  InitStack(SqStack* s1);

SElemType Pop(SqStack* s, SElemType m);

int Push(SqStack* s1, SElemType m);

int StackEmpty(SqStack* s);