#include <iostream>
using namespace std;

int main(void)
{
	int N, A, B;
	
	cin>>N;
	
	for(int i=0;i<N;i++)
	{
		cin>>A>>B;
		cout<<"Case #"<<i+1<<": "<<A<<" + "<<B<<" = "<<A+B<<"\n";
	}
	
	return 0;
}