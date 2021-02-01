#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
char target[1000002], pattern[1000002];
int m, n, Next[1000002];

void preprocessing()
{
	int i=0;
	int k=-1;
	Next[0]=-1;
	while(i<m)
		if(k==-1 || pattern[i]==pattern[k])
			Next[++i]=++k;
		else
			k = Next[k];
}

int KMP(char *t)
{
	for(int i=0, j=0; j<n;)
	{
		if(i==-1 || pattern[i]==t[j])
			{i++; j++;}
		else
			i=Next[i];
		if(i>=m)
			return j-i;
	}
	return -1;
}

int main()
{
	scanf("%s", target);
	scanf("%s", pattern);
	m = strlen(pattern);
	n = strlen(target);
	preprocessing();
	vector<int> v;
	char *a=target;
	int n_=n, temp=0;
	while(KMP(a)+1)
	{
		temp += KMP(a)+1;
		v.push_back(temp);
		a=target+temp;
		n=n_-temp;
	}
	auto it = v.begin();
	while(it != v.end())
		printf("%d\n", *(it++));
	for(int i=1; i<=m; ++i)
		printf("%d%c", Next[i], ' ');
	return 0;
}
