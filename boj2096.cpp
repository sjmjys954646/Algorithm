//freopen("input.txt", "r", stdin);
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
#include <limits.h>
#include <stdlib.h>

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

int arr[100002][3];
int minCache[3][3];
int maxCache[3][3];
int N;

int main()
{
    scanf("%d", &N);

    rep1(i, N)
    {
        rep(j, 3)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    minCache[1][0] = maxCache[1][0] = arr[1][0];
    minCache[1][1] = maxCache[1][1] = arr[1][1];
    minCache[1][2] = maxCache[1][2] = arr[1][2];

    for (int i = 2; i <= N; i++)
    {
        minCache[2][0] = min(minCache[1][0], minCache[1][1]) + arr[i][0];
        minCache[2][1] = min(min(minCache[1][0], minCache[1][1]), minCache[1][2]) + arr[i][1];
        minCache[2][2] = min(minCache[1][1], minCache[1][2]) + arr[i][2];

        maxCache[2][0] = max(maxCache[1][0], maxCache[1][1]) + arr[i][0];
        maxCache[2][1] = max(max(maxCache[1][0], maxCache[1][1]), maxCache[1][2]) + arr[i][1];
        maxCache[2][2] = max(maxCache[1][1], maxCache[1][2]) + arr[i][2];

        for (int j = 0; j < 3; j++)
        {
            minCache[1][j] = minCache[2][j];
            maxCache[1][j] = maxCache[2][j];
        }
    }

    int minans = INF;
    int maxans = -1;

    for (int j = 0; j < 3; j++)
    {
        minans = min(minans, minCache[1][j]);
        maxans = max(maxans, maxCache[1][j]);
    }

    printf("%d %d", maxans, minans);
   

    return 0;
}