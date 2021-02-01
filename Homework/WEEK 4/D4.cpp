#include <iostream>
#include <string>
using namespace std;
int first, second, m;
string s, one, two, three;

bool check()
{
	one=s.substr(0, first);
	two=s.substr(first, second-first);
	three=s.substr(second, m-second);
	long long sum1=0, sum2=0, sum3=0;
	for(int i=0; i<first; ++i)
		sum1=(10*sum1+one[i])%1000000007;
	for(int i=0; i<second-first; ++i)
		sum2=(10*sum2+two[i])%1000000007;
	for(int i=0; i<m-second; ++i)
		sum3=(10*sum3+three[i])%1000000007;
	if(sum3==sum1+sum2)
		return 1;
	else
		return 0;
}

print()
{
	cout << one << '+' << two << '=' << three;
}

int main()
{
	cin >> s;
	m=s.size();
	int bottom = m/3, top = m/2;
	first=1; second=m-top;
	for(second= m%2 ? m/2+1 : m/2; second<=m-m/3; ++second)
	{
        int len=m-second;
        if(s[second+1] == '0' && len!=1)	continue;
    	first = second-len;
        if((s[first+1]!='0' || len==1) && check())	{print(); break;}
        first = len;
        if((s[first+1]!='0' || second==len+1) && check())	{print(); break;}
        first = second-len+1;
        if((s[first+1]!='0' || len==2) && check())	{print(); break;}
        first = len-1;
        if((s[first+1]!='0' || second==len) && check())	{print(); break;}
	}
	return 0;
} 
