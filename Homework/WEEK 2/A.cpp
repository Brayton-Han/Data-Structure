#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int edge, r=0;

bool judge(int a[], int k)
{
	for(; k<=edge; ++k)
		if(a[k]==0){
			a[k]=1;
			return 0;
		}
	return 1;
}

int main()
{
	while(cin){
		int m, n, win=0, a[1000]={0};
		vector<int> vec;
		cin >> m >> n;
		if(m==0 && n==0) 
			break;
		r++; edge=m*n;
		while(n--){
			cin >> m;
			vec.push_back(m);
			a[m]=1;
		}
		auto it=vec.begin();
		while(it!=vec.end()){
			if(judge(a, *it)) 
				win++;
			it++;
		}
		cout << "Case " << r << ": " << win << endl;
	}
	return 0;
} 
