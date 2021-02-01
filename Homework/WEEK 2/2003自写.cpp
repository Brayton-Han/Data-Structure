#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int s;
		cin >> s;
		vector<int> v(s);
		for(int i=0; i<s; ++i)
			cin >> v[i];
		sort(v.begin(), v.end());
		int i=(v[1]==v[0]+1 ? 0 : 1);
		for(int j=v[i==0 ? 0 : 1], flag=(i==0 ? 1 : 0); i<s; i++, j++){
			if(v[i]!=j && flag==1){
				flag=0;
				j--;
			}
			else if(v[i]!=j && flag==0){
				cout << "No" << endl;
				break;
			}
		}
		if(i==s)
			cout << "Yes" << endl;
	}
	return 0;
}
