#include <iostream>

using namespace std;

int GCD(int a, int b)
{
	while(b!=0)
	{
		int r =a%b;
		a = b;
		b=r;
	}
	
	return a;
}

int LCM(int a, int b)
{
	return a*b/GCD(a,b);
}

int main(void)
{
	int T;
	int M,N,x,y;
	
	cin >> T;
	
 	for(int i =0;i<T;i++)
	{
		cin>>M>>N>>x>>y;
		
		while(true)
		{
			if(x>LCM(M,N) || (x-1)%N+1 == y)
				break;
			
			x+=M;
		}
		
		if(x>LCM(M,N))
		{
			cout<<"-1\n";
		}
		else
		{
			cout<<x<<"\n";
		}
	}
	return 0;
}