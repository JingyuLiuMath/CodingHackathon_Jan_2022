#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<iomanip>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string* phonelist_str = new string[n];
	string str;
	string temp;
	// Get the phonenumber string list.
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		temp = "\0";
		for (int l = 0; l < str.length(); l++)
		{
			if (str[l] != '-')
			{
				if (str[l] == 'A' || str[l] == 'B' || str[l] == 'C'
					|| str[l] == 'a' || str[l] == 'b' || str[l] == 'c')
				{
					temp += '2';
				}
				else if (str[l] == 'D' || str[l] == 'E' || str[l] == 'F'
					|| str[l] == 'd' || str[l] == 'e' || str[l] == 'f')
				{
					temp += '3';
				}
				else if (str[l] == 'G' || str[l] == 'H' || str[l] == 'I'
					|| str[l] == 'g' || str[l] == 'h' || str[l] == 'i')
				{
					temp += '4';
				}
				else if (str[l] == 'J' || str[l] == 'K' || str[l] == 'L'
					|| str[l] == 'j' || str[l] == 'k' || str[l] == 'l')
				{
					temp += '5';
				}
				else if (str[l] == 'M' || str[l] == 'N' || str[l] == 'O'
					|| str[l] == 'm' || str[l] == 'n' || str[l] == 'o')
				{
					temp += '6';
				}
				else if (str[l] == 'P' || str[l] == 'R' || str[l] == 'S'
					|| str[l] == 'p' || str[l] == 'r' || str[l] == 's')
				{
					temp += '7';
				}
				else if (str[l] == 'T' || str[l] == 'U' || str[l] == 'V'
					|| str[l] == 't' || str[l] == 'u' || str[l] == 'v')
				{
					temp += '8';
				}
				else if (str[l] == 'W' || str[l] == 'X' || str[l] == 'Y'
					|| str[l] == 'w' || str[l] == 'x' || str[l] == 'y')
				{
					temp += '9';
				}
				else
				{
					temp += str[l];
				}
			}
		}
		phonelist_str[i] = temp;
	}
	// Convert the phonelist to list of numbers.
	int* phonelist_num = new int[n];
	for (int i = 0; i < n; i++)
	{
		phonelist_num[i] = atoi(phonelist_str[i].c_str());
	}
	// Sorting
	/*for (int p = 1; p < n; p++)
	{
		for (int q = 0; q < n - p; q++)
		{
			if (phonelist_num[q] > phonelist_num[q + 1])
			{
				int temp = phonelist_num[q];
				phonelist_num[q] = phonelist_num[q + 1];
				phonelist_num[q + 1] = temp;
			}
		}
	}*/
	sort(phonelist_num, phonelist_num + n);
	/*for (int d = 0; d < n; d++)
		cout << phonelist_num[d] << endl;*/
	// show output
	int dpnum;
	int current;
	int j = 0;
	bool flag = 1;
	while(j < n)
	{
		dpnum = 1;
		current = phonelist_num[j];
		for (int jj = j + 1; jj < n; jj++)
		{
			if (phonelist_num[jj] == current)
				dpnum += 1;
			else
				break;
		}
		if (dpnum != 1)
		{
			flag = 0;
			cout << setfill('0') << setw(3) << current / 10000;
			cout << "-";
			cout << setfill('0') << setw(4) << current % 10000;
			cout << " " << dpnum << endl;
		}
		j = j + dpnum;     
	}
	if (flag == 1)
		cout << "No duplicates." << endl;
	return 0;
}