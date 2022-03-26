#include<iostream>
#include<string>

using namespace std;

int main()
{
	string input;
	int num[101] = { 0 };
	int sum[101] = { 0 };
	while (1)
	{
		cin >> input;
		if (input.length() == 1 && input[0] == '0')
			break;
		int len = input.length();
		for (int i = 0; i < len; i++)
		{
			// e.g. 1234 --> 4 3 2 1, 个位-十位-...  
			num[i] = int(input[len - i - 1] - '0');
		}
		// 从低位加到高位
		for (int i = 0; i < 100; i++)
		{
			int temp = num[i] + sum[i];
			sum[i] = temp % 10;
			sum[i + 1] += temp / 10;
		}
	}
	// 输出结果
	bool flag = 1;
	for (int i = 100; i >= 0; i--)
	{
		if (flag == 1)
		{
			if (sum[i] != 0)
			{
				flag = 0;
				cout << sum[i];
			}
		}
		else
			cout << sum[i];
	}
	cout << endl;
	return 0;
}