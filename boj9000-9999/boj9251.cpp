#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
using std::string;

inline int max( int x,  int y) { return x < y ? y : x;} 
	  
int LCS(string A, string B)
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
	
	return Arr[B.length()][A.length()];
}

int main(void)
{
	string A;
	string B;	
	
	cin>>A>>B;
	
	cout<<LCS(A,B);
	
	return 0;
}
