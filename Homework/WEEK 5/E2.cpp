#include <iostream>
#include <cstring>
using namespace std;
const int sz=1000005;
int n, m, a[sz], cnt[sz], num[sz];

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
    int ans=1,t=0,tmp;
    memset(num,0,sizeof(num));
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]<=m) 
            num[a[i]]++;
    }
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=m;i++){
        if(num[i]==0) 
            continue;
        for(int j=i;j<=m;j+=i)
            cnt[j]+=num[i];
    }
    for(int i=1;i<=m;i++){
        if(cnt[i]>t){
            t=cnt[i];
            ans=i;
        }
    }
    printf("%d %d\n",ans,t);
    for(int i=1;t>0&&i<=n;i++)
        if(a[i]<=ans&&ans%a[i]==0)
            printf("%d ",i);
    printf("\n");
    return 0;
}
