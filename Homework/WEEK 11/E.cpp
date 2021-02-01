#include <iostream>
#include <vector>
using namespace std;
int n, q, u, k, order[200005], en[200005], cur=1;
vector<int> vec[200005], v;

void work(int u)
{
    order[u] = cur;
    v.push_back(u);
    for(int i=0; i<vec[u].size(); ++i){
        cur++;
        work(vec[u][i]);
    }
    en[u] = cur+1;
}

int main()
{
    cin >> n >> q;
    for(int i=2; i<=n; ++i){
        scanf("%d", &u);
        vec[u].push_back(i);
    }
    work(1);
    while(q--){
        scanf("%d%d", &u, &k);
        if(k <= en[u]-order[u])
            cout << v[order[u]+k-2] << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}