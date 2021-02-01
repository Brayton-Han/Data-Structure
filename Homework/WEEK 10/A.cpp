#include <iostream>
#include <cstring>
#include <utility>
using namespace std;
int n, c[100005], d[100005], cnt=0;
pair<int, int> p[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(d, 0, sizeof(d));
    cin >> n;
    for(int i=1; i<n; ++i)
        cin >> p[i].first >> p[i].second;
    for(int i=1; i<=n; ++i)
        cin >> c[i];
    for(int i=1; i<n; ++i)
        if(c[p[i].first]!=c[p[i].second]){
            d[p[i].first]++;
            d[p[i].second]++;
            cnt++;
        }
    for(int i=1; i<=n; ++i)
        if(d[i]==cnt){
            cout << "YES" << endl;
            cout << i << endl;
            return 0;
        }
    cout << "NO" << endl;
    return 0;
}
