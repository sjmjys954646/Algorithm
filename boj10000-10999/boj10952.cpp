#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int A, B;
	
	while(1)
	{
		cin>>A>>B;
		if(A==0 && B==0)
			break;
		else
			cout<<A+B<<"\n";
	}
}

