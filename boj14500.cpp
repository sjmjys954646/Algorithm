#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#define X first
#define Y second
using namespace std;

int N, M;
int arr[501][501];

int Tetris[19][4][2] =
{
	{{0,0}, {1,0}, {2,0}, {3,0}},//i미노 가로
	{{0,0}, {0,1}, {0,2}, {0,3}},//i미노 세로
	{{0,0}, {0,1}, {1,0}, {1,1}},//0미노 
	{{0,0}, {1,0}, {1,-1}, {2,-1}},//s미노 누워
	{{0,0}, {0,1}, {1,1}, {1,2}},//s미노 세워
	{{0,0}, {1,0}, {1,1}, {2,1}},//z미노 누워
	{{0,0}, {0,1}, {-1,1}, {-1,2}},//z미노 세워
	{{0,0}, {1,0}, {2,0}, {1,1}},//t미노 ㅜ
	{{0,0}, {0,1}, {0,2}, {1,1}},//t미노 ㅏ
	{{0,0}, {0,1}, {1,1}, {-1,1}},//t미노 ㅗ
	{{0,0}, {0,1}, {0,2}, {-1,1}},//t미노 ㅓ
	{{0,0}, {1,0}, {1,1}, {1,2}},//l미노
	{{0,0}, {1,0}, {2,0}, {2,-1}},//l미노
	{{0,0}, {0,1}, {0,2}, {1,2}},//l미노
	{{0,0}, {0,-1}, {1,-1}, {2,-1}},//l미노
	{{0,0}, {1,0}, {0,1}, {0,2}},//j미노
	{{0,0}, {1,0},{2,0},{2,1}},//j미노
	{{0,0}, {0,1}, {0,2}, {-1,2}},//j미노
	{{0,0},{0,1},{1,1},{2,1}}//j미노
};

int solve()
{
	int tot = 0;

	int x, y;//중점
	for (int t = 0; t < N; t++)
	{
		for (int r = 0; r < M; r++)
		{
			x = r;
			y = t;

			for (int i = 0; i < 19; i++)
			{
				int total = 0;
				bool impos = false;
				for (int j = 0; j < 4; j++)
				{
					int mX = x + Tetris[i][j][0];
					int mY = y + Tetris[i][j][1];

					if (mX < 0 || mX >= M || mY < 0 || mY >= N)
					{
						impos = true;
						break;
					}

					total += arr[mY][mX];
				}
				if (impos)
					continue;

				tot = max(tot, total);
			}
		}
	}
	return tot;
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << solve();
	return 0;
}