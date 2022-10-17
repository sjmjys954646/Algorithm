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

int testcase;
int k;

long long cache[22][102];
long long arr[102];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long ans = 0;

    memset(cache, -1, sizeof(cache));

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }

    cache[arr[0]][0] = 1;

    for (int i = 0; i < k - 1; i++)
    {
        if (i == k - 2)
        {
            for (int j = 0; j <= 20; j++)
            {
                if (cache[j][i] == -1)
                    continue;

                int curNum = arr[i + 1];

                if (curNum == j)
                {
                    ans = cache[j][i];
                }
            }
            break;
        }

        for (int j = 0; j <= 20; j++)
        {
            if (cache[j][i] == -1)
                continue;

            int curNum = arr[i+1];

            if (curNum + j <= 20)
            {
                if (cache[curNum + j][i + 1] == -1)
                    cache[curNum + j][i + 1] = 0;

                cache[curNum + j][i + 1] += cache[j][i];
            }

            if ( j - curNum >= 0)
            {
                if (cache[j - curNum][i + 1] == -1)
                    cache[j - curNum][i + 1] = 0;

                cache[j - curNum][i + 1] += cache[j][i];
            }
        }
    }
    cout << ans;


    return 0;
}