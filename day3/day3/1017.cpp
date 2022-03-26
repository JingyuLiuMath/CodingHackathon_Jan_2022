#include<iostream>

using namespace std;

const int two2one = 4;
int main()
{
	int a1, a2, a3, a4, a5, a6;
	int box;
	cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
	while (a1 != 0 || a2 != 0 || a3 != 0 || a4 != 0 || a5 != 0 || a6 != 0)
	{
		box = 0;
		//give a solution
		box += a6;
		box += a5;
		int five4one = 11 * a5;
		a1 = max(a1 - five4one, 0);
		box += a4;
		int four4two = 5 * a4;
		if (four4two > a2)
		{
			four4two = four4two - a2;
			a2 = 0;
			int four4one = four4two * 4;
			a1 = max(a1 - four4one, 0);
		}
		else
		{
			a2 = a2 - four4two;
		}
		if (a3 > 0)
		{
			int box3 = a3 / 4;
			int box3left = a3 % 4;
			if (box3left != 0)
				box3 += 1;
			box += box3;
			if (box3left == 1)
			{
				int three4two = 5;
				int three4one = 7;
				if (three4two > a2)
				{
					three4two = three4two - a2;
					a2 = 0;
					three4one += 4 * three4two;
					a1 = max(a1 - three4one, 0);
				}
				else 
				{
					a2 = a2 - three4two;
					a1 = max(a1 - three4one, 0);
				}
			}
			else if (box3left == 2)
			{
				int three4two = 3;
				int three4one = 6;
				if (three4two > a2)
				{
					three4two = three4two - a2;
					a2 = 0;
					three4one += 4 * three4two;
					a1 = max(a1 - three4one, 0);
				}
				else
				{
					a2 = a2 - three4two;
					a1 = max(a1 - three4one, 0);
				}
			}
			else if (box3left == 3)
			{
				int three4two = 1;
				int three4one = 5;
				if (three4two > a2)
				{
					three4two = three4two - a2;
					a2 = 0;
					three4one += 4 * three4two;
					a1 = max(a1 - three4one, 0);
				}
				else
				{
					a2 = a2 - three4two;
					a1 = max(a1 - three4one, 0);
				}
			}
		}
		if (a2 > 0)
		{
			int box2 = a2 / 9;
			int box2left = a2 % 9;
			if (box2left != 0)
				box2 += 1;
			box += box2;
			if (box2left > 0)
			{
				box2left = 9 - box2left;
				int two4one = 4 * box2left;
				a1 = max(a1 - two4one, 0);
			}
		}
		if (a1 > 0)
		{
			int box1 = a1 / 36;
			int box1left = a1 % 36;
			if (box1left != 0)
				box1 += 1;
			box += box1;
		}
		// Output
		cout << box << endl;
		cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
	}
	return 0;
}