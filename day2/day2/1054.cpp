#include<iostream>
#include<algorithm>

using namespace std;

struct Node
{
	int x;
	int y;
};
bool cmp(Node node1, Node node2);

int main()
{
	// The number of rows and columns
	int R, C;
	// The number of flattened rice plants
	int N;
	cin >> R >> C;
	cin >> N;
	bool** frog = new bool* [R];
	for (int i = 0; i < R; i++)
	{
		frog[i] = new bool[C];
		for (int j = 0; j < C; j++)
			frog[i][j] = 0;
	}
	// Get nodes 
	Node* nodes = new Node[N];
	int count;
	int maxcount = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> nodes[i].x >> nodes[i].y;
		frog[nodes[i].x - 1][nodes[i].y - 1] = 1;
	}
	sort(nodes, nodes + N, cmp); // 此时按x从小到大排
	// Start
	bool nibound;
	for (int ni = 0; ni < N; ni++)
	{
		for (int nj = ni + 1; nj < N; nj++)
		{
			int xstep = nodes[nj].x - nodes[ni].x; // xstep >= 0
			int ystep = nodes[nj].y - nodes[ni].y;
			nibound = (nodes[ni].x - xstep < 1) || (nodes[ni].y - ystep < 1)
				|| (nodes[ni].y - ystep > C) || (nodes[ni].x - xstep > R);
			if (nibound)
			{
				count = 2;
				int xk = nodes[nj].x + xstep;
				int yk = nodes[nj].y + ystep;
				while (xk <= R && yk >= 1 && yk <= C && xk >= 1)
				{
					if (frog[xk - 1][yk - 1] == 1)
					{
						count += 1;
					}
					else
					{
						count = 0;
						break;
					}
					xk += xstep;
					yk += ystep;
				}
				if (count > 2)
					maxcount = max(count, maxcount);
			}
		}
	}
	cout << maxcount << endl;
	return 0;
}

bool cmp(Node node1, Node node2)
{
	if (node1.x == node2.x)
		return node1.y < node2.y;
	return node1.x < node2.x;
}