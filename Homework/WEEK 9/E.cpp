#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
int n, m, k, block[1000005], cost[1000005], len=0;
ll ans=0x7fffffffffffffff, temp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    memset(block, 0, sizeof(block));
    for(int i=0, t; i<m; ++i){
        cin >> t;
        block[t]=1;
    }
    for(int i=1; i<=k; ++i)
        cin >> cost[i];
    if(block[0]){
        cout << -1 << endl;
        return 0;
    }
    for(int i=1; i<n; ++i)
        if(block[i]){
            block[i] += block[i-1];
            len = max(len, block[i]);
        }
    if(len>=k){
        cout << -1 << endl;
        return 0;
    }
    for(int i=len+1; i<=k; i++){
        temp=0;
        for(int j=0; j<n; j+=i,temp++)
            if(block[j]) 
                j -= block[j];
        ans = min(ans, temp*cost[i]);
    }
    cout << ans << endl;
    return 0;
}