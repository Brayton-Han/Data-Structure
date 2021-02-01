#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
int n, a[200005], cnt[200005], pre[200005];
long long ans=1;
int main()
{
    cin >> n;
    for(int i=1; i<=200004; ++i)
        pre[i] = n, cnt[i] = 0;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        if(i-pre[a[i]]>1)
            ans = (ans+cnt[a[i]])%mod;
        else if(i-pre[a[i]]==1)
            cnt[a[i]]--;
        cnt[a[i]]++;
        pre[a[i]] = i;
    }
    cout << ans << endl;
    return 0;
}