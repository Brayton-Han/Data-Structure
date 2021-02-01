#include <stdio.h>
#include <string.h>
using namespace std;
const int MAXN = 100010;
long long num[MAXN], head[MAXN];
long long n;
long long ans, tot;

struct Edge{
    long long to,next;
}edge[MAXN*2];

void init()
{
    memset(head,-1,sizeof(head));
    tot = 0;
}

void addedge(long long u,long long v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void dfs(long long u,long long pre)
{
    num[u] = 1;
    long long tmp = 0;
    for(long long i = head[u];i!= -1;i = edge[i].next){
        long long v = edge[i].to;
        if(v == pre)
            continue;
        dfs(v,u);
        ans += tmp*num[v];
        num[u] += num[v];
        tmp += num[v];
    }
    ans += tmp*(n-num[u]);
}

int main()
{
    long long u,v;
    scanf("%lld",&n);
    init();
    for(int i = 1;i < n;i++){
        scanf("%lld%lld",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    ans = 0;
    dfs(1,-1);
    tot = n*(n-1)*(n-2)/6;
    printf("%lld\n",tot-ans);
    return 0;
}