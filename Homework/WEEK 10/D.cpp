#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=50005;
int point[N], next[N*10], n, tot=1, minn, ans[N], son[N];
bool f[N];

struct s{
    int st,en;
}aa[N*10];

void add(int x,int y)
{
    tot += 1;
    next[tot] = point[x];
    point[x] = tot;
    aa[tot].st = x;
    aa[tot].en = y;
}

void dfs(int x)
{
    int u, balance=0, i;
    f[x]=false;
    son[x]=0;
    for(i=point[x]; i; i=next[i]){
        u=aa[i].en;
        if(!f[u]) 
            continue;
        dfs(u);
        son[x] += son[u]+1;
        balance = max(balance, son[u]+1);
    }
    balance = max(balance, n-son[x]-1);
    if(balance<minn){
        ans[0] = 1;
        ans[1] = x;
        minn = balance;
    }
    else if(balance==minn){
        ans[0] += 1;
        ans[ans[0]] = x;
    }
}

int main()
{
    int i, j, x, y;
    cin >> n;
    memset(f, 1, sizeof(f));
    for(i=1; i<n; ++i){
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    minn=210000000;
    dfs(1);
    sort(ans+1, ans+ans[0]+1);
    for(i=1; i<=ans[0]; ++i)
      printf("%d ", ans[i]);
    printf("\n");
    return 0;
}