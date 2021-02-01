#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
deque<int> d;
int a[1000002], N, K, ans;

int main()
{
    cin >> N >> K;
    a[0]=0; ans=N+1; d.push_back(0);
    for(int i=1; i<=N; ++i){
    	cin >> a[i];
    	a[i] += a[i-1];
	}
    for(int i=1; i<=N; ++i){
    	while(d.size()>0 && a[d.back()]>=a[i])
    		d.pop_back();
    	d.push_back(i);
    	while(a[d.back()]-a[d.front()]>=K){
    		ans = min(ans, d.back()-d.front());
    		d.pop_front();
		}
	}
    if(ans==N+1)
    	cout << -1 << endl;
    else
    	cout << ans << endl;
    return 0;
}
