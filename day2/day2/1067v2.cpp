#include<iostream>

using namespace std;
bool whowin(int a, int b);

int main()
{
	// a, b是两堆石子的数目
	int a, b;
	int win;
	while (cin >> a >> b)
	{
		if (a > b)
		{
			int temp = a;
			a = b;
			b = temp;
		}
		win = whowin(a, b);
		cout << win << endl;
	}
}

bool whowin(int a, int b)
{
	if (a == b)
		return 1;
	if (a == 0 || b == 0)
		return 1;
	else
	{
		int tempwin = 0;
		// case 1: 在任意的一堆中取走任意多的石子
		for (int i = 1; i <= a; i++)
			if (!whowin(a - i, b))
				tempwin = 1;
		for (int i = 1; i <= b; i++)
			if (!whowin(a, b - i))
				tempwin = 1;
		// case 2: 在两堆中同时取走相同数量的石子
		for (int i = 1; i < a; i++)
		if (!whowin(a - i, b - i))
				tempwin = 1;
		return tempwin;
	}
}