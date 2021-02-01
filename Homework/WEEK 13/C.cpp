#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200005;
long long value[N];
int fa[N];

class node{
public:
    int x, y;
    long long w;
    node(){}
    node(int x, int y, long long w):x(x), y(y), w(w){}
    bool operator<(const node& a)const {return w<a.w;}
}e[N*4];

int finds(int x) { return x==fa[x] ? x : fa[x]=finds(fa[x]); }

int main()
{
    int n, m, pos;
    long long minn=1e17, ans=0;
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        scanf("%lld", &value[i]);
        if(value[i]<minn)
            minn = value[i], pos = i;
        fa[i] = i;
    }
    for(int i=1; i<=m; ++i)
        scanf("%d %d %lld", &e[i].x, &e[i].y, &e[i].w);
    for(int i=1; i<=n; ++i)
        if(i!=pos)
            e[++m] = node(i, pos, value[i]+value[pos]);
    sort(e+1, e+m+1);
    for(int i=1; i<=m; ++i){
        int x=finds(e[i].x), y=finds(e[i].y);
        if(x!=y){
            ans += e[i].w;
            fa[y] = x;
        }
    }
    printf("%lld\n", ans);
    return 0;
}