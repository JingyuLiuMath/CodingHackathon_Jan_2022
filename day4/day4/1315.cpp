#include<iostream>
#include<string>
#include<cstring>

using namespace std;

void DFS(string* board, int n, int start, int** visit, int depth);
bool able(string* board, int n, int currentx, int currenty, int** visit);

int depth;
int maxnum = 0;

int main()
{
	int n;
	cin >> n;
	while (n != 0)
	{
		maxnum = 0;
		string* board = new string[n];
		for (int i = 0; i < n; i++)
		{
			cin >> board[i];
		}
		// Start
		int** visit = new int*[n];
		for (int i = 0; i < n; i++)
		{
			visit[i] = new int[n];
			memset(visit[i], 0, n * sizeof(int));
		}
		/*for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for(int d = 0; d < n; d++)
					memset(visit[d], 0, n * sizeof(int));
				int start = i * n + j;
				depth = 0;
				DFS(board, n, start, visit, depth);
			}
		}*/
		depth = 0;
		DFS(board, n, 0, visit, depth);
		cout << maxnum << endl;
		cin >> n;
	}
	return 0;
}

void DFS(string* board, int n, int start, int** visit, int depth)
{
	int total = n * n;
	for (int current = start; current < total; current++)
	{
		int currentx = current / n;
		int currenty = current % n;
		if (able(board, n, currentx, currenty, visit))
		{
			visit[currentx][currenty] = 1;
			if (depth + 1 > maxnum)
				maxnum = depth + 1;
			DFS(board, n, current, visit, depth +1);
			visit[currentx][currenty] = 0;
		}
	}
}

bool able(string* board, int n, int currentx, int currenty, int** visit)
{
	if (board[currentx][currenty] == 'X' || visit[currentx][currenty] == 1)
		return 0;
	// 竖直方向
	int x = currentx - 1;
	while (x >= 0 && board[x][currenty] != 'X')
	{
		if (visit[x][currenty] == 1)
			return 0;
		x -= 1;
	}
	// 水平方向
	int y = currenty - 1;
	while (y >= 0 && board[currentx][y] != 'X')
	{
		if (visit[currentx][y] == 1)
			return 0;
		y -= 1;
	}
	return 1;
}