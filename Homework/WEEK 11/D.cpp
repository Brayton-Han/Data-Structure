#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, ans=0;

bool check(ll k)
{
    ll x = n, cnt = 0;
    while(x > 0){
        cnt += min(x, k);//x<k不够吃,此时吃了x个
        x -= k;
        x -= x/10;
    }
    return cnt >= (n+1)/2;//注意奇数
}

int main()
{
    scanf("%lld", &n);
    ll l = 1, r = (n+1)/2, m = (l+r)/2;
    while(l < r){
        if(check(m)) 
            ans = r = m;
        else 
            l = m+1;
        m = (l+r)/2;
    }
    if(ans == 0) 
        ans = 1;//n = 1的特殊情况
    printf("%lld\n", ans);
    return 0;
}