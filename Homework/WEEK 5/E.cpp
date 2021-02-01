#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n, m, temp, x, si, a[1000002], lcm=1;
vector<int> v;

bool judge()
{
    int x_=x, lcm_=lcm;
    while(lcm_!=0){
    	temp = x_%lcm_;
    	x_ = lcm_;
    	lcm_ = temp;
	} 
    if(x*lcm/x_<=m){
        lcm = max(x*lcm/x_, lcm);
        return 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    memset(a, 0, sizeof(a));
    cin >> n >> m;
    for(int i=1; i<=n; ++i)
        cin >> a[i];
    for(int i=1; i<=n; ++i){
    	if(a[i]>m) continue;
        x=a[i];
        if(judge())
            v.push_back(i);
    }
    si=v.size();
    sort(v.begin(), v.end());
    cout << lcm << ' ' << si << endl;
    auto it=v.begin();
    while(it!=v.end())
        cout << *(it++) << ' ';
    cout << endl;
    return 0;
}
