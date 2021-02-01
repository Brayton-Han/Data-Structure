#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string s1, s2;

string judge(string s)
{
	if(s.size()%2==1) 
		return s;
	int len=s.size();
	string s3=judge(s.substr(0,len/2));
	string s4=judge(s.substr(len/2,len/2));
	if(s3<s4)
		return s3+s4;
	else
		return s4+s3;
}
 
int main()
{
	ios::sync_with_stdio(false);
    cin >> s1 >> s2;
    if(judge(s1)==judge(s2))
    	cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
