#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int par[100003];
int G;
int P;

int find(int a)
{
  if(a==par[a])
    return a;
  return par[a] = find(par[a]);
}

void merge(int a, int b)
{
  a = find(a);
  b = find(b);
  if(a!=b)
  {
    par[a] = b;
  }
}

int main() 
{
  int ans= 0;
  cin >> G >> P;

  for(int i = 0;i<=G;i++)
  {
    par[i] = i;
  }

  for(int i = 0;i<P;i++)
  {
    int tmp;
    cin>>tmp;
    int p = find(tmp);
    if(p==0)
      break;
    ans++;
    par[p] = p-1;
  }
  cout<<ans;
	return 0;
}