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

int K,N;
int arr[1001][27];
int fin[27];
int topres[27];
int botres[27];
int result[27];
int S;

int makeresult()
{
  int res = 1;
  for(int i = 0;i<K-1;i++)
  { 
    if(topres[i+1] == botres[i] && topres[i] == botres[i+1])
    {
      result[i] = 45;
    }
  }

  for(int i = 0;i<K-1;i++)
  {
    if(result[i] > 0)
      continue;
    
    if(topres[i] == botres[i] && topres[i+1] == botres[i+1])
    {
      result[i] = 42;
    } 
    else if(result[i-1]==45 || result[i+1]==45)
    {
      result[i] = 42;
    }
    else 
    {
      res = -1;
      break;
    }
  }

  return res;
}

void goline()
{
  for(int i = 0;i<K;i++)
  {
    topres[i] = i+65;
  }

  for(int i = 0;i<S;i++)
  {
    for(int j = 0;j<K-1;j++)
    {
      if(arr[i][j] == 45)
      {
        int tmp = topres[j+1];
        topres[j+1] = topres[j];
        topres[j] = tmp;
      }
    }
  }
  
  for(int i = 0;i<K;i++)
  {
    botres[i] = fin[i];
  }

  for(int i = N-1;i>S;i--)
  {
    for(int j = 0;j<K-1;j++)
    {
      if(arr[i][j] == 45)
      {
        int tmp = botres[j+1];
        botres[j+1] = botres[j];
        botres[j] = tmp;
      }
    }
  }
}


int main() 
{
  /*
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  */
  string a;
  scanf("%d %d",&K,&N);

  cin>>a;
  for(int i = 0;i<K;i++)  
  {
    fin[i] = a[i];
  }

  for(int i = 0;i<N;i++)
  {
    cin>>a;
    for(int j = 0;j<K-1;j++)
    {
      arr[i][j] = a[j];
      for(int j = 0;j<K-1;j++)
     {
        arr[i][j] = a[j];
        if(arr[i][j] == 63)
          S=i;
     }
    }
  }

  goline();

  int res = makeresult();

  if(res == -1)
  {
    for(int i = 0;i<K-1;i++)
    {
      cout<<"x";
    }
  }
  else
  {
    for(int i = 0;i<K-1;i++)
    {
      if(result[i]==42)
      {
        cout<<"*";
      }
      else if(result[i]==45)
      {
        cout<<"-";
      }
    }
  }


	return 0;
}