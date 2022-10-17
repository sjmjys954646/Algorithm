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
int N, M;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    map<string, int> m1;
    map<int, string> m2;

    rep1(i, N)
    {
        string tmp;
        cin >> tmp;
        m1[tmp] = i;
        m2[i] = tmp;
    }
    rep(i, M)
    {
        string k;
        cin >> k;
        if ('0' <= k[0] && k[0] <= '9')
        {
            int p = stoi(k);
            cout << m2[p] << "\n";
        }
        else
        {
            cout << m1[k] << "\n";
        }
    }
    
}