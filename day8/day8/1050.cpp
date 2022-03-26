#include<iostream>
#include<math.h>
#include<cstring>

const int inf = -40000000;

using namespace std;

int solve1D(int* line, int N);

int main()
{
	int N;
	cin >> N;
	int** rec = new int* [N + 1];
	for (int i = 0; i <= N; i++)
	{
		rec[i] = new int[N + 1];
		for (int j = 0; j <= N; j++)
		{
			rec[i][j] = 0;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> rec[i][j];
		}
	}
	int max1 = inf;
	int temp = inf;
	// 遍历i, j行之间（含）的所有矩阵
	int* line = new int[N + 1];
	for (int i = 0; i <= N; i++)
	{
		line[i] = 0;
	}
	for (int startrow = 1; startrow <= N; startrow++)
	{
		for (int i = 0; i <= N; i++)
		{
			line[i] = 0;
		}
		for (int endrow = startrow; endrow <= N; endrow++)
		{
			for (int col = 1; col <= N; col++)
			{
				line[col] += rec[endrow][col];
			}
			temp = solve1D(line, N);
			max1 = max(temp, max1);
		}
	}
	cout << max1 << endl;
	return 0;
}

int solve1D(int* line, int N)
{
	int local = line[1];
	int max1= line[1];
	for (int i = 2; i <= N; i++)
	{
		if (local < 0)
		{
			local = 0;
		}
		local += line[i];
		if (local > max1)
		{
			max1 = local;
		}
	}
	return max1;
}