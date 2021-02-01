#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int n, a[100][100], max_sum=INT_MIN;

void oneDimention(vector<int>& v)
{
	int pre = 0;
    for(int y=0; y<v.size(); ++y){
        pre = max(pre + v[y], v[y]);
        max_sum = max(max_sum, pre);
    }
}

int main()
{
	cin >> n;
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			cin >> a[i][j];	
	for(int i=1; i<n; ++i)
		for(int j=0; j<n; ++j)
			a[i][j] += a[i-1][j];
	for(int i=0; i<n; ++i)
		for(int j=i; j<n; ++j){
			vector<int> vec;
			for(int k=0; k<n; ++k)
				if(i==0) 
					vec.push_back(a[j][k]);
				else 
					vec.push_back(a[j][k]-a[i-1][k]);
			oneDimention(vec);
		}
	cout << max_sum << endl;
	return 0;
}
