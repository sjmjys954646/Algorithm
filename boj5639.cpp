#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

vector<int> arr;

void traverse(int left, int right)
{
  if(left==right)
    return;

  int root = arr[left];
  int c = right;
  for(int i = left;i<right;i++)
  {
    if(root<arr[i])
    {
      c = i;
      break;
    }
  }

  if(right - left > 1)
  {
    traverse(left+1,c);
    traverse(c,right);
  }
  cout<<root<<"\n";
}

int main() 
{
  int tmp;
  while(cin>>tmp)
  {
      arr.push_back(tmp);
  }
  
  traverse(0,arr.size());
  


	return 0;
}