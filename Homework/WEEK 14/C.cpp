#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int n, cnt=0, m=0, fa[2005];
long long ans, c[2005], k[2005];
vector<int> point;
pair<int, int> pos[2005];
vector<pair<int, int>> edge;

struct node{
	int u, v; 
    long long w;
	bool operator<(const node& n) const { return w < n.w; }
}e[4000005];

int find(int x) { return x==fa[x] ? x : fa[x]=find(fa[x]); }
 
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=1; i<=n; ++i){
        cin >> pos[i].first >> pos[i].second;
		fa[i] = i;
	}
	for(int i=1; i<=n; ++i){
        cin >> c[i];
		e[++cnt] = {0, i, c[i]};
	}
	for(int i=1; i<=n; ++i) 
        cin >> k[i];
	for(int i=1; i<n; ++i)
		for(int j=i+1; j<=n; ++j)
			e[++cnt] = {i, j, (abs(pos[i].first-pos[j].first)+abs(pos[i].second-pos[j].second))*(k[i] + k[j])};
	sort(e+1, e+cnt+1);
	for(int i=1; i<=cnt; ++i){
        if(m==n) 
            break;
		int x = find(e[i].u), y = find(e[i].v);
		if(x!=y){
        	fa[x] = y;
			ans += e[i].w;
			m++;
			if(e[i].u==0) 
                point.push_back(e[i].v);
			else if(e[i].v==0) 
                point.push_back(e[i].u);
			else 
                edge.push_back({e[i].u, e[i].v});
		}
	}
	cout << ans << endl;
    cout << point.size() << endl; 
	for(int i=0; i<point.size(); i++){
        cout << point[i] << ' '; 
        if(i==point.size()-1)
            cout << endl;
    }
	cout << edge.size() << endl;
	for(int i=0; i<edge.size(); i++) 
        cout << edge[i].first << ' ' << edge[i].second << endl;
	return 0;
} 