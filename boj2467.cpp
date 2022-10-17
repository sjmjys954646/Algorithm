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
vector<long long> acid;
vector<long long> basic;

int main() 
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  long long ans = 3000000000;
  long long ansA, ansB;
  long long A,B,C;
  int acidpos = 0;
  int basicpos = 0;

  cin >> N;

  for(int i = 0;i<N;i++)
  {
    int tmp;
    cin>>tmp;

    if(tmp > 0)
      acid.push_back(tmp);
    else
      basic.push_back(-tmp);
  }

  reverse(basic.begin(),basic.end());

  if(acid.size()<=1)
  {
    B = 3000000000;
  }
  else
  {
    B = acid[0] + acid[1];
  }

  if(basic.size()<=1)
  {
    C = 3000000000;
  }
  else
  {
    C = basic[0] + basic[1];
  }

  A = 3000000000;
  while(true)
  {
    if(acidpos >= acid.size() || basicpos >= basic.size())
      break;

    int T = abs(acid[acidpos] - basic[basicpos]);
    
    if(A > T)
    {
      A = T;
      ansA = -basic[basicpos];
      ansB = acid[acidpos];
    }

    if(acid[acidpos] > basic[basicpos])
    {
      basicpos++;
    }
    else
    {
      acidpos++;
    }
  }
  
  ans = min(min(A,B),C);

  if(ans == B)
  {
    ansA = acid[0];
    ansB = acid[1];
  }
  else if(ans == C)
  {
    ansA = -basic[1];
    ansB = -basic[0];
  }
  cout<<ansA<<" "<<ansB;

	return 0;
}