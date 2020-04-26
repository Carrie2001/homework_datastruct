#include "horse_run.h"
#include <iostream>

bool pass(int pos[], bool board[][len])
{
	if (pos[0] >= 0 && pos[0] < len && pos[1] >= 0 && pos[1] < len && !board[pos[0]][pos[1]])
		return 1;
	return 0;
}

int add[len*2]{ -2,1,-1,2,1,2,2,1,2,-1,1,-2,-1,-2,-2 ,-1 };
int found = 0;

void find_The_Way(bool board[][len], int& steps, Stack& way , int &count)
{
	if (count)
		return;
	if (steps >= len * len +1) {
		count++;
		return;
	}
	int cur[2];
	GetTop(way, cur);
	if (!pass(cur,board) )
	{
		return; // 不符题意
	}
	board[cur[0]][cur[1]] = 1; 
	/* 以下是穷举的8种可能的情况： */
	for (size_t i = 0; i < 8; i++)
	{
		int nex[2];
		nex[0] = cur[0] + add[ 2*i];
		nex[1] = cur[1] + add[ 2*i+1];
		Push(way, nex);
		steps++;
		find_The_Way(board, steps , way,count);
		if (count)
			return;
		Pop(way);
		steps--;
	}
	board[cur[0]][cur[1]] = 0; // 此位置清空，没有走马
}

void let_Horse_Fly(int pos[])
{
	bool board[len][len]{0};
	Stack way; InitStack_Sq(way);
	Push(way, pos);
	int steps = 1; int count = 0;
	find_The_Way(board, steps, way,count);
	Pop(way);
	Stack re; InitStack_Sq(re);
	
	for (size_t i = 0; i < 64; i++)
	{
		int tem[2];
		pop_And_Return(way, tem);
		Push(re, tem);
	}
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			int tem[2];
			pop_And_Return(re, tem);
			std::cout <<" "<< tem[0]+1 << ' ' << tem[1]+1<<" ->";
		}
		std::cout<< std::endl;
	}
}
