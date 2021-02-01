#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int mod = 1e9+9;
int n, k, depth[100005];
long long ans=0, fac[100005], inv[100005];
vector<int> vec[100005];

void dfs(int index, int last, int d)
{
    depth[index] = d;
    for(int i=0; i<vec[index].size(); ++i)
        if(vec[index][i]!=last)
            dfs(vec[index][i], index, d+1);
}

bool cmp(int& x, int& y) { return depth[x]>depth[y]; }

long long qpow(long long a, int b){
    long long ans = 1;
    int p = b-2;
    a = (a%p+p)%p;
    while(b){
        if(b&1) 
            ans = (a*ans)%p;
        a = (a*a)%p;
        b >>= 1;
    }
    return ans;
}

void init()
{
    fac[0] = inv[0] = 1;
    for(int i=1; i<100005; ++i){
        fac[i] = (fac[i-1]*i)%mod;
        inv[i] = qpow(fac[i], mod);
    }
}

long long C(int m, int n) { return fac[n]*inv[m]%mod*inv[n-m]%mod; }

int main()
{
    init();
    /*
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    init();
    for(int i=1, x, y; i<n; ++i){
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    dfs(1, 0, 1);
    sort(depth+1, depth+n+1, cmp);
    int i=1;
    while(depth[i]>=k){
        ans = (ans + C(k-1, depth[i]-1))%mod;
        i++;
    }
    cout << ans << endl;
    */
    cout << C(4, 7)%mod << endl;
    return 0;
}