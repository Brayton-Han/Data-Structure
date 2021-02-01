#include <iostream>
#include <vector>
#include <map>
using namespace std;
int N, Q, dp[200005][20], depth[200005], color[200005];
vector<int> vec[200005];
map<int, int> m;

void bfs(int index, int last, int d)
{
    dp[index][0] = last;
    depth[index] = d;
    for(int i=1; (1<<i) <= depth[index]; i++)
    	dp[index][i] = dp[dp[index][i-1]][i-1];
    for(int i=0; i<vec[index].size(); ++i)
        if(vec[index][i]!=last)
            bfs(vec[index][i], index, d+1);
}

void LCA(int a, int b, int d)
{
	if(depth[a]<depth[b])
		swap(a, b);
	for(int i=19; i>=0; --i)
		if(depth[a]-(1<<i)>=depth[b]){
            color[a] = b;
            a = dp[a][i];
        }
	if(a!=b)
	    for(int i=19; i>=0; --i)
		    if(dp[a][i]!=dp[b][i]){
                color[a] = color[b] = d;
			    a = dp[a][i];
			    b = dp[b][i];
		    }
}

int main()
{
    cin >> N >> Q;
    for(int i=2, u; i<N; ++i){
        scanf("%d", &u);
        vec[u].push_back(i);
        vec[i].push_back(u);
    }
    bfs(1, 0, 0);
    for(int i=1, u, v; i<=Q; ++i){
        scanf("%d %d", &u, &v);
        LCA(u, v, i);
    }
    for(int i=2; i<=N; ++i)
        if(color[i]>0)
            m[color[i]]++;
    for(int i=1; i<=Q; ++i)
        printf("%d ", m[i]);
    cout << endl;
    return 0;
}