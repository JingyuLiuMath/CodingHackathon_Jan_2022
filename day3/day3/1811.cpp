#include<iostream>
#include<math.h>

typedef long long ll;
using namespace std;

int main()
{
	int T;
	cin >> T;
	long long N;
	int flag;
	for (int num = 0; num < T; num++)
	{
		cin >> N;
		flag = 0;
		if (N == 2)
		{
			cout << "Prime" << endl;
			continue;
		}
		if (N % 2 == 0)
		{
			cout << 2 << endl;
			continue;
		}
		long long test = floor(sqrt(N)) + 1;
		for (long long factor = 3; factor < test; factor += 2)
		{
			if (N % factor == 0)
			{
				cout << factor << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			cout << "Prime" << endl;
	}
	return 0;
}