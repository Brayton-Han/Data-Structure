#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+9;
const int maxn=100005;
int n, k, depth[maxn];
ll ans=0, fac[maxn], inv[maxn];
vector<int> vec[maxn];

void dfs(int index, int last, int d)
{
    depth[index] = d;
    for(int i=0; i<vec[index].size(); ++i)
        if(vec[index][i]!=last)
            dfs(vec[index][i], index, d+1);
}

ll C(int m,int n) { return fac[n]*inv[m]%mod*inv[n-m]%mod; }
 
ll quick_pow(ll a,ll m)
{
    ll tmp=a%mod, an=1;
    while(m){
        if(m&1)
            an = an*tmp%mod;
        tmp = tmp*tmp%mod;
        m >>= 1;
    }
    return an;
}
 
void init()
{
    fac[0] = 1;
    for(int i=1; i<maxn; i++)
        fac[i] = (fac[i-1]*i)%mod;
    inv[maxn-1] = quick_pow(fac[maxn-1], mod-2);
    for(int i=maxn-2; i>=0; i--)
        inv[i] = (inv[i+1]*(i+1))%mod;
}
 
int main()
{
    init();
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    init();
    for(int i=1, x, y; i<n; ++i){
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    dfs(1, 0, 1);
    for(int i=1; i<=n; ++i)
        if(depth[i]>=k)
            ans = (ans+C(k-1, depth[i]-1))%mod;
    cout << ans << endl;
    return 0;
}
