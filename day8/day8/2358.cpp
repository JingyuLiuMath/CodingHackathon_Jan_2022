#include<iostream>
#include<vector>

using namespace std;

void arrange(int* board, int N, int i, int j, int k, int& num);
bool check(int* board, int N);

int main()
{
	int N;
	cin >> N;
	int* board = new int[N + 1];
	board[0] = 0;
	int x, y;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		board[x] = y;
	}
	int* boardcopy = new int[N + 1];
	int num = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			for (int k = j + 1; k <= N; k++)
			{
				for (int t = 0; t <= N; t++)
				{
					boardcopy[t] = board[t];
				}
				arrange(boardcopy, N, i, j, k, num);
			}
		}
	}
	cout << num << endl;
	return 0;
}

void arrange(int* boardcopy, int N, int i, int j, int k, int &num)
{
	int coli = boardcopy[i], colj = boardcopy[j], colk = boardcopy[k];
	// case 1
	boardcopy[i] = colj;
	boardcopy[j] = colk;
	boardcopy[k] = coli;
	if (check(boardcopy, N))
		num += 1;
	// case 2
	boardcopy[i] = colk;
	boardcopy[j] = coli;
	boardcopy[k] = colj;
	if (check(boardcopy, N))
		num += 1;
}

bool check(int* board, int N)
{
	for (int i = 1; i <= N; i++)
	{
			for (int j = i + 1; j <= N; j++)
			{
				if (board[j] == board[i])
				{
					return false;
				}
				if (abs(j - i) == abs(board[j] - board[i]))
				{
					return false;
				}
			}
	}
	return true;
}