#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
int n, k, length[100005], dp[100005][20], depth[100005];
vector<int> vec[100005];
pair<int, int> p[100005];

void bfs(int index, int last, int d)
{
    dp[index][0]= last;
    depth[index] = d;
    for(int i=1; (1<<i) <= depth[index]; i++)
    	dp[index][i] = dp[dp[index][i-1]][i-1];
    for(int i=0; i<vec[index].size(); ++i)
        if(vec[index][i]!=last)
            bfs(vec[index][i], index, d+1);
}

int work(int index, int last)
{
    for(int i=0; i<vec[index].size(); ++i)
        if(vec[index][i]!=last)
            length[index] += work(vec[index][i], index);
    return length[index];
}

int LCA(int a, int b)
{
	if(depth[a]<depth[b])
		swap(a,b);
	for(int i=19; i>=0; i--)
		if(depth[a]-(1<<i)>=depth[b])
			a = dp[a][i];
	if(a==b)
		return a;
	for(int i=19; i>=0; i--)
		if(dp[a][i]!=dp[b][i]){
			a=dp[a][i];
			b=dp[b][i];
		}
	return dp[a][0];
}

int main()
{
    cin >> n;
    for(int i=1, u, v; i<n; ++i){
        scanf("%d%d", &u, &v);
        vec[u].push_back(v);
        vec[v].push_back(u);
        p[i] = {u, v};
    }
    bfs(1, 1, 0);
    memset(length, 0, sizeof(length));
    cin >> k;
    int u, v, lca;
    while(k--){
        scanf("%d%d", &u, &v);
        length[u]++; 
        length[v]++;
        lca = LCA(u, v);
        length[lca] -= 2;
    }
    work(1, 0);
    for(int i=1, temp; i<n; ++i){
        if(depth[p[i].first]<depth[p[i].second])
            temp = p[i].second;
        else
            temp = p[i].first;
        printf("%d ", length[temp]);
    }
    cout << endl;
    return 0;
}