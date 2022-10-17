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
int arr[1030][1030];
int sum[1030][1030];

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    rep1(i,N)
    {
        rep1(j, N)
        {
            int tmp;
            cin >> tmp;
            arr[i][j] = tmp;
        }
    }
    
    rep1(i, N)
    {
        rep1(j, N)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j-1]  - sum[i - 1][j-1] + arr[i][j];
        }
    }

    int x1, y1, x2, y2;
    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        ans = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
        cout << ans << '\n';
    }


    return 0;
}