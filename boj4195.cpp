#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int par[200001];
int num[200001];

int find(int a)
{
  if(a==par[a])
    return a;
  return par[a] = find(par[a]);
}

int merge(int a, int b)
{
  a = find(a);
  b = find(b);
  if(a!=b)
  {
    par[a] = b;
    num[b]+=num[a];
    num[a] = 1;
  }
  return num[b];
}

int main() 
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int testcase;

  cin >>testcase;

  while(testcase--)
  {
    int count = 1;
    int n;
    map<string,int> m;

    cin>>n;
    for(int i = 1;i<=2*n;i++)
    {
      par[i] = i;
      num[i] = 1;
    }

    for(int i = 0;i<n;i++)
    {
      string a, b;
      cin>>a>>b;
      if(m.count(a)==0)
        m[a] = count++;
      if(m.count(b)==0)
        m[b] = count++;
      
      cout<<merge(m[a],m[b])<<"\n";
    }
    
    
  }


	return 0;
}