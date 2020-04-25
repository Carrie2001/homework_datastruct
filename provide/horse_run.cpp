#include "horse_run.h"

Coordinate move[8] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-1,-1} };

int Pass(Coordinate s,int chessboard[][8])
{
	if (!chessboard[s.x][s.y]&& (s.x <= 7) && (s.x >= 0)&& (s.y <= 7) && (s.y >= 0))
		return 1;
	else
		return 0;
}

Coordinate NextPos(Coordinate s, int i)
{
	s.x = s.x + move[i].x;
	s.y = s.y + move[i].y;
	return(s);
}

void let_Horse_Fly(Coordinate start, int chessboard[][8])
{
	int step = 0;
	SqStack way;
	SElemType top_tem;
	Coordinate curpos = start;
	InitStack(&way);

	do
	{
		if (Pass(curpos,chessboard))
		{
			step++;
			chessboard[curpos.x][curpos.y] = step;
			top_tem.seat = curpos;
			top_tem.ord = step;
			top_tem.di = 0;
			Push(&way, top_tem);
			if (step == 64)
				break;
			else
				curpos = NextPos(curpos, top_tem.di);
		}
		else
		{
			if (!StackEmpty(&way))
			{
				Pop(&way, top_tem);
				while (top_tem.di == 7 && !StackEmpty(&way))
				{
					chessboard[top_tem.seat.x][top_tem.seat.y] = 0;//恢复原态
					top_tem = Pop(&way, top_tem);	 //往前回溯
					step = top_tem.ord;			//恢复原态
				}
				if (top_tem.di < 7) //穷举所有可能
				{
					top_tem.di++;
					Push(&way, top_tem);
					curpos = NextPos(top_tem.seat, top_tem.di);
				}
			}
		}
	} while (!StackEmpty(&way));
}



