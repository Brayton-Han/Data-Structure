#include <iostream>
#include <vector>
using namespace std;
const int maxn = 2e5+10;
int n, c[maxn];
vector<int> son[maxn];

pair<int,int> dfs(int u, int fa, int cnt)
{
    pair<int,int> tmp = make_pair(cnt, u);
    for(int i=0; i<son[u].size(); ++i){
        int v = son[u][i];
        if(v==fa) 
            tmp = max(tmp, dfs(v,u,cnt+(c[u]!=c[v])));
    }
    return tmp;
}

int main()
{
    cin >> n;
    for(int i=1; i<=n; ++i)
        scanf("%d", &c[i]);
    for(int i=1; i<n; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        son[u].push_back(v);
        son[v].push_back(u);
    }
    pair<int,int> tmp;
    tmp = dfs(1, -1, 1);
    tmp = dfs(tmp.second, -1, 1);
    cout << tmp.first/2 << endl;
    return 0;
}