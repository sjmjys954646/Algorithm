#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;

const ll INF = 9876543210;
const double pi = 3.14159265358979;
const ll MOD = 1000000007;

struct Point
{
    double x, y;

    bool operator<(const Point &a)
    {
        if (y == a.y)
            return x < a.x;
        else
            return y < a.y;
    }
};

ll ccw(pll a, pll b, pll c)
{
    ll ret = a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;

    if (ret > 0)
        return 1;
    else if (ret < 0)
        return -1;
    else
        return 0;
}

double dist(Point a, Point b)
{
    return (a.y - b.y) * (a.y - b.y) + (a.x - b.x) * (a.x - b.x);
}

int manhat(int startX, int startY, int endX, int endY)
{
    return abs(startX - endX) + abs(startY - endY);
}

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

double round_digit(double num, int d)
{
    double t = pow(10, d - 1);
    return round(num * t) / t;
}

bool crossChk(pll a, pll b, pll c, pll d)
{
    ll abc = ccw(a, b, c);
    ll abd = ccw(a, b, d);
    ll cda = ccw(c, d, a);
    ll cdb = ccw(c, d, b);

    if (abc * abd == 0 && cda * cdb == 0)
    {
        if (a > b)
            swap(a, b);
        if (c > d)
            swap(c, d);

        return a <= d && c <= b;
    }

    return abc * abd <= 0 && cda * cdb <= 0;
}

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    map<string, int> m;
    map<string, int> conv;
    vi v;

    string tmp;

    rep(i, N)
    {
        cin >> tmp;
        if (m.count(tmp) == 0)
            m[tmp] = 1;
        else
            m[tmp]++;
    }

    rep1(i, M)
    {
        cin >> tmp;
        conv[tmp] = i;
    }

    rep(i, M + 1)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int ans = 0;
    for (auto i : m)
    {
        if (conv.count(i.first))
        {
            ans += i.second * v[conv[i.first]];
        }
        else
        {
            ans += i.second * v[0];
        }
    }
    cout << ans;

    return 0;
}