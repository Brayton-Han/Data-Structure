#include <bits/stdc++.h>
using namespace std;
vector <int> v;

int main() 
{
	int n , k;
	cin >> n >> k;
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 1 ; i < s.length() ; i++)
		if(s[i] == s[i - 1])
			ans++;
	ans = min(2 * k + ans , n -1); 
	cout << ans << "\n";
	return 0;
}
