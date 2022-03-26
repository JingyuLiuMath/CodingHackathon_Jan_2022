#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

long long m = 0;
queue<long long> q;
void BFS(int n);

int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		while (!q.empty()) q.pop();
		q.push(1);
		BFS(n);
		cout << m << endl;
	}
	return 0;
}

void BFS(int n)
{
	while (1)
	{
		long long now = q.front();
		q.pop();
		if (now % n == 0)
		{
			m = now;
			return;
		}
		else
		{
			q.push(now * 10);
			q.push(now * 10 + 1);
		}
	}
}