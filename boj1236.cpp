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

int N, M;
int arr[52][52];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int garo = 0;
    int sero = 0;
    int ans = 0;

    rep(i, N)
    {
        string tmp;
        cin >> tmp;
        rep(j, M)
        {
            if (tmp[j] == 'X')
                arr[i][j] = 1;
        }
    }

    rep(i, N)
    {
        bool chk = false;
        rep(j, M)
        {
            if (arr[i][j] == 1)
                chk = true;

           // cout << i << " " << j << "\n";
        }
        if (!chk)
            garo++;
    }

    rep(i, M)
    {
        bool chk = false;
        rep(j, N)
        {
            if (arr[j][i] == 1)
                chk = true;
            //cout << j << " " << i << "\n";
        }
        if (!chk)
            sero++;
    }
    
    cout << max(garo,sero);

    return 0;
}