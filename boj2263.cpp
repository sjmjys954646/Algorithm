#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int N;
int idx[100001];
vector<int> inorder;
vector<int> postorder;
void make(int inBeg,int inEnd, int posBeg,int posEnd)
{
  if(inBeg > inEnd || posBeg > posEnd)
    return;
  
  const int root = postorder[posEnd];
  
  cout<<root<<" ";

  make(inBeg,idx[root] - 1,posBeg,posBeg + (idx[root] - inBeg) - 1);
  make(idx[root]+1,inEnd,posBeg + (idx[root] - inBeg),posEnd - 1);

}

int main() 
{
  cin>>N;

  for(int i = 0;i<N;i++)
  {
    int p;
    cin>>p;
    inorder.push_back(p);
  }
  for(int i = 0;i<N;i++)
  {
    int p;
    cin>>p;
    postorder.push_back(p);
  }

  for(int i = 0;i<N;i++)
  {
    idx[inorder[i]] = i;
  }

  make(0,N-1,0,N-1);
  
	return 0;
}