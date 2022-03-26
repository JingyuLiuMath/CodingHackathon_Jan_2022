#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<math.h>

using namespace std;

int main()
{
	int N, W;
	while (cin >> N >> W && (N != 0 || W != 0))
	{
		// initialize
		int* v = new int[N+1];
		int* w = new int[N+1];
		memset(v, 0, sizeof(v));
		memset(w, 0, sizeof(w));
		int* choose = new int[N+1];
		memset(choose, 0, sizeof(choose));
		vector<vector<int>>  V(N + 1, vector<int>(W + 1, 0));
		for (int i = 1; i < N+1; i++)
		{
			cin >> v[i] >> w[i];
		}
		// DP
		for (int i = 1; i < N + 1; i++)
		{
			for (int j = 1; j < W + 1; j++)
			{
				if (j < w[i])
				{
					V[i][j] = V[i - 1][j];
				}
				else
				{
					V[i][j] = max(V[i - 1][j - w[i]] + v[i], V[i - 1][j]);
				}
			}
		}
		// print DP table
		for (int i = 0; i < N + 1; i++)
		{
			for (int j = 0; j < W + 1; j++)
			{
				cout << V[i][j] << ' ';
			}
			cout << endl;
		}
		// find solution
		int nowi = N;
		int nowj = W;
		while (nowi > 0)
		{
			if (V[nowi][nowj] == V[nowi - 1][nowj])
			{
				choose[nowi] = 0;
				nowi = nowi - 1;
			}
			else if  (V[nowi][nowj] == V[nowi - 1][nowj - w[nowi]] + v[nowi])
			{
				choose[nowi] = 1;
				nowj = nowj - w[nowi];
				nowi = nowi - 1;
			}
		}
		cout << "Choose: " << endl;
		for (int i = 1; i < N + 1; i++)
		{
			if (choose[i] == 1)
				cout << i << endl;
		}
		cout << "Optimal Value: ";
		cout << V[N][W] << endl;
	}
	return 0;
}