#include <iostream>
#include <vector>
#include <limits.h>
#include <utility>
using namespace std;
long long ans=0;
int n, money[2005], k[2005], f[2005][2005];
pair<int, int> p[2005];
vector<int> point, rest;
vector<pair<int, int>> edge;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; ++i)
        cin >> p[i].first >> p[i].second;
    for(int i=1; i<=n; ++i)
        cin >> money[i];
    for(int i=1; i<=n; ++i)
        cin >> k[i];
    for(int i=1; i<=n; ++i)
        for(int j=i; j<=n; ++j)
            f[j][i] = f[i][j] = (k[i]+k[j])*(abs(p[i].first-p[j].first)+abs(p[i].second-p[j].second));
    for(int i=1, j; i<=n; ++i){
        for(j=1; j<=n; ++j)
            if(i!=j && money[i]>f[i][j]){
                rest.push_back(i);
                break;
            }
        if(j==n+1){
            ans += money[i];
            point.push_back(i);
        }
    }
    auto it = rest.begin();
    while(it!=rest.end()){
        auto iter = point.begin();
        int temp = INT_MAX, a;
        while(iter!=point.end()){
            if(f[*it][*iter]<temp)
                a = *iter, temp = f[*it][*iter];
            iter++;
        }
        edge.push_back({*it, a});
        ans += temp;
        it++;
    }
    cout << ans << endl;
    cout << point.size() << endl;
    for(int i=0; i<point.size(); ++i){
        cout << point[i] << ' ';
        if(i==point.size()-1) 
            cout << endl;
    }
    cout << edge.size() << endl;
    for(int i=0; i<edge.size(); ++i)
        cout << edge[i].first << ' ' << edge[i].second << endl;
    return 0;
}
