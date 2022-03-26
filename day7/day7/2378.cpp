#include<iostream>
#include<vector>
#include<stack>

using namespace std;

stack<int> stk;
void DFS(vector<int>* G, int N, int start, int* num_child, int* father);

int main()
{
	// initialize
	int N;
	cin >> N;
	vector<int>* G = new vector<int>[N + 1];
	int x, y;
	for (int i = 1; i <= N - 1; i++)
	{
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	// DFS
	// 我们要记录两个值: 节点的子孙节点数量num_child(含自己), 
	// 节点的子节点构成的子树中,子孙节点的数量的最大值num_maxsubtree
	int* num_child = new int[N + 1];
	for (int i = 0; i < N + 1; i++)
		num_child[i] = 0;
	int* father = new int[N + 1];
	for (int i = 0; i < N + 1; i++)
		father[i] = 0;
	int* num_maxsubtree = new int[N + 1];
	for (int i = 0; i < N + 1; i++)
		num_maxsubtree[i] = 0;
	if (!stk.empty()) stk.pop();
	DFS(G, N, 1, num_child, father);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (father[j] == i)
			{
				num_maxsubtree[i] = max(num_maxsubtree[i], num_child[j]);
			}
		}
	}
	/*cout << "num_child" << endl;
	for (int i = 1; i <= N; i++)
		cout << num_child[i] << endl;
	cout << "father" << endl;
	for (int i = 1; i <= N; i++)
		cout << father[i] << endl;*/
		// 判断并输出结果
	int judge = N / 2;
	int output = 0;
	for (int i = 1; i <= N; i++)
	{
		if (N - num_child[i] <= judge && num_maxsubtree[i] <= judge)
		{
			output = 1;
			cout << i << endl;
		}
	}
	if (output == 0)
	{
		cout << "NONE" << endl;
	}
	return 0;
}

void DFS(vector<int>* G, int N, int start, int* num_child, int* father)
{
	int* visit = new int[N + 1];
	for (int i = 0; i < N + 1; i++)
		visit[i] = 0;
	// 取一个节点
	int now = start;
	int old = 0;
	while (1)
	{
		// 如果这个节点是第一次出现，则放入堆栈中
		if (visit[now] == 0)
		{
			visit[now] = 1;
			// cout << now << endl;
			stk.push(now);
		}
		// 判断搜索是否完成
		int flag = 1;
		int son = 0;
		for (int i = 0; i < G[now].size(); i++)
		{
			son = G[now][i];
			if (visit[son] == 0)
			{
				flag = 0;
				father[son] = now;
				// 取一个节点
				now = son;
				break;
			}
		}
		if (flag == 1) // 搜索完成
		{
			num_child[now] += 1;
			stk.pop();
			if (stk.empty())
			{
				delete[] visit;
				return;
			}
			else
			{
				old = now;
				// 取一个节点
				now = stk.top();
				num_child[now] += num_child[old];
			}
		}
	}
}