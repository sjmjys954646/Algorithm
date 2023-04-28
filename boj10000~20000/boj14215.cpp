// freopen("input.txt", "r", stdin);
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

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

vi v;

int main() 
{
    int tmp;
    for (int i = 0; i < 3; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    if (v[0] + v[1] > v[2])
        cout << v[0] + v[1] + v[2];
    else
        cout << (v[0] + v[1]) * 2 - 1;

    return 0;
}