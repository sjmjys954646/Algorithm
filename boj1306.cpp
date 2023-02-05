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

vector<ll> tree;
vector<ll> a;
int n, m;

long long init(int node, int start, int end) {
    if (start == end) 
    {
        return tree[node] = a[start];
    }
    else 
    {
        return tree[node] = max(init(node * 2, start, (start + end) / 2) ,init(node * 2 + 1, (start + end) / 2 + 1, end));
    }
}

void update(int node, int start, int end, int index, long long diff) 
{
    if (index < start || index > end) return;

    tree[node] = tree[node] + diff;

    if (start != end) 
    {
        update( node * 2, start, (start + end) / 2, index, diff);
        update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
}

long long query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) 
        return 0;

    if (left <= start && end <= right) 
    {
        return tree[node];
    }

    return max(query( node * 2, start, (start + end) / 2, left, right), query(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    a.resize(n);
    tree.resize(4 * n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    init(1, 0, n - 1);



    for (int i = m - 1; i <= n - m; i++)
    {
        cout << query(1, 0, n - 1, i - (m-1) , i + (m - 1)) << " ";
    }

	return 0;
}