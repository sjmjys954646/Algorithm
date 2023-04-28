#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
using namespace std;

int N;
vector<pair<float, float> > point;
vector<pair<float, pair<int, int> > > arr;
int root[10001];

float dis(float a, float b)
{
  return sqrt(a*a + b*b);
}

int find(int a)
{
  if(root[a] == a)
    return a;
  else
    return root[a] = find(root[a]);
}

void merge(int a, int b)
{
  int num1 = find(a);
  int num2 = find(b);
  root[num1] = num2;
}

int main() 
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;

  for(int i = 0;i<N;i++)
  {
    float a, b;
    cin >> a >> b;
    point.push_back({a,b});
  }

  sort(point.begin(),point.end());

  for(int i = 0;i < N-1;i++)
  {
    for(int j = i+1;j < N;j++)
    {
      float distance = dis(point[j].first - point[i].first, point[j].second - point[i].second);
      arr.push_back({distance,{i,j}});
    }
  }

  sort(arr.begin(), arr.end());

  for(int i = 0;i<10001;i++)
  {
    root[i] = i;
  }
  
  float ans = 0;
  for(int i = 0;i<arr.size();i++)
  {
    int a = find(arr[i].second.first);
    int b = find(arr[i].second.second);
    if(a==b)
    {
      continue;
    }
    else
    {
      ans+=arr[i].first;
      merge(a,b);
    }
  }

  printf("%.2f",ans);

	return 0;
}