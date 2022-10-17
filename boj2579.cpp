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

int arr[302] = { 0, };
int cache[302];
int N;

int dp(int num)
{
    int& ret = cache[num];
    if (ret != -1)
        return ret;
    
    return ret = max(dp(num-2), dp(num-3)+arr[num-1]) + arr[num];
}

int main()
{
    memset(cache, -1, sizeof(cache));

    scanf("%d", &N);

    rep(i, N)
    {
        scanf("%d", &arr[i]);
    }

    cache[0] = arr[0];
    cache[1] = arr[0] + arr[1];
    cache[2] = max(arr[0] + arr[2], arr[1] + arr[2]);

    dp(N - 1);

    printf("%d", cache[N - 1]);


    return 0;
}