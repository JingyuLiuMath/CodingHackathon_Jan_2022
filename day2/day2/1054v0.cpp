#include<iostream>
#include<algorithm>

using namespace std;

struct Node
{
	int x;
	int y;
};
bool cmp(Node node1, Node node2);

// 结果正确但慢 
int main()
{
	// The number of rows and columns
	int R, C;
	// The number of flattened rice plants
	int N;
	cin >> R >> C;
	cin >> N;
	// Get nodes 
	Node* nodes = new Node[N];
	int count;
	int maxcount = 0;
	for (int i = 0; i < N; i++)
		cin >> nodes[i].x >> nodes[i].y;
	sort(nodes, nodes + N, cmp); // 此时按x从小到大排
	// Start
	bool flag;
	bool find;
	bool nibound;
	for (int ni = 0; ni < N; ni++)
	{
		for (int nj = ni + 1; nj < N; nj++)
		{
			flag = 1;
			count = 2;
			find = 0;
			int xstep = nodes[nj].x - nodes[ni].x; // xstep >= 0
			int ystep = nodes[nj].y - nodes[ni].y;
			nibound = (nodes[ni].x - xstep < 1) || (nodes[ni].y - ystep < 1)
				|| (nodes[ni].y - ystep > C);
			if (nibound)
			{
				int xk = nodes[nj].x + xstep;
				int yk = nodes[nj].y + ystep;
				while (xk <= R && yk >= 1 && yk <= C)
				{
					find = 0;
					for (int each = 0; each < N; each++)
					{
						// 判断有无
						if (nodes[each].x == xk && nodes[each].y == yk)
						{
							count += 1;
							find = 1;
							break;
						}
					}
					if (find == 0)
					{
						flag = 0;
						break;
					}
					xk += xstep;
					yk += ystep;
				}
				if (flag == 1)
					if (count > maxcount)
						maxcount = count;
			}
		}
	}
	cout << maxcount << endl;
	return 0;
}

bool cmp(Node node1, Node node2)
{
	return node1.x < node2.x;
}