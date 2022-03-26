#include<iostream>
#include<math.h>

using namespace std;
int Howmax(int** trig, int N);

int main()
{
	int N;
	cin >> N;
	int** trig = new int* [N];
	for (int row = 0; row < N; row++)
	{
		trig[row] = new int[row + 1];
		for (int col = 0; col < row + 1; col++)
			cin >> trig[row][col];
	}
	int maxsum;
	maxsum = Howmax(trig, N);
	cout << maxsum << endl;
	return 0;
}

int Howmax(int** trig, int N)
{
	int max1;
	if (N == 1)
	{
		max1 = trig[0][0];
	}
	else
	{
		int** trig1 = new int* [N-1];
		int** trig2 = new int* [N-1];
		for (int nrow = 0; nrow < N - 1; nrow++)
		{
			trig1[nrow] = new int[nrow + 1];
			trig2[nrow] = new int[nrow + 1];
			for (int ncol = 0; ncol < nrow + 1; ncol++)
			{
				trig1[nrow][ncol] = trig[nrow + 1][ncol];
				trig2[nrow][ncol] = trig[nrow + 1][ncol + 1];
			}
		}
		int maxtemp1, maxtemp2;
		maxtemp1 = Howmax(trig1, N - 1);
		maxtemp2 = Howmax(trig2, N - 1);
		max1 = max(maxtemp1, maxtemp2);
		max1 += trig[0][0];
	}
	return max1;
}