#include <iostream>
#include <algorithm>
using namespace std;
int n, m, now=1;
int fa[200005];
long long sum[200005], ans[200005], tmp=0;

struct A{
	int v, label;
}query[200005];

struct B{
	int u, v, w;
}path[200005];

bool cmp(A& i, A& j) { return i.v < j.v; }
bool cmp1(B& i, B& j) { return i.w < j.w; }

int find(int x)
{
	if(fa[x]==x)
		return x;
	else
		return fa[x]=find(fa[x]);
}

void work(int x, int y){
	x = find(x);
	y = find(y);
	if(x!=y){
		tmp -= sum[x]*(sum[x]-1)/2;
		tmp -= sum[y]*(sum[y]-1)/2;
		fa[x] = y;
		sum[y] += sum[x];
		tmp += sum[y]*(sum[y]-1)/2;
	}
}

int main()
{
	scanf("%d%d", &n, &m);
    for(int i=0; i<=n; i++){
		fa[i] = i;
		sum[i] = 1;
	}
	for(int i=1; i<n; ++i)
		scanf("%d%d%d", &path[i].u, &path[i].v, &path[i].w);
	for(int i=1; i<=m; ++i){
		query[i].label = i;
		scanf("%d", &query[i].v);
	}
	sort(query+1, query+m+1, cmp);
	sort(path+1, path+n, cmp1);
	for(int i=1; i<=m; ++i){
		while(path[now].w<=query[i].v && now<n){
            work(path[now].u, path[now].v);
			now++;
		}
		ans[query[i].label] = tmp;
	}
	for(int i=1; i<=m; ++i)
		printf("%lld ", ans[i]);
	return 0;
}