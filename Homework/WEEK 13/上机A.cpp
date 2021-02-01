#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int n, m, q, x, y;
map<int, int> vec[10005];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1, x, y, z; i<=m; ++i) {
        cin >> x >> y >> z;
        vec[x][y] = z;
        vec[y][x] = z;
    }
    for(int k=1; k<=n; ++k)
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j)
                if(vec[i][k])
                    vec[i][j] = max(vec[i][j], min(vec[i][k], vec[k][j]));
    cin >> q;
    while(q--){
        cin >> x >> y;
        if(vec[x][y]==0)
            cout << -1 << endl;
        else
            cout << vec[x][y] << endl;
    }
    return 0;
}