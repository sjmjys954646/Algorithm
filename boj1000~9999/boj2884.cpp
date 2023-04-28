#include <iostream>
using namespace std;

int main(void)
{
	int A, B;
	
	cin>>A>>B;
	
	if(B-45<0)
	{
		if(A==0)
			cout<<23<<" "<<B+15;
		else
			cout<<A-1<<" "<<B+15;
	}
	else
		cout<<A<<" "<<B-45;
	
	return 0;
}