#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int N;
	int B;
	int K;
	cin >> N >> B >> K;
	int** val = new int* [N];
	for (int i = 0; i < N; i++)
	{
		val[i] = new int[N];
		for (int j = 0; j < N; j++)
			cin >> val[i][j];
	}
	int** qval = new int* [B];
	int qr;
	int qc;
	for (int q = 0; q < K; q++)
	{
		cin >> qr >> qc;
		int max1 = 0;
		int min1 = 250;
		for (int i = 0; i < B; i++)
		{
			for (int j = 0; j < B; j++)
			{
				max1 = max(max1, val[qr - 1 + i][qc - 1 + j]);
				min1 = min(min1, val[qr - 1 + i][qc - 1 + j]);
			}
		}
		cout << max1-min1 << endl;
	}
	return 0;
}