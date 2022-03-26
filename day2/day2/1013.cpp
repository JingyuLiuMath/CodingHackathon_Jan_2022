#include<iostream>
#include <algorithm>

using namespace std;

char letter[12] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L' };
// enum letter { A, B, C, D, E, F, G, H, I, J, K, L };

int main()
{
	int n;
	cin >> n;
	string(*text)[3] = new string[3][3];
	for (int ks = 0; ks < n; ks++)
	{
		int coins[12] = { 0 };
		int flags[12] = { 0 };
		// Read datas
		for (int line = 0; line < 3; line++)
		{
			for (int part = 0; part < 3; part++)
			{
				cin >> text[line][part];
			}
		}
		// Start our alg
		// 1: light, 2: normal, 3: heavy
		for (int line = 0; line < 3; line++)
		{
			if (text[line][2][0] == 'e')
			{
				for (int i = 0; i < text[line][0].length(); i++)
				{
					flags[text[line][0][i] - 'A'] = 1;
				}
				for (int i = 0; i < text[line][1].length(); i++)
				{
					flags[text[line][1][i] - 'A'] = 1;
				}
			}
		}
		for (int line = 0; line < 3; line++)
		{
			if (text[line][2][0] == 'u')
			{
				for (int i = 0; i < text[line][0].length(); i++)
				{
					if (flags[text[line][0][i] - 'A'] != 1)
						coins[text[line][0][i] - 'A'] += 1;
				}
				for (int i = 0; i < text[line][1].length(); i++)
				{
					if (flags[text[line][1][i] - 'A'] != 1)
						coins[text[line][1][i] - 'A'] -= 1;
				}
			}
			else if (text[line][2][0] == 'd')
			{
				for (int i = 0; i < text[line][0].length(); i++)
				{
					if (flags[text[line][0][i] - 'A'] != 1)
						coins[text[line][0][i] - 'A'] -= 1;
				}
				for (int i = 0; i < text[line][1].length(); i++)
				{
					if (flags[text[line][1][i] - 'A'] != 1)
						coins[text[line][1][i] - 'A'] += 1;
				}
			}
		}
		int maxcoin = *max_element(coins, coins + 12);
		int mincoin = *min_element(coins, coins + 12);
		if (abs(maxcoin) > abs(mincoin))
		{
			for (int index = 0; index < 12; index++)
			{
				if (coins[index] == maxcoin)
					cout << letter[index] << " is the counterfeit coin and it is heavy." << endl;
				// cout << coins[index] << endl;
			}
		}
		else if (abs(maxcoin) < abs(mincoin))
		{
			for (int index = 0; index < 12; index++)
			{
				if (coins[index] == mincoin)
					cout << letter[index] << " is the counterfeit coin and it is light." << endl;
				// cout << coins[index] << endl;
			}
		}
	}
	return 0;
}