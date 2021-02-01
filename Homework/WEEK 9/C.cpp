#include <iostream>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const ll M=1000000006;
const ll ini=333333336;
int k;
ll a, down=1, sum=1, up, sign=1;

ll fastPower(ll bas, ll power) {
    ll result=1;
    while(power){
        if (power&1)
            result = result*bas%mod;
        bas = (bas*bas)%mod;
        power /= 2;
    }
    return result;
}

int main()
{
    scanf("%d", &k);
    while(k--){
        scanf("%lld", &a);
        a %= M;
        sum = sum*a%M;
    }
    if(sum==0) 
        sum = M;
    if(sum&1)
        sign = -1;
    down = fastPower(2, sum-1);
    up = (down+sign)*ini%mod;
    cout << up << '/' << down << endl;
    return 0;
}