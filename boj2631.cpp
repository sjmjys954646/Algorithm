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

int cache[203];
int arr[203];
int N;

int main()
{
    scanf("%d", &N);

    rep(i, N)
    {
        scanf("%d", &arr[i]);
        cache[i] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[i] > arr[j])
            {
                cache[i] = max(cache[i], cache[j] + 1);
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < N; i++)
        if (ans < cache[i])
            ans = cache[i];

    printf("%d", N-ans);

    return 0;
}