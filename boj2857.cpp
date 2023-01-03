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
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    vi v;

    for (int i = 0; i < 5; i++)
    {
        string tmp;
        cin >> tmp;

        if (tmp.find("FBI") != string::npos)
        {
            v.push_back(i + 1);
        }
    }

    if (!v.size())
        cout << "HE GOT AWAY!";
    else
    {
        for (auto i : v)
            cout << i << " ";
    }

    return 0;
}