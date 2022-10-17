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

int dp[31] = { 0, };

int main()
{
    int n; 
    
    scanf("%d", &n);

    dp[0] = 1;
    dp[1] = 0; 
    dp[2] = 3;

    for (int i = 3; i <= n; i++) 
    {
        if (i % 2 == 1)
            continue;

        dp[i] += 3 * dp[i - 2];

        for (int j = i - 4; j >= 0; j -= 2) 
        {
            dp[i] += 2 * dp[j];
        }
    }

    printf("%d", dp[n]);

    return 0;
}