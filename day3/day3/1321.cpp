#include<iostream>
#include<string>
#include <vector>

using namespace std;

struct node
{
	int r, c;
};

int Howmany(vector<node>board, int k);

int main()
{
	int n, k;
	cin >> n >> k;
	while (n != -1 || k != -1)
	{
		// 读取棋盘上可以摆放的点
		vector<node> board;
		string temp;
		node temp1;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			for (int j = 0; j < n; j++)
			{
				if (temp[j] == '#')
				{
					temp1.r = i;
					temp1.c = j;
					board.push_back(temp1);
				}
			}
		}
		// Start
		int count = Howmany(board, k);
		cout << count << endl;
		cin >> n >> k;
	}
	return 0;
}

int Howmany(vector<node>board, int k)
{
	int count = 0;
	if (k == 1)
	{
		count = board.size();
	}
	else
	{
		for (int start = 0; start < board.size(); start++)
		{
			int rowctrl = board[start].r;
			int colctrl = board[start].c;
			vector<node> board_current;
			for (int search = start + 1; search < board.size(); search++)
			{
				if (board[search].r != rowctrl && board[search].c != colctrl)
				{
					board_current.push_back(board[search]);
				}
			}
			count += Howmany(board_current, k - 1);
		}
	}
	return count;
}