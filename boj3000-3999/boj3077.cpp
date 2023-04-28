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

vector<string> ans;
vector<string> query;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string tmp;
    map<string,int> m;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        ans.push_back(tmp);
        m[tmp] = i;
    }
    
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        query.push_back(tmp);
    }

    int sum = 0;
    for (int i = 0; i < N-1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (m[query[i]] < m[query[j]])
                sum++;
        }
    }

    int p = N * (N - 1) / 2;
    cout << sum << "/" << p;

    return 0;
}