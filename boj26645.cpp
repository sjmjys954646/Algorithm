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


int main()
{
    int tmp;
    cin >> tmp;

    if (200 <= tmp && tmp <= 205)
        cout << 1;
    else if (206 <= tmp && tmp <= 217)
        cout << 2;
    else if (218 <= tmp && tmp <= 228)
        cout << 3;
    else 
        cout << 4;

    return 0;
}