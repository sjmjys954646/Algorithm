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

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    vi av;
    vi bv;
    priority_queue<pii> pq;

    cin >> N >> M;;
    int tot = 0;

    for (int i = 0; i < M; i++)
    {
        cin >> a;
        av.push_back(a);
        tot += a;
    }

    for (int i = 0; i < M; i++)
    {
        cin >> b;
        bv.push_back(b);
    }

    for (int i = 0; i < M; i++)
    {
        pq.push({ bv[i] , 100 - av[i] });
    }
    int hour = N * 24;

    while (true)
    {
        if (hour == 0)
            break;

        if (pq.empty())
            break;

        pii p = pq.top();
        pq.pop();

        if (p.second >= p.first)
        {
            tot += p.first;
            pq.push({ p.first, p.second - p.first });
            hour-=1;
        }
        else
            pq.push({ p.second, p.second });
    }

    cout << tot;
    
    return 0;
}