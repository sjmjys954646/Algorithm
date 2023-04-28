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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    deque<pii> dq;
    vi ans;

    cin >> k;

    rep(i, k)
    {
        int tmp;
        cin >> tmp;
        dq.push_back({ tmp,i + 1 });
    }

    while (true)
    {
        if (dq.size() == 1)
        {
            ans.push_back(dq.front().S);
            break;
        }

        pii t = dq.front();
        dq.pop_front();
        ans.push_back(t.S);

        pii tmp;
        if (t.F > 0)
        {
            for (int i = 1; i < t.F; i++)
            {
                tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
            }
        }
        else
        {
            int circuit = abs(t.F);
            for (int i = 0; i < circuit; i++)
            {
                tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp);

            }
        }
    }

    rep(i, ans.size())
    {
        cout << ans[i] << " ";
    }


    return 0;
}