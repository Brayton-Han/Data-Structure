#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
int T, n, m, map[1005][1005], dis[1005];
bool vis[1005];
 
void Dijkstra()
{
	memset(vis, false, sizeof(vis));
	for(int i=1; i<=n; ++i)
		dis[i] = map[1][i];
	vis[1] = true;
	for(int i=1; i<n; ++i){
		int minn = inf, temp;
		for(int j=1; j<=n; ++j)
			if(!vis[j] && dis[j]<minn){
				minn = dis[j];
				temp = j;
			}
		vis[temp] = true;
		for(int j=1; j<=n; ++j)
            dis[j] = min(dis[j], map[temp][j]+dis[temp]);
    }
}
 
int main()
{
    cin >> T;
    while(T--){
	    cin >> m >> n;
	    memset(map, inf, sizeof(map));
	    for(int i=1; i<=n; ++i)
		    map[i][i] = 0;
	    for(int i=1, u, v, w; i<=m; ++i){
	  	    scanf("%d %d %d", &u, &v, &w);
	  	    if(map[u][v]>w){
		        map[u][v] = w;
		        map[v][u] = w;
	        }
	    }
	    Dijkstra();
	    printf("%d\n", dis[n]);
    }
	return 0;
}