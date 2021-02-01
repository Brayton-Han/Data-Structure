#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, q, x, y, cnt=0, fa[10005], length[10005], ans;
vector<int> vec[10005];

struct node{
    int x, y, w;
    bool operator<(const node& n) const { return w>n.w; }
}edge[50005];

int find(int x) { return x==fa[x] ? x : find(fa[x]); }

void work(int index, int aim, int last, int len)
{
    len = min(len, length[index]);
    for(int i=0; i<vec[index].size(); ++i)
        if(vec[index][i]!=last){
            if(vec[index][i]==aim){
                ans = max(ans, len);
                return;
            }
            work(vec[index][i], aim, index, len);
        }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; ++i)
        fa[i] = i;
    for(int i=1; i<=m; ++i)
        cin >> edge[i].x >> edge[i].y >> edge[i].w;
    sort(edge+1, edge+m+1);
    for(int i=1; i<=m; ++i){
        int x = find(edge[i].x), y = find(edge[i].y);
        if(x==y) continue;
        cnt++;
        fa[x] = y;
        length[x] = edge[i].w;
        vec[y].push_back(x);
        vec[x].push_back(y);
        if(cnt==n-1) break;
    }
    cin >> q;
    while(q--){
        cin >> x >> y;
        if(find(x)!=find(y))
            cout << -1 << endl;
        else{
            ans = 0;
            work(x, y, x, 100005);
            cout << ans << endl;
        }
    }
    return 0;
}