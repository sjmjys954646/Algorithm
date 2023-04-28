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

ll N, M, K;
ll seg[4000002];

//ll arr[4000002];
//
//ll init(ll start, ll end, ll node) 
//{
//    ll mid = (start + end)/2;
//    if (start == end)
//        return seg[node] = arr[start];
//    else
//        return seg[node] = init( node * 2, start, mid) + init( node * 2 + 1, mid + 1, end);
//}

void update(ll pos, ll val, ll node, ll x, ll y)
{
    if (pos < x || y < pos)
        return;

    seg[node] += val;

    if (x == y)
        return;

    ll mid = (x + y) / 2;

    update(pos, val, node * 2, x, mid);
    update(pos, val, node * 2 + 1, mid + 1, y);
}

ll query(ll f, ll node, ll x, ll y)
{
    //cout << f << " " << x << " " << y <<" " << seg[node] << "\n";
    if(x == y)
        return x;

    ll mid = (x + y) / 2;

    if (seg[node * 2] >= f)
        return query(f, node * 2, x, mid);
    else
        return query(f - seg[node * 2], node * 2 + 1, mid + 1, y);
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N;

    cin >> N;

    rep(i, N)
    {
        int op;
        int a, b;
        cin >> op;
        if (op == 2)
        {
            cin >> a >> b;
            update(a, b, 1, 1, 1000000);
        }
        else
        {
            cin >> a;
            ll p = query(a, 1, 1, 1000000);
            cout << p << "\n";
            update(p, -1, 1 , 1, 1000000);
        }
    }

	return 0;
}