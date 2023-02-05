#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <string>
#include <cmath>
#include <map>
#include <stack>
#include <sstream>
#include <string.h>
#include <queue>
using namespace std;

const long long INF = 987654321;

int root[10002];
int V, E;
vector<pair<long long, pair<long long, long long> > > arr;

int find(int a)
{
    if (root[a] == a)
        return a;
    else
        return root[a] = find(root[a]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    root[a] = b;
}

bool cmp(pair<long long, pair<long long, long long> > a, pair<long long, pair<long long, long long> > b)
{
    return a.second.second < b.second.second;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

    while (true)
    {
        memset(root, 0, sizeof(root));
        arr.clear();
        int sum = 0;
        cin >> V >> E;

        if (V == 0 && E == 0)
            break;

        for (int i = 0; i < E; i++)
        {
            long long u1, u2, d;
            cin >> u1 >> u2 >> d;
            arr.push_back({ u1, {u2,d} });
            arr.push_back({ u2, {u1,d} });
            sum += d;
        }

        sort(arr.begin(), arr.end(), cmp);

        for (int i = 0; i < V + 1; i++)
        {
            root[i] = i;
        }

        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            int a = find(arr[i].first);
            int b = find(arr[i].second.first);
            if (a == b)
                continue;
            else
            {
                ans += arr[i].second.second;
                merge(arr[i].first, arr[i].second.first);
            }
        }

        cout << sum - ans << "\n";
    }

    

	return 0;
}
