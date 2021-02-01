#include <iostream>
#include <algorithm>
#include <string>
#include <string.h> 
#include <limits.h>
#include <vector>
#include <list>
using namespace std;
int n, num, temp;
list<long long> li;
long long t; 

int main()
{
	cin >> num;
	while(num--){
		cin >> n;
		for(int i=0; i<n; ++i){
			cin >> temp;
			li.push_back(temp);
		}
		auto it = li.begin();
		it++;
		while(it!=(li.end()--)){
			auto iter = it;
			if(*(--iter)<*(++iter) && *(iter++)>*(iter--) && *(iter--)<(*(iter++)+*(++iter))){
				t = *(iter--)+*(--iter);
				iter = li.erase(iter);
				*(iter++) = t;
				it = li.erase(iter);
				it--;
				if(it!=li.begin()) it--;
				if(it!=li.begin()) it--;
			}
			it++;
		}
		it = li.begin();
		while(it != li.end())
			cout << *(it++) << ' ';
		cout << endl;
		li.clear();
	}
	return 0;
}
