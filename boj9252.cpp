#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>

using namespace std;
using std::string;

inline int max( int x,  int y) { return x < y ? y : x;} 
	  
void LCS(string A, string B)
{
	int Arr[B.length()+1][A.length()+1];
	
	for(int i=0;i<A.length()+1;i++)
		Arr[0][i] = 0;
	for(int i=0;i<B.length()+1;i++)
		Arr[i][0] = 0;
	
	for(int i=1;i<A.length()+1;i++)
	{
		for(int j=1;j<B.length()+1;j++)
		{
			if(A[i-1]==B[j-1])
				Arr[j][i] = Arr[j-1][i-1] + 1;
			else
				Arr[j][i] = max(Arr[j][i-1],Arr[j-1][i]);
		}
	}
	
	cout<<Arr[B.length()][A.length()]<<"\n";

  int a = A.length();
  int b = B.length();
  stack<int> s;

  while(Arr[b][a] != 0)
  {
    if(Arr[b][a] == Arr[b][a-1])
      a--;
    else if(Arr[b][a] == Arr[b-1][a])
      b--;
    else
    {
      s.push(a);
      a--;
      b--;
    }
  }

 while (!s.empty())
 {
    cout <<A[s.top()-1];
    s.pop();
 }
}

int main(void)
{
	string A;
	string B;	
	
	cin>>A>>B;
	
	LCS(A,B);
	
	return 0;
}

