// freopen("input.txt", "r", stdin);
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 987654321;

int main() 
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  string tmp;
  string ans = "";
  string query;
  
  cin >> tmp;

  for(int i = 0;i<tmp.size();i++)
  {
      if(tmp[i] >= '0' && tmp[i] <= '9')
        continue;
      ans+=tmp[i];
    }
  cin >> query;
  
  if(ans.find(query) != std::string::npos)
    cout<<1;
  else
    cout<<0;
  
}