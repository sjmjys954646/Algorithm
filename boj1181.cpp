#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string s1, string s2)
{
	if(s1.size() == s2.size())
	{
		return s1<s2;
	}
	return s1.size() < s2.size();
}

int main(void)
{
	int T;
	string word;
	vector<string> all;
	
	cin>>T;
	
	for(int i =0;i<T;i++)
	{
		cin>>word;
		all.push_back(word);
	}
	
	sort(all.begin(), all.end(), comp);
	
	for(int i =0;i<T;i++)
	{
		if(i)
		{
			if(!all[i].compare(all[i-1]))
			{
				continue;
			}		   
		}
		cout<<all[i]<<"\n";
	}
	
	return 0;
}
