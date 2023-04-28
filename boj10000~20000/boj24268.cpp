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

vector<long long> v[10];
vector<long long> hubo;
int visited[10];
long long N, d;

long long rev(long long tmp)
{
    long long revret = 0;
    string ret = to_string(tmp);
    int indexMul = 1;
    int index = 0;
    int fin = ret.size();
    reverse(ret.begin(), ret.end());
    while (true)
    {
        if (index == fin)
            break;
        revret += indexMul * (ret[index] - '0');
        index++;
        indexMul *= d;
    }

    return revret;
}



void select(int index, int fin)
{
    if (index == fin)
    {
        if (hubo.empty())
            return;

        if (hubo[0] == 0)
            return;

        string k = "";

        for (auto i : hubo)
            k += i + '0';

        //cout << k << " " << rev(stoll(k)) << "\n";

        v[fin].push_back(rev(stoll(k)));
        return;
    }

    for (int i = 0; i < fin; i++)
    {
        if (visited[i] == 1)
            continue;

        visited[i] = 1;
        hubo.push_back(i);
        select(index + 1, fin);
        hubo.pop_back();
        visited[i] = 0;

    }
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> d;

    select(0, d);
    sort(v[d].begin(), v[d].end());

    string tmp = "";
    long long t = N;

    auto it = upper_bound(v[d].begin(), v[d].end(), N);

    //cout << *it << "\n";

    if (it == v[d].end())
        cout << -1;
    else
        cout << *it;

    return 0;

}