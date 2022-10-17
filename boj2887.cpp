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

int N;
vector<pair<int, int> > arrx;
vector<pair<int, int> > arry;
vector<pair<int, int> > arrz;
vector<pair<int ,pair<int, int> > > v;
int root[100001];

int find(int x) 
{
	if (root[x] == x) 
    return x;
  else
	  return root[x] = find(root[x]);
}

bool merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) 
    return false;
	root[a] = b;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;

  for(int i = 0;i<100001;i++)
  {
    root[i] = i;
  }

	int a, b, c;

	for (int i = 0; i < N; i++) 
  {
		cin >> a >> b >> c;
	  arrx.push_back({a,i});
    arry.push_back({b,i});
    arrz.push_back({c,i});
	}

	sort(arrx.begin(),arrx.end());
  for(int i = 0;i<N-1;i++)
  {
    int dis = arrx[i+1].first - arrx[i].first;
    v.push_back({dis,{arrx[i+1].second,arrx[i].second}});
  }
  sort(arry.begin(),arry.end());
  for(int i = 0;i<N-1;i++)
  {
    int dis = arry[i+1].first - arry[i].first;
    v.push_back({dis,{arry[i+1].second,arry[i].second}});
  }
  sort(arrz.begin(),arrz.end());
  for(int i = 0;i<N-1;i++)
  {
    int dis = arrz[i+1].first - arrz[i].first;
    v.push_back({dis,{arrz[i+1].second,arrz[i].second}});
  }

	sort(v.begin(), v.end());

  long long sum = 0;
  int cnt = 0;
	for(int i=0;i<v.size();i++)
  {
		int cost = v[i].first;
		int a = v[i].second.first;
		int b = v[i].second.second;

    if(merge(a,b))
    {
      sum+=cost;
      cnt++;
      if(cnt==N-1)
        break;
    }
	}
	
  cout<<sum;

	return 0;
}