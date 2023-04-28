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

int N;
int arr[100003][2];
int cache[100003][2];

int main()
{
    int testcase;
    
    scanf("%d", &testcase);

    while (testcase--)
    {
        memset(cache, -1, sizeof(cache));

        scanf("%d", &N);

        rep(j, 2)
        {
            rep(i, N)
            {
                scanf("%d", &arr[i][j]);
            }
        }
        cache[0][0] = arr[0][0];
        cache[0][1] = arr[0][1];
        cache[1][0] = arr[0][1] + arr[1][0];
        cache[1][1] = arr[0][0] + arr[1][1];

        for (int i = 2; i < N; i++)
        {
            cache[i][0] = max(max(cache[i - 2][0], cache[i - 2][1]), cache[i - 1][1]) + arr[i][0];
            cache[i][1] = max(max(cache[i - 2][0], cache[i - 2][1]), cache[i - 1][0]) + arr[i][1];
        }

        printf("%d\n", max(cache[N - 1][0], cache[N - 1][1]));
    }


    return 0;
}