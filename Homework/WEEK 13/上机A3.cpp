#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<ctime>
#include<map>
#include<vector>
#include<stack>
#define inf 10000007
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int maxn=50002;
struct bwy 
{
    int x,y,dis;
}s[maxn];
int e[maxn],nex[maxn],lin[maxn],ver[maxn],len;
int f[maxn],fa[maxn][30],w[maxn][30],depth[maxn],vis[maxn];
void add(int x,int y,int z)
{
    ver[++len]=y;
    nex[len]=lin[x];
    lin[x]=len;
    e[len]=z;
}
int n,m,k;
int my(bwy x,bwy y)
{
    return x.dis>y.dis;
}
int getfather(int x)
{
    if(x==f[x])
        return x;
    return f[x]=getfather(f[x]);
}
void kruskal()
{
    for(int i=1;i<=n;i++)
        f[i]=i;
    sort(s+1,s+1+m,my);
    for(int i=1;i<=m;i++)
    {
        int xx=getfather(s[i].x);
        int yy=getfather(s[i].y);
        if(xx!=yy)
        {
            f[xx]=yy;
            add(s[i].x,s[i].y,s[i].dis);
            add(s[i].y,s[i].x,s[i].dis);
        }
    }
}
void dfs(int num)
{
    vis[num]=1;
    for(int i=lin[num];i!=0;i=nex[i])
    {
        int tn=ver[i];
        if(vis[tn]==1)
            continue;
        depth[tn]=depth[num]+1;
        fa[tn][0]=num;
        w[tn][0]=e[i];
        dfs(tn);
    }
    return;
}
int lca(int x,int y)
{
    if(getfather(x)!=getfather(y))
        return -1;
    int ans=inf;
    if(depth[x]>depth[y])
        swap(x,y);
    for(int i=20;i>=0;i--)
    {
        if(depth[fa[y][i]]>=depth[x])
        {
            ans=min(ans,w[y][i]);
            y=fa[y][i];
        }
    }
    if(x==y)return ans;
    for(int i=20;i>=0;i--)
    {
        if(fa[x][i]!=fa[y][i])
        {
            ans=min(ans,min(w[x][i],w[y][i]));
            x=fa[x][i],y=fa[y][i];
        }
    }
    ans=min(ans,min(w[x][0],w[y][0]));
    return ans;
}
int main()
{
    //freopen("1.in","r",stdin);
    n=read();m=read();
    for(int i=1;i<=m;i++)
    {    
        s[i].x=read();s[i].y=read();s[i].dis=read();
    }
    kruskal();
    for(int i=1;i<=n;i++)
    {
        if(vis[i]!=1)
        {
            depth[i]=1;
            dfs(i);
            fa[i][0]=i;
            w[i][0]=inf;
        }
    }
    for(int i=1;i<=20;i++)
        for(int j=1;j<=n;j++)
        {
            fa[j][i]=fa[fa[j][i-1]][i-1];
            w[j][i]=min(w[j][i-1],w[fa[j][i-1]][i-1]);
        }
    k=read();
    for(int i=1;i<=k;i++)
    {
        int x,y;
        x=read();y=read();
        cout<<lca(x,y)<<endl;
    }
    return 0;
}