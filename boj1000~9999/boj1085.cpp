#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int x, y, w, h;
	int ans;
	vector<int> vec;
	
	cin>>x>>y>>w>>h;
	
	vec.push_back(w-x);
	vec.push_back(h-y);
	vec.push_back(x);
	vec.push_back(y);
	
	sort(vec.begin(),vec.end());
	
	cout<<vec.front();
	
	return 0;
}