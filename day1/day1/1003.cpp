#include<iostream>

using namespace std;

int main()
{
	float input;
	double sum = 0;
	int num = 1;
	cin >> input;
	while (input != 0.00)
	{
		sum = 0;
		num = 1;
		while (sum <= input)
		{
			sum += 1 / float((num + 1));
			num += 1;
		}
		cout << num-1 << " card(s)" << endl;
		cin >> input;
	}
	return 0;
}