#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<math.h>

using namespace std;

int main()
{
	int n, m;
	int round = 1;
	while (cin >> n >> m && (n != 0 || m != 0))
	{
		// initialize
		int* v = new int[n + 1];
		int* w = new int[n + 1];
		memset(v, 0, sizeof(v));
		memset(w, 0, sizeof(w));
		int p, d;
		for (int i = 1; i < n + 1; i++)
		{
			cin >> p >> d;
			v[i] = p + d;
			w[i] = p - d;
		}
		int Wbd = 20 * m;
		vector<vector<vector<int>>> F(n + 1, vector<vector<int>>(m + 1, 
			vector<int>(2 * Wbd + 1, -1)));
		F[0][0][Wbd] = 0; // 初始在W
		// DP
		for (int i = 1; i < n + 1; i++)
		{
			for(int k = 0;k< 2 * Wbd + 1; k++)
				F[i][0][Wbd] = F[i-1][0][Wbd];
			for (int j = 1; j < m + 1; j++)
			{
				for (int k = 0; k < 2 * Wbd + 1; k++)
				{
					F[i][j][k] = F[i - 1][j][k];
					if (k - w[i] >= 0 && k - w[i] < 2 * Wbd + 1)
					{
						if(F[i - 1][j - 1][k - w[i]] >= 0) // 因为要加vi
							F[i][j][k] = max(F[i - 1][j][k],
								F[i - 1][j - 1][k - w[i]] + v[i]);
					}
					// cout << i << ' ' << j << ' ' << k-Wbd << ' ' << F[i][j][k] << endl;
				}
			}
		}
		// find min
		int mink = 2 * Wbd + 1;
		for (int k = Wbd; k < 2 * Wbd + 1; k++)
		{
			if (F[n][m][k] >= 0 || F[n][m][2 * Wbd-k] >= 0)
			{
				if (F[n][m][k] > F[n][m][2 * Wbd - k])
				{
					mink = k;
				}
				else
				{
					mink = 2 * Wbd - k;
				}
				break;
			}
		}
		int maxF = F[n][m][mink];
		// find solution
		int* choose = new int[n + 1];
		memset(choose, 0, sizeof(choose));
		int nowi = n;
		int nowj = m;
		int nowk = mink;
		while (nowj > 0)
		{
			if (F[nowi][nowj][nowk] == F[nowi - 1][nowj][nowk])
			{
				choose[nowi] = 0;
				nowi = nowi - 1;
			}
			else if (F[nowi][nowj][nowk] == F[nowi - 1][nowj - 1][nowk- w[nowi]] + v[nowi])
			{
				choose[nowi] = 1;
				nowj = nowj - 1;
				nowk = nowk - w[nowi];
				nowi = nowi - 1;
			}
		}
		// output
		mink = mink - Wbd;
		cout << "Jury #" << round << endl;
		cout << "Best jury has value " << (maxF + mink) / 2 << " for prosecution and value "
			<< (maxF - mink) / 2 << " for defence:" << endl;
		for (int i = 1; i < n + 1; i++)
		{
			if (choose[i] == 1)
				cout << ' ' << i;
		}
		round += 1;
	}
	return 0;
}