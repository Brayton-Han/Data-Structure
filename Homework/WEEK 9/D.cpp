#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int B = 131;
int n, ans[1000015];
char s[1000015];
ll Hash[1000015], pp[1000015];

ll get_Hash(int s, int e) 
{
    ll res = (Hash[e] - pp[e-s+1]*Hash[s-1])%mod;
    if(res<0) 
        res += mod;
    return res;
}

bool check(int mi, int x) 
{
    return get_Hash(mi-x+1, mi+x-1) == get_Hash(n+1-mi-x+1, n+1-mi+x-1);
}

int main() 
{
    scanf("%d%s", &n, s+1);
    pp[0] = 1;
    for(int i=1; i<=n; ++i){
        Hash[i] = (Hash[i-1]*B + s[i])%mod;
        pp[i] = pp[i-1]*B%mod;
    }
    memset(ans, -1, sizeof(ans));
    for(int i=1; i<=n+1>>1; ++i){
        int s=1, e=i, mi, res=0;
        if(2*i == n+1) 
            break;
        while(s <= e){
            mi = s+e>>1;
            if(check(i, mi)){
                res = mi;
                s = res+1;
            }
            else 
                e = mi-1;
        }
        ans[i-res+1] = max(ans[i-res+1], 2*res-1);
    }
    for(int i=1; i<=n+1>>1; ++i) 
    {
        ans[i] = max(ans[i-1]-2, ans[i]);
        printf("%d ", ans[i]);
    }
    return 0;
}