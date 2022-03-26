#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int p;
	int e;
	int i;
	int d;
	int start;
	int n = 1;
	cin >> p >> e >> i >> d;
	while ((p != -1) && (e != -1) && (i != -1) && (d != -1))
	{
		start = d + 1;
		while ( 
			(start-p) % 23 != 0 || (start - e) % 28 != 0 || (start - i) % 33 != 0
			)
		{
			if (start > d + 21252)
				break;
			start = start + 1;
		}
		cout << "Case " << n << ": the next triple peak occurs in " << start - d << " days." << endl;
		n += 1;
		cin >> p >> e >> i >> d;
	}
	return 0;
}