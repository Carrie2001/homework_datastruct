#include "stack.h"

int InitStack(SqStack* s1)
{
	s1->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!s1->base)
		exit(1);
	s1->top = s1->base;
	s1->stacksize = STACK_INIT_SIZE;
	return (1);
}

SElemType Pop(SqStack* s, SElemType m){
	m = *(--s->top);
	return m;
}

int Push(SqStack* s1, SElemType m)
{
	if (s1->top - s1->base >= s1->stacksize)
	{
		s1->base = (SElemType*)realloc(s1->base, (s1->stacksize + n) * sizeof(SElemType));
		if (!s1->base)
			exit(1);
		s1->top = s1->base + s1->stacksize;
		s1->stacksize += n;
	}
	*(s1->top++) = m;
	return 1;
}

int StackEmpty(SqStack* s){
	if (s->base == s->top)
		return (1);
	else
		return (0);
}