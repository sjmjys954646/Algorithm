// freopen("input.txt", "r", stdin);
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <cstring>
#include <list>
#include <set>
#include <string.h>
#include <map>
#include <limits.h>
#include <stdlib.h>
#include <typeinfo>
#include <bitset>

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

const int INF = 987654321;

int testcase;
int startX, startY, finX, finY;
int visit[9][9];
vector<pii> logg[9][9];
vi arr;
int dx[4] = {1,1,-1,-1};
int dy[4] = {-1,1,1,-1};

void bfs()
{
    queue<pair<pii,int>> q;
    visit[startY][startX] = 0;
    q.push({ {startY,startX},0 });

    while (!q.empty())
    {
        int curX = q.front().F.S;
        int curY = q.front().F.F;
        int cost = q.front().S;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nX = curX;
            int nY = curY;
            while (true)
            {
                nX = nX + dx[i];
                nY = nY + dy[i];

                if (nX < 0 || nY < 0 || nX >= 8 || nY >= 8)
                    break;
                if (visit[nY][nX] != -1)
                    continue;

                for (int t = 0; t < logg[curY][curX].size(); t++)
                {
                    logg[nY][nX].push_back({ logg[curY][curX][t].F,logg[curY][curX][t].S });
                }

                logg[nY][nX].push_back({ curY,curX });
                visit[nY][nX] = cost + 1;
                q.push({ {nY,nX},cost + 1 });
            }
        }
    }

    cout << visit[finY][finX] << " ";
    for (int i = 0; i < logg[finY][finX].size(); i++)
    {
        cout << (char)(logg[finY][finX][i].S + 'A') << " " << 8 - logg[finY][finX][i].F << " ";
    }
    cout << (char)(finX + 'A') << " " << 8 - finY << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> testcase;


    while (testcase--)
    {
        rep(i, 9)
            rep(j, 9)
                logg[i][j].clear();
        
        memset(visit, -1, sizeof(visit));
        arr.clear();

        char startX_c, finX_c;

        cin >> startX_c >> startY >> finX_c >> finY;


        startX = startX_c - 'A';
        finX = finX_c - 'A';
        startY -= 1;
        startY =7 - startY;
        finY -= 1;
        finY = 7 - finY;

        if (abs(startX - finX) % 2 != abs(startY - finY) % 2)
        {
            cout << "Impossible" << "\n";
            continue;
        }    

        bfs();
    }
    

    return 0;
}