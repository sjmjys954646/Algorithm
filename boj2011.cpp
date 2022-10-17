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

int cache[5002];
string arr;

int main()
{
    cin >> arr;

    cache[0] = 1;

    arr = ' ' + arr;

    for (int i = 1; i < arr.length(); i++)
    {
        if (arr[i] - '0' >= 1)
            cache[i] = (cache[i] + cache[i - 1]) % 1000000;

        int tmp = (arr[i - 1] - '0') * 10 + arr[i] - '0';

        if(10 <= tmp && tmp < 27)
            cache[i] = (cache[i] + cache[i - 2]) % 1000000;
    }

    printf("%d\n", cache[arr.size() - 1]);

    return 0;
}