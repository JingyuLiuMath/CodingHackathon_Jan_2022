#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	// a, b������ʯ�ӵ���Ŀ
	int a, b;
	bool win;
	const double x = (1 + sqrt(5.0)) / 2.0;
	// ��������
	// a = [k * (1 + sqrt(5.0) / 2]
	// b = a + k
	while (cin >> a >> b)
	{
		win = 1;
		if (a > b)
		{
			int temp = a;
			a = b;
			b = temp;
		}
		int k = b - a;
		int a1 = floor(k * x);
		if (a1 == a)
			win = 0;
		cout << win << endl;
	}
}