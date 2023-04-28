#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int M, Q, D, Ms;
	int Sum = 0;
	int Ans = 0;
	int c = 0;
	
	cin>>M;
	Ms= M;
	while(Ms!=0)
	{
		Ms/=10;
		c++;
	}
	for(int i =9*c;i>0;i--)
	{
		Q=M-i;
		D=Q;
		Sum+=Q;
		while(Q!=0)
		{
			Sum+=(Q%10);
			Q/=10;
		}
		if(Sum==M)
		{
			Ans = D;
			break;
		}
		Sum=0;
	}
	
	cout<<Ans;
	
	return 0;
}