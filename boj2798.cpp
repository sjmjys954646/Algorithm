#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N, M, Q, Sum;
	int Ans = 0;
	vector<int> v;
	
	cin>>N>>M;
	
	for(int i =0;i<N;i++)
	{
		cin>>Q;
		v.push_back(Q);
	}
	
	for(int i =0;i<N;i++)
	{
		for(int j =i+1;j<N;j++)
		{
			for(int k=j+1;k<N;k++)
			{
				Sum = v[i]+v[j]+v[k];
				if(Sum>M)
					continue;				
				else if(Sum<=M && Sum>=Ans)
					Ans=Sum;					
			}
		}
	}
	
	cout<<Ans;
	return 0;
}