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
#include <stack>
#include <cstring>
#include <list>
#include <set>
#include <string.h>
#include <map>

using namespace std;

typedef pair<pair<int, int>, vector<pair<int, int>>> piiii;
int n;
int m[22][22];
piiii cnt(int sx, int sy, int ex, int ey)
{
    int gold = 0, stone = 0;
    vector<pair<int, int>> v;
    for (int i = sx; i <= ex; i++)
    {
        for (int j = sy; j <= ey; j++)

        {
            if (m[i][j] == 1)

            {
                stone++;
                v.push_back(make_pair(i, j));

            }
            else if (m[i][j] == 2)
                gold++;

        }

    }
    return make_pair(make_pair(gold, stone), v);
}
int recur(int sx, int sy, int ex, int ey, int vert)
{
    piiii check;
    piiii temp;
    check = cnt(sx, sy, ex, ey);
    if (check.first.first == 1 && check.first.second == 0) return 1;
    else if (check.first.first > 1 && check.first.second == 0) return 0;
    else if (check.first.first == 0) return 0;
    else if (check.first.second > 0)

    {
        int res = 0;
        for (int i = 0; i < check.first.second; i++)

        {
            int xx, yy;
            xx = check.second[i].first;
            yy = check.second[i].second;
            if (vert)

            {
                temp = cnt(sx, yy, ex, yy);
                if (temp.first.first >= 1) continue;
                if (yy - sy < 1 || ey - yy < 1) continue;
                res += recur(sx, sy, ex, yy - 1, !vert) * recur(sx, yy + 1, ex, ey, !vert);

            }
            else
            {
                temp = cnt(xx, sy, xx, ey);
                if (temp.first.first >= 1) continue;
                if (xx - sx < 1 || ex - xx < 1) continue;
                res += recur(sx, sy, xx - 1, ey, !vert) * recur(xx + 1, sy, ex, ey, !vert);

            }

        }
        return res;

    }
    return 0;
}
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &m[i][j]);
    piiii check = cnt(1, 1, n, n);
    if (check.first.first == 1 && check.first.second == 0) printf("1\n");
    else
    {
        int res = recur(1, 1, n, n, false) + recur(1, 1, n, n, true);
        if (res == 0) res = -1;
        printf("%d\n", res);

    }
}
int main()
{
    solve();
    return 0;
}