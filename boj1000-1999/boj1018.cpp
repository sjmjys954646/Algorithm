#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int M, N;
	int ans = 65;
	
	cin>>M>>N;
	
	char arr[M][N];
	
	for(int i =0;i<M;i++)
	{
		for(int j =0;j<N;j++)
		{
			cin>>arr[i][j];
		}
	}	
	
	for(int i =0;i<=M-8;i++)
	{
		for(int j =0;j<=N-8;j++)
		{
			int total = 0;
			
			for(int m =0;m<8;m++)
			{
				for(int n =0;n<8;n++)
				{
					if((m+n)%2 == 0)
					{
						if(arr[i+m][j+n]==arr[i][j])
							continue;
						else
							total++;
					}
					else
					{
						if(arr[i+m][j+n]==arr[i][j])
							total++;
						else
							continue;
					}
				}
			}
			
			if(total>=32)
				total = 64 - total;
			
			if(ans>=total)
				ans = total;
		}
	}
	
	cout<<ans;
	
	return 0; 
}