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

long long  arr[42];
vector<long long > p;

int main()
{
    int N, M;

    scanf("%d %d", &N, &M);
    
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;

    for (int i = 3; i < 42; i++)
    {
        arr[i] = arr[i - 2] + arr[i - 1];
    }

    long long ans = 1;
    int prev = 0;
    rep(i, M)
    {
        int tmp;
        scanf("%d", &tmp);

        ans *= arr[tmp - prev - 1];
        prev = tmp;
    }

    ans *= arr[N - prev];

    cout << ans;


    return 0;
}