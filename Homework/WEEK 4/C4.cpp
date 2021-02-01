#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string s;
char c;
size_t n;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		cin >> s;
		vector<int> v;
		c=s[0]; n=s.size(); pos=0;
		if(s.find(c, 1)==npos)
			return n;
		else{
			while(pos!=npos)
			{
				v.push_back(pos);
				pos = s.find(c, pos+1);
			}
			auto it=v.begin();
			int step=v[1]-v[0], len=step;
			for(int i=0; i+step<n; ++i)
			{
				if(s[i]!=s[i+step])
				{
					len+=step;
					i=*(it++);
				}
			}
		}
	}
	return 0;
}
