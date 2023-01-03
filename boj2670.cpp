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

double arr[10002];
double cache[10002];
int N;

int main()
{
    double ans = -1;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%lf", &arr[i]);

    cache[0] = arr[0];
    
    for (int i = 1; i < N; i++)
    {
        cache[i] = max(arr[i], cache[i - 1] * arr[i]);
    }

    for (int i = 0; i < N; i++)
    {
        ans = max(ans, cache[i]);
    }

    printf("%.3lf", ans);

    return 0;
}