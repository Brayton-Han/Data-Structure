#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <deque>
using namespace std;
const int N = 200005;
vector<int> vec[N];
list<int> L;
vector<int> ans;
map<int, bool> vis;

void work()
{
    int cnt=1;
    deque<int> d;
    d.push_back(*(L.begin())); 
    L.erase(L.begin());
    while(!d.empty()){
        for(int i=0; i<vec[d.front()].size(); i++)
            vis[vec[d.front()][i]] = true;
        auto it = L.begin();
        while(it!=L.end())
            if(!vis[(*it)]){
                cnt++;
                d.push_back((*it));
                it = L.erase(it);
            }else it++;
        d.pop_front();
        vis.clear();
    }
    ans.push_back(cnt);
}

int main(){
    int n, m, x, y;
    scanf("%d %d", &n, &m);
    while(m--){
        scanf("%d %d", &x, &y);
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    for(int i=1; i<=n; i++) 
        L.push_back(i);
    while(!L.empty())
        work();
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for(int i=0; i<ans.size(); i++){
        printf("%d", ans[i]);
        if(i!=ans.size()-1)
            printf(" ");
    }
    cout << endl;
    return 0;
}