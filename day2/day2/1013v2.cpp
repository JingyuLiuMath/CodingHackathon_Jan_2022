#include<iostream>

using namespace std;

char letter[12] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L' };
bool iseq(int* coins, string(*text)[3]);
int main()
{
	int n;
	cin >> n;
	string(*text)[3] = new string[3][3];
	for (int ks = 0; ks < n; ks++)
	{
		int coins[12] = { 0 };
		// Read datas
		for (int line = 0; line < 3; line++)
		{
			for (int part = 0; part < 3; part++)
			{
				cin >> text[line][part];
			}
		}
		for (int each = 0; each < 12; each++)
		{
			// case 1
			coins[each] = 1;
			if (iseq(coins, text))
			{
				cout << letter[each] <<  " is the counterfeit coin and it is heavy." << endl;
				break;
			}
			// case 2
			coins[each] = -1;
			if (iseq(coins, text))
			{
				cout << letter[each] << " is the counterfeit coin and it is light." << endl;
				break;
			}
			// set 0
			coins[each] = 0;
		}
	}
	return 0;
}

bool iseq(int* coins, string(*text)[3])
{
	int left;
	int right;
	for (int line = 0; line < 3; line++)
	{
		left = 0;
		right = 0;
		if (text[line][2][0] == 'e')
		{
			for (int i = 0; i < text[line][0].length(); i++)
			{
				left += coins[text[line][0][i] - 'A'];
			}
			for (int i = 0; i < text[line][1].length(); i++)
			{
				right += coins[text[line][1][i] - 'A'];
			}
			if (left != right)
				return false;
		}
		else if (text[line][2][0] == 'u')
		{
			for (int i = 0; i < text[line][0].length(); i++)
			{
				left += coins[text[line][0][i] - 'A'];
			}
			for (int i = 0; i < text[line][1].length(); i++)
			{
				right += coins[text[line][1][i] - 'A'];
			}
			if (left <= right)
				return false;
		}
		else if (text[line][2][0] == 'd')
		{
			for (int i = 0; i < text[line][0].length(); i++)
			{
				left += coins[text[line][0][i] - 'A'];
			}
			for (int i = 0; i < text[line][1].length(); i++)
			{
				right += coins[text[line][1][i] - 'A'];
			}
			if (left >= right)
				return false;
		}
	}
	return true;
}