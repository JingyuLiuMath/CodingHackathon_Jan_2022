#include<iostream>
#include <math.h>

using namespace std;

int main()
{
	int N;
	float x;
	float y;
	int year;
	float area;
	const float pi = 3.1415926;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		area = pi* (x * x + y * y) / 2;
		year = int(area / 50) + 1;
		cout << "Property " << i + 1 << ": This property will begin eroding in year " << year << "." << endl;
	}
	cout << "END OF OUTPUT." << endl;
	return 0;
}