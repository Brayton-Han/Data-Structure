#include <iostream>
#include <algorithm>
using namespace std;
int n, m, fa[205], st[205], top=0, cnt;
long long g, s, ans = 0x7fffffffffffffff;

struct edge{
    int x, y;
    long long g, s;
}e[50005];

bool cmp(edge& a, edge& b) { return a.g==b.g ? a.s < b.s : a.g < b.g; }
int find(int x) {return x==fa[x] ? x : fa[x]=find(fa[x]); }
 
int main() 
{
    cin >> n >> m >> g >> s;
    for(int i=1; i<=m; ++i)
	    scanf("%d %d %lld %lld", &e[i].x, &e[i].y, &e[i].g, &e[i].s);
    sort(e+1, e+m+1, cmp); 
    for(int i=1; i<=m; ++i) {
	    for(int j=1; j<=n; ++j) 
            fa[j] = j;
	    st[++top] = i, cnt = 0;
        for(int j=top; j>=2; --j)
	        if(e[st[j]].s<e[st[j-1]].s)
		        swap(st[j], st[j-1]);
	    for(int j=1; j<=top; ++j) {
	        int x = find(e[st[j]].x), y = find(e[st[j]].y);
	        if(x==y)  continue;
	        fa[y] = x;
	        st[++cnt] = st[j];//舍弃不会用到的边 
	        if(cnt==n-1)    break;
	    }
	    if(cnt==n-1) 
            ans = min(ans, e[i].g*g + e[st[cnt]].s*s);
	    top = cnt;
    }
    if(ans==0x7fffffffffffffff) 
        cout << -1 << endl;
    else 
        cout << ans << endl;
    return 0;
}