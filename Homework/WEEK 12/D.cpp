#include <iostream>
#include <set>
using namespace std;
int T, N, M, A, B, Fa[1005];

int find(int x){
    if(Fa[x] == x) 
        return x;         
    return Fa[x]=find(Fa[x]);
}

void Query(int u, int v){
    u = find(u);
    v = find(v);
    if(u!=v)    
        Fa[u] = v;                                      
}

int main()
{
    cin >> T;
    while(T--){
        set<int> s;
        scanf("%d %d", &N, &M);
        for(int i=1; i<=N; ++i)
            Fa[i] = i;
        while(M--){
            scanf("%d %d", &A, &B);
            Query(A, B);
        }
        for(int i=1; i<=N; ++i)
            Fa[i] = find(i);
        for(int i=1; i<=N; ++i)
            s.insert(Fa[i]);
        cout << s.size() << endl;
    }
    return 0;
}