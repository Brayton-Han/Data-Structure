#include <iostream>
#define ll long long
using namespace std;
ll n, l, r;
int ans=0;

void work(ll n, ll lef, ll rgt)
{
	if(lef>r || rgt<l || n==0)
		return;
	if(n==1){
		ans++;
		return;
	}
	ll mid = (lef+rgt)/2;
    work(n/2, lef, mid-1);
    work(n%2, mid, mid);
    work(n/2, mid+1, rgt);
}

int main()
{
    scanf("%lld%lld%lld", &n, &l, &r);
    ll len=1, temp=n;
    while(temp>1){
    	len = 2*len + 1;
    	temp /= 2;
	}
    work(n, 1, len);
    printf("%d", ans);
    return 0;
}
