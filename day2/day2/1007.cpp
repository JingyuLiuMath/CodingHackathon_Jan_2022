#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
	// n是字符串长度, m是字符串个数
	int n, m;
	cin >> n >> m;
	string* DNA = new string[m];
	int* num = new int[m];
	for (int i = 0; i < m; i++)
	{
		cin >> DNA[i];
		num[i] = 0;
		for (int j = 0; j < n; j++)
		{
			for (int k = j+1; k < n; k++)
			{
				if (DNA[i][j] > DNA[i][k])
					num[i] += 1;
			}
		}
	}
	// sort
	for (int p = 1; p < m; p++)
	{
		for (int q = 0; q < m - p; q++)
		{
			if (num[q] > num[q + 1])
			{
				int temp = num[q];
				num[q] = num[q + 1];
				num[q + 1] = temp;
				string tempstr = DNA[q];
				DNA[q] = DNA[q + 1];
				DNA[q + 1] = tempstr;
			}
		}
	}
	// Output.
	for (int d = 0; d < m; d++)
		cout << DNA[d] << endl;
}