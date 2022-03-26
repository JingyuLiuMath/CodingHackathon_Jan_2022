#include<iostream>
#include<string>
#include<math.h>
#include<queue>

using namespace std;

int num = 0;

queue<int> qrow;
queue<int> qcol;

int searchx[4] = { 1,-1,0,0 };
int searchy[4] = { 0,0,1,-1 };

void BFS(int** board, int W, int H);

int main()
{
	// initialize
	int W, H;
	cin >> W >> H;
	while (W != 0 || H != 0)
	{
		while (!qrow.empty()) qrow.pop();
		while (!qcol.empty()) qcol.pop();
		string temp;
		int** board = new int* [H];
		for (int i = 0; i < H; i++)
		{
			cin >> temp;
			board[i] = new int[W];
			for (int j = 0; j < W; j++)
			{
				if (temp[j] == '#')
					board[i][j] = 0;
				else if (temp[j] == '@')
				{
					qrow.push(i);
					qcol.push(j);
					board[i][j] = 0;
				}
				else
					board[i][j] = 1;
			}
		}
		// start
		num = 1;
		BFS(board, W, H);
		cout << num << endl;
		cin >> W >> H;
	}
	return 0;
}

void BFS(int** board, int W, int H)
{
	while (1)
	{
		int nowrow = qrow.front();
		int nowcol = qcol.front();
		qrow.pop();
		qcol.pop();
		for (int search = 0; search < 4; search++)
		{
			if (nowrow + searchx[search] < H && nowrow + searchx[search] >= 0
				&& nowcol + searchy[search] < W && nowcol + searchy[search] >= 0)
			{
				if (board[nowrow + searchx[search]][nowcol + searchy[search]] == 1)
				{
					qrow.push(nowrow + searchx[search]);
					qcol.push(nowcol + searchy[search]);
					num += 1;
					board[nowrow + searchx[search]][nowcol + searchy[search]] = 0;
				}
			}
		}
		if (qrow.empty())
		{
			break;
		}
	}
}