#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
	int A, B, C, Q;
	
	cin>>A>>B>>C;
	
	if(C-B==0)
	{
		cout<<"-1";
		return 0;
	}
	
	Q=floor(A/(C-B))+1;
	
	if( Q <=0)
		cout<<"-1";
	else
		cout<<Q;
	
	return 0;
}