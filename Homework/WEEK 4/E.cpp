#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits.h>
using namespace std;
int n;
string a, b, c, d;

int main()
{
	cin >> n;
	for(int f=1; f<=n; ++f){
		cin >> a >> b;
		c=a; d=b;
		int maxsize=max(a.size(), b.size());
		int minsize=min(a.size(), b.size());
		int flag = a.size()>=b.size() ? 1 : 0;
		int y[1000]={0};
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		for(int i=0; i<maxsize; ++i)
			if(i<minsize)
				y[i] = int(a[i]+b[i])-96;
			else if(flag)
				y[i] = int(a[i])-48;
			else
				y[i] = int(b[i])-48;
		for(int i=1; i<=maxsize; ++i){
			y[i] += y[i-1]/10;
			y[i-1] %= 10;
		}
		if(!y[maxsize])
			maxsize--;
		cout << "Case " << f << ':' << endl;
		cout << c << " + " << d << " = ";
		for(int i=maxsize; i>=0; --i)
			cout << y[i];
		cout << endl;
		if(f!=n)
			cout << endl;
    }
	return 0;
}
