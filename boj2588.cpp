#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
	int A,B;
	int sum=0;
	
	cin>>A>>B;
	
	for(int i =0;i<3;i++)
	{
		cout<<A*(B%10);
		sum+=A*(B%10)*pow(10,(double)i);			
		B/=10;	
		cout<<"\n";
	}
	
	cout<<sum;
	
	return 0;
}