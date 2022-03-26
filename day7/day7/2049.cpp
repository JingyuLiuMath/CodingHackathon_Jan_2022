#include<iostream>
#include<vector>

using namespace std;

struct wall
{
	int x, y, d, t;
};

struct door
{
	int x, y, d;
};

int main()
{
	int M, N;
	while (cin >> M >> N && (M != -1 || N != -1))
	{
		vector<wall> walls;
		wall tempwall;
		for (int i = 0; i < M; i++)
		{
			cin >> tempwall.x >> tempwall.y >> tempwall.d >> tempwall.t;
			walls.push_back(tempwall);
		}
		vector<door> doors;
		door tempdoor;
		for (int i = 0; i < M; i++)
		{
			cin >> tempdoor.x >> tempdoor.y >> tempdoor.d;
			doors.push_back(tempdoor);
		}
		float f1, f2;
		cin >> f1 >> f2;

	}
}

void BFS()
{

}