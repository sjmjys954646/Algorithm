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

int N, M;
int Q;
int a, b;

int main()
{
    cin >> N >> M >> Q;

    string ans = "";

    for(int i = 0;i<Q;i++)
    {
        cin >> a >> b;
    }
    int index = 0;
    for (int i = 0; i < M; i++)
    {
        if (index == N)
            index = 0;

        ans += char(index + 'a');

        if(i%2 == 1)
            index++;
    }
    cout << ans;

    return 0;
}