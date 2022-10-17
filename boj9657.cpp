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

const int INF = 1e9;

int testcase;

int N, M, K, Q, L;
int cache[1003];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    memset(cache, -1, sizeof(cache));

    cin >> N;

    // 1 ��� 0 â��
    cache[1] = 1;
    cache[2] = 0;
    cache[3] = 1;
    cache[4] = 1;

    for (int i = 5; i <= N; i++)
    {
        if (cache[i - 1] == 0 || cache[i - 3] == 0 || cache[i - 4] == 0)
            cache[i] = 1;
        else
            cache[i] = 0;
    }

    if (cache[N])
        cout << "SK";
    else
        cout << "CY";
    

    return 0;
}
