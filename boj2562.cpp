#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int max = 0;
	int ans = 0;
	int N;
	
	for(int i =0;i<9;i++)
	{
		cin>>N;
		if(max<N)
		{
			max=N;
			ans=i+1;
		}
	}
	
	cout<<max<<"\n"<<ans;
	
}

