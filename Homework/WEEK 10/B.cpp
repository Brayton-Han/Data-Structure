#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int T, N, M, u, v, K, ml, last;
bool visit[100005];
vector<int> vec[100005];

void bfs(int index, int len){
    visit[index] = true;
    if(len>ml) {
        ml = len;
        last = index;
    }
    for(int i=0; i<vec[index].size(); ++i)
        if(!visit[vec[index][i]])
            bfs(vec[index][i], len+1);
}

int main()
{
    cin >> T;
    while(T--){
        cin >> N >> M;
        for(int i=0; i<N-1; ++i){
            scanf("%d%d", &u, &v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        ml = 0;
        memset(visit, false, sizeof(visit));
        bfs(1, 1);
        ml = 0;
        memset(visit, false, sizeof(visit));
        bfs(last, 1);
        while(M--){
            scanf("%d", &K);
            if(K<=ml)
                cout << K-1 << endl;
            else
                cout << ml-1 + 2*(K-ml) << endl;
        }
        for(int i=1; i<=N; ++i)
            vec[i].clear();
    }
    return 0;
}
