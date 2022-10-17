#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;


long long S,F;
long long arr[1000006];
vector<long long> zegop;


int main() 
{
  cin >> S >> F;

  long long tmp = (long long)sqrt(F);
  for(long long i = 2;i<=tmp;i++)
  {    
    zegop.push_back(i*i);
  }
 
  for(long long i = 0;i<zegop.size();i++)
  {
    long long div_min = S;
    if(div_min % zegop[i] != 0)
    {
      div_min = (S/zegop[i] + 1) * zegop[i];
    }
    
    for(long long j = div_min;j<=F;j+=zegop[i])
    {
      if(!arr[j-S])
      {
        arr[j-S] = 1;
      }
    }
  }

  long long sum = 0;
  for(long long i = 0;i<F - S + 1;i++)
  {
    if(!arr[i])
    {
      sum++;
    }
  }

  cout<<sum;

	return 0;
  
}