#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <limits.h>
using namespace std;
int n, m=INT_MIN;
string s;
list<int> a;

int main()
{
	cin >> n >> s;
	a.push_back(-1);
	for(int i=0; i<n; ++i){
		a.push_back(int(s[i]-'a'));
		m = max(m, int(s[i]-'a'));
	}
	a.push_back(-1);
	for(int i=m; i>=1; --i){
		auto it=a.begin(), iter=a.end();
		it++; iter--;
		while(it!=iter){
			auto itl = --it; it++;
			auto itr = ++it; it--;
			if(*it==i && ((i-1)==*itl || (i-1)==*itr)){
				it=a.erase(it);
				it--;
			}
			else
				it++;
		}
	}
	cout << n+2-a.size() <<endl;
	return 0;
}
