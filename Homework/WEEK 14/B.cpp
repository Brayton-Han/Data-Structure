#include <iostream>
#include <vector>
using namespace std;
int n, k, temp, v, flag[100005];
vector<int> ans, need, vec[100005];

void tp(int u){
    if(flag[u]==2)
        return;
    flag[u] = 1;
    for(auto v : vec[u]){
        if(flag[v]==1)
            cout << -1 << endl, exit(0);
        tp(v);
    }
    flag[u] = 2;
    ans.push_back(u);
}

int main() 
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    while(k--){
        cin >> temp;
        need.push_back(temp);
    }
    for(int i=1; i<=n; ++i){
        cin >> temp;
        while(temp--){
            cin >> v;
            vec[i].push_back(v);
        }
    }
    for(auto x : need)
        tp(x);
    cout << ans.size() << endl;
    for(auto x : ans) 
        cout << x << " ";
    cout << endl;
    return 0;
}
