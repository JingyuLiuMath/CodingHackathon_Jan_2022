#include<iostream>

using namespace std;

int main()
{
	int N;
	while (cin >> N && N != 0)
	{
		int* sticks = new int[N + 1];
		for (int i = 1; i <= N; i++)
		{
			cin >> sticks[i];
		}
		cout << findlen(sticks, N) << endl;
	}
	return 0;
}

int findlen(int* sticks, int N)
{

	return 1;
}