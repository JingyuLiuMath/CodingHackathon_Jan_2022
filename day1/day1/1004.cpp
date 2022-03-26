#include<iostream>
#include <cmath>
using namespace std;
int main()
{
	float money;
	float sum = 0;
	for (int i = 0; i < 12; i++) 
	{
		cin >> money;
		sum += money;
	}
	printf("$%.2f", sum / 12);
	return 0;
}