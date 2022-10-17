#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <iomanip>
using namespace std;

int n, m, p[1001],cnt;
double res;
typedef pair<double,pair<int, int>> P;
vector<pair<int, int>> v;
vector<P> pq;

int find(int x) 
{
	if (p[x] == x) 
    return x;
  else
	  return p[x] = find(p[x]);
}

bool merge(int a, int b)
 {
	a = find(a);
	b = find(b);
	if (a == b) 
    return false;
	p[a] = b;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m;

  for(int i = 0;i<1001;i++)
  {
    p[i] = i;
  }

	int a, b;

	for (int i = 0; i < n; i++) 
  {
		cin >> a >> b;
		v.push_back({ a,b });
	}

	for (int i = 0; i < n; i++)
 {
		for (int j = i + 1; j < n; j++)
    {
			double t = sqrt(pow(v[i].first - v[j].first, 2)+pow(v[i].second-v[j].second,2));
			pq.push_back({ t,{i,j} });
		}
	}

	for (int j = 0; j < m; j++) 
  {
		cin >> a >> b;
		merge(a - 1, b - 1);
	}

	sort(pq.begin(), pq.end());

	for(int i=0;i<pq.size();i++)
  {
		double cost = pq[i].first;
		int a = pq[i].second.first;
		int b = pq[i].second.second;

		if (merge(a, b)) {
			cnt++;
			res += cost;
			if (cnt == n - 1) break;
		}
	}
	cout <<fixed<<setprecision(2)<< res << '\n';
	return 0;
}