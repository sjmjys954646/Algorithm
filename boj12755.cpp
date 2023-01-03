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

const int INF = 9876543210;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    int cur = 1;
    int N;
    int p = 0;

    cin >> N;

    while(true)
    {
        string tmp = to_string(cur);
        //cout << N << " " << tmp<<"\n";
        if (tmp.size() < N)
        {
            N -= tmp.size();
            cur++;
        }
        else
        {
            for (int i = 0; i < N; i++)
            {
                p = tmp[i] - '0';
            }
            break;
        }
    }
    cout << p;
    

    return 0;
}