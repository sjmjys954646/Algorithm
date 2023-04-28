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

int N, M, K, Q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    string A;
    string B;

    getline(cin, A);
    getline(cin, B);

    if (A.size() < B.size())
    {
        cout << 0;
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < A.size() - B.size() + 1; i++)
    {
        bool check = true;
        for (int j = 0; j < B.size(); j++)
        {
            if (B[j] != A[i + j])
                check = false;
        }
        if (check)
        {
            i += (B.size()-1);
            ans++;
        }
    }
    cout << ans;



    return 0;
}
