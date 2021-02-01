#include <iostream>
#include <cstdio>
#include <string.h>
#include <list>
using namespace std;
char s[100000];
list<char> li;

int main()
{
	while(scanf("%s",s)==1){
		int n=strlen(s), fast=0, slow=0;
		while(slow<n)
		{
			if(s[slow]=='[')
				slow++;
			else if(s[slow]==']')
			{
				slow++; fast=slow;
			}
			else
			{
				if(fast==slow)
				{
					li.push_back(s[slow]);
					fast=++slow;
				}
				else if(fast==0)
					li.insert(li.begin(), s[slow++]);
			}
		}
		auto it=li.begin();
		while(it!=li.end())
			cout << *it;
		cout << endl;
		li.clear();
	}
	return 0;
}
