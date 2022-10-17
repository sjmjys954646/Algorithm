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
int n, m, q;
int score[105];
int clearNum[105];
int wrong[105][17]; // 틀린시간
int clear[105][17]; // 통과했는지

struct team 
{
    int time, num, scorenum;

    bool operator <(const team& a)const 
    {
        if (scorenum == a.scorenum) 
        {
            if (time == a.time)
                return num < a.num;
            else
                return time < a.time;
        }
        return scorenum > a.scorenum;
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> q;

    int a, b, c;
    string tmp;
    vector<team> v;
    v.resize(n + 1);
    
    for (int i = 1; i <= n; i++)
        v[i].num = i;

    for (int i = 0; i < q; i++)
    {
        cin >> a >> b >> c >> tmp;
        if (clear[b][c] == -1)
            continue;

        if (tmp == "AC")
        {
            clear[b][c] = a;
            v[b].time += (a + 20 * wrong[b][c]);
            v[b].scorenum++;
            clear[b][c] = -1;
        }
        else
        {
            wrong[b][c]++;
        }
    }

    sort(v.begin(), v.end());

    for (auto i : v)
    {
        if (i.num == 0)
            continue;
        cout << i.num << " " << i.scorenum << " " << i.time << "\n";
    }


    return 0;
}