#include "stack.h"

void InitStack_Sq(Stack& S, int maxsize, int incresize)

{
	S.stack = (int*)malloc(maxsize * 2 * sizeof(int)); // Ϊ˳��ջ�����ʼ�洢�ռ�
	if (!S.stack)  exit(1);                                // �洢�ռ����ʧ��
	S.top = -1;                                            // ��ջ��
	S.stacksize = maxsize;                                 // ˳��ջ�ĵ�ǰ����
	S.incrementsize = incresize;                           // �����ռ�
}

int StackLength_Sq(Stack S)
{
	return S.top + 1;
}

bool Push(Stack& S, int* e)

{  //��˳��ջ��ջ������Ԫ��e
	if (S.top == S.stacksize - 1) {
		S.stack = (int*)realloc(S.stack, (S.stacksize + S.incrementsize) * sizeof(int)); // ջ������˳��ջ�����ռ�
		if (!S.stack)     return false;                // ����洢�ռ�ʧ��
		S.stacksize += S.incrementsize;
	}
	S.stack[++S.top] = *e;                             // ջ��ָ�����ƣ�Ԫ��e��ջ
	S.stack[++S.top] = *(e + 1);
	return true;
}

bool Pop(Stack& S)// Pop_Sq
{   // ɾ��˳��ջջ��Ԫ��
	if (S.top == -1)  return false;
	S.top -= 2;
	return true;
}

bool GetTop(Stack S, int* e)
{   
	if (S.top == -1)  return false;
	*(e + 1) = S.stack[S.top];
	*e = S.stack[S.top - 1];
	return true;
}
bool StackEmpty_Sq(Stack S)
{
	if (S.top == -1)  return true;
	else return false;
}

void pop_And_Return(Stack& S, int* e)
{
	*(e + 1) = S.stack[S.top--];
	*e = S.stack[S.top--];
}
// StackEmpty_Sq