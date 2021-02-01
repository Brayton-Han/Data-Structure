#include <iostream>
#include <map>
using namespace std;
int n, q, ep=0, fa[200005], f[200005], a[200005], b[200005], h[200005], d[200005], col[200005];
map<int, int> ans;

struct EDGE{
    int v,nx;
}e[400010];

void add(int u, int v)
{
    e[++ep] = {v, h[u]};
    h[u] = ep;
}

int find(int x)
{
    return x==f[x] ? x : f[x]=find(f[x]);
}

void dfs(int index, int last, int dd)
{
    d[index] = dd;
    for(int i=h[index]; i; i=e[i].nx){
        int v = e[i].v;
        if(v!=last)
            dfs(v, index, dd+1);
    }
}

void work(int u, int v, int c){
    while(u!=v)
        if(d[u]>=d[v]){
            if(col[u]==0)
                col[u] = c;
            f[find(u)] = find(fa[u]);
            u = find(fa[u]);
        }else{
            if(col[v]==0)
                col[v] = c;
            f[find(v)] = find(fa[v]);
            v = find(fa[v]);
        }
}

int main(){
    cin >> n >> q;
    f[1] = 1;
    for(int i=2; i<=n; ++i){
        f[i] = i;
        scanf("%d", &fa[i]);
        add(fa[i], i);
        add(i, fa[i]);
    }
    dfs(1, 0, 1);
    for(int i=1; i<=q; ++i)
        scanf("%d %d", &a[i], &b[i]);
    for(int i=q; i; --i)
        work(a[i], b[i], i);
    for(int i=1; i<=n; ++i)
        ans[col[i]]++;
    for(int i=1; i<=q; ++i)
        printf("%d ", ans[i]);
    cout << endl;
    return 0;
}