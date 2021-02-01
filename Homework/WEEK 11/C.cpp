#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>
using namespace std;
int T, n, m, pos, length[40005];
vector<pair<int, int>> vec[40005];
vector<int> ola;
unordered_map<int, int> map;

void bfs(int index, int last, int k)
{
    ola.push_back(index);
    map[index] = pos++;
    length[index] = length[last]+k;
    for(int i=0; i<vec[index].size(); ++i)
        if(vec[index][i].first!=last){
            bfs(vec[index][i].first, index, vec[index][i].second);
            ola.push_back(index);
        }
}

int main()
{
    cin >> T;
    while(T--){
        cin >> n >> m;
        memset(length, 0, sizeof(length));
        for(int i=1, u, v, k; i<n; ++i){
            scanf("%d%d%d", &u, &v, &k);
            vec[u].push_back({v, k});
            vec[v].push_back({u, k});
        }
        pos = 1;
        bfs(1, 1, 0);
        while(m--){
            int i, j, lca;
            scanf("%d%d", &i, &j);
            auto lef = find(ola.begin(), ola.end(), i);
            auto rgt = find(ola.begin(), ola.end(), j);
            if(rgt<lef)
                swap(lef, rgt);
            lca = *lef;
            while(lef<=rgt){
                if(map[*lef]<map[lca])
                    lca = *lef;
                lef++;
            }
            printf("%d\n", length[i]+length[j]-2*length[lca]);
        }
        for(int i=1; i<=n; ++i)
            vec[i].clear();
        ola.clear();
    }
    return 0;
}