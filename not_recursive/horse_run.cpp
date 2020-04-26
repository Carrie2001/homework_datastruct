#include "horse_run.h"
#include <iostream>

bool pass(int pos[], bool board[][len])
{
	if (pos[0] >= 0 && pos[0] < len && pos[1] >= 0 && pos[1] < len && !board[pos[0]][pos[1]])
		return 1;
	return 0;
}

int add_x[8]{ -2,-1,1,2,2,1,-1,-2 };
int add_y[8]{ 1,2,2,1,-1,-2,-2,-1 };
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
	/* 以下是8种可能的情况： */
	for (size_t i = 0; i < 8; i++)
	{
		int nex[2];
		nex[0] = cur[0] + add_x[ i];
		nex[1] = cur[1] + add_y[ i];
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

/* 1  38  55  34   3  36  19  22
  54  47   2  37  20  23   4  17
  39  56  33  46  35  18  21  10
  48  53  40  57  24  11  16   5
  59  32  45  52  41  26   9  12
  44  49  58  25  62  15   6  27
  31  60  51  42  29   8  13  64
  50  43  30  61  14  63  28   7*/

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
		pop_And_return(way, tem);
		Push(re, tem);
	}
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			int tem[2];
			pop_And_return(re, tem);
			std::cout << tem[0] << '!' << tem[1]<<" ";
		}
		std::cout<< std::endl;
	}
}
