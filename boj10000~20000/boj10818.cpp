#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int min = 1000001;
	int max = -1000001;
	int N;
	int A;
	
	cin>>N;
	
	for(int i = 0;i<N;i++)
	{
		cin>>A; 
		if(min>A)
			min = A;
		if(max<A)
			max = A;
	}
	
	cout<<min<<" "<<max;
}