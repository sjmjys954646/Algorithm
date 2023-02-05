#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 9876543210;

int arr[31][31][31];
int visited[31][31][31];
int L, R, C;
int startZ, startY, startX;
int finZ, finY, finX;

int nZ[6] = { 0,0,0,0,1,-1 };
int nY[6] = { 0,1,0,-1,0,0 };
int nX[6] = { 1,0,-1,0,0,0 };

struct dd {
	int z;
	int y;
	int x;
};

int main()
{
	while (true)
	{
		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));

		cin >> L >> R >> C;

		if (L + R + C == 0)
			break;

		string tmp;

		rep(i, L)
		{
			rep(j, R)
			{
				cin >> tmp;
				rep(k, C)
				{
					char p = tmp[k];
					if (p == 'S')
					{
						startZ = i;
						startY = j;
						startX = k;
					}
					else if (p == 'E')
					{
						finZ = i;
						finY = j;
						finX = k;
					}
					else if (p == '#')
						arr[i][j][k] = 1;
					else
						arr[i][j][k] = 0;
				}
			}
		}

		queue<pair<dd, int> > pq;
		visited[startZ][startY][startX] = 1;
		dd start = { startZ, startY, startX };
		pq.push({ start, 0 });

		int ans = -1;

		while (!pq.empty())
		{
			dd cur = pq.front().first;
			int cost = pq.front().second;
			pq.pop();

			if (cur.z == finZ && cur.y == finY && cur.x == finX)
			{
				ans = cost;
				break;
			}

			for (int i = 0; i < 6; i++)
			{
				if (cur.z + nZ[i] < 0 || cur.z + nZ[i] >= L)
					continue;
				if (cur.y + nY[i] < 0 || cur.y + nY[i] >= R)
					continue;
				if (cur.x + nX[i] < 0 || cur.x + nX[i] >= C)
					continue;
				if (arr[cur.z + nZ[i]][cur.y + nY[i]][cur.x + nX[i]] == 1)
					continue;
				if (visited[cur.z + nZ[i]][cur.y + nY[i]][cur.x + nX[i]] == 1)
					continue;

				visited[cur.z + nZ[i]][cur.y + nY[i]][cur.x + nX[i]] = 1;
				dd newCur = { cur.z + nZ[i] ,cur.y + nY[i] ,cur.x + nX[i] };
				pq.push({ newCur,cost + 1 });
			}

		}
		if (ans == -1)
			cout << "Trapped!" << "\n";
		else
			cout << "Escaped in " << ans << " minute(s).\n";
	}

	return 0;
}