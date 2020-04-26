#pragma once
#include <stdlib.h>
# define STACK_INIT_SIZE  100      // ˳��ջ (Ĭ�ϵ�)�ĳ�ʼ�����������
# define STACKINCREMENT  10        // (Ĭ�ϵ�)�����ռ���

typedef struct {
	int* stack;                  // �洢����Ԫ�ص�һά����
	int top;                         // ջ��ָ��
	int stacksize;                   // ��ǰ�����������������intΪ��λ��
	int incrementsize;	           // �����ռ�������intΪ��λ��
}Stack;

void InitStack_Sq(Stack& S, int maxsize = STACK_INIT_SIZE, int incresize = STACKINCREMENT);// InitStack_Sq

int StackLength_Sq(Stack S);// StackLength_Sq


bool Push(Stack& S, int* e);// Push_Sq

bool Pop(Stack& S);

bool GetTop(Stack S, int* e);//ȡ˳��ջջ��Ԫ�أ�����e������ֵ

bool StackEmpty_Sq(Stack S);

void pop_And_return(Stack& S, int* e);