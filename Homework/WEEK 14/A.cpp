#include <iostream>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;
int n, m, p[1005];
long long ans=0;
set<int> s[1005];
unordered_map<int, int> map;

bool cmp(const int& x, const int& y) { return map[x]>map[y]; }

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        cin >> map[i];
        p[i] = i;
    }
    sort(p+1, p+n+1, cmp);
    for(int i=0, x, y; i<m; ++i){
        cin >> x >> y;
        s[x].insert(y);
        s[y].insert(x);
    }
    for(int i=1; i<=n; ++i){
        auto it = s[p[i]].begin();
        while(it!=s[p[i]].end()){
            ans += map[*it];
            s[*it].erase(p[i]);
            it++;
        }
    }
    cout << ans << endl;
    return 0;
}