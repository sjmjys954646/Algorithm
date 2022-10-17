#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
	int A,B;
	
	cin>>A>>B;
	
	if(A<B)
		cout<<"<";
	else if(A>B)
		cout<<">";
	else
		cout<<"==";
	return 0;
}