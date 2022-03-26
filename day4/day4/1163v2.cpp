#include<iostream>
#include<math.h>

using namespace std;
int LastRowmax(int** trig, int N, int col);

int main()
{
	int N;
	cin >> N;
	int** trig = new int* [N];
	int** cost = new int* [N];
	for (int row = 0; row < N; row++)
	{
		trig[row] = new int[row + 1];
		for (int col = 0; col < row + 1; col++)
		{
			cin >> trig[row][col];
		}
	}
	for (int row = 0; row < N; row++)
	{
		cost[row] = new int[row + 1];
		for (int col = 0; col < row + 1; col++)
		{
			if (row == 0)
			{
				cost[row][col] = trig[row][col];
			}
			else 
			{
				cost[row][col] = trig[row][col] + max(cost[row - 1][col - 1], cost[row - 1][col]);
			}
		}
	}
	int maxsum = 0;
	for (int col = 0; col < N; col++)
	{
		maxsum = max(maxsum, cost[N - 1][col]);
	}
	cout << maxsum << endl;
	return 0;
}