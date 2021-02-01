#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, x, left, right, ans=0, temp=1;
	cin >> n >> x;
	while(n){
		cin >> left >> right;
		temp += (left-temp)/x*x;
		ans += right-temp+1;
		temp = right+1;
		n--;
	}
	cout << ans << endl;
	return 0;
}
