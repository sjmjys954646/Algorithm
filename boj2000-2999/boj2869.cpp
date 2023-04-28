#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int A, B, C;
	
	cin>>A>>B>>C;
	
	if((C-A)%(A-B)!=0)
		cout<<(C-A)/(A-B)+2;
	else
		cout<<(C-A)/(A-B)+1;
	
	return 0;
}
