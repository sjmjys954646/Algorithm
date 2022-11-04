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
vi v[102];
int score[102];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    rep1(i, N)
    {
        rep(j, M)
        {
            int tmp;
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }

    rep1(i, N)
    {
        sort(v[i].begin(), v[i].end());
    }

    int maxi;
    rep(t, M)
    {
        maxi = -1;
        rep1(i, N)
        {
            maxi = max(v[i][t], maxi);
        }

        rep1(i, N)
        {
            if (v[i][t] == maxi)
            {
                score[i]++;
            }
        }
    }
    
    maxi = -1;
    vi ans;
    rep1(i, N)
    {
        if (score[i] > maxi)
        {
            ans.clear();
            ans.push_back(i);
            maxi = score[i];
        }
        else if (score[i] == maxi)
        {
            ans.push_back(i);
        }
    }

    sort(ans.begin(), ans.end());

    for (auto i : ans)
        cout << i << " ";
    

    return 0;

}