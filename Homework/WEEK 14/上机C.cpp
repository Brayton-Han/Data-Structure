#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 1e8;
int T, n, m, floyd[105][105], ans[105];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i=1; i<=n; ++i)
        	for(int j=1; j<=n; ++j)
        		floyd[i][j] = ( i==j ? 0 : INF );
        memset(ans, 0, sizeof(ans));
        while(m--){
            int x, y, z;
            cin >> x >> y >> z;
            floyd[x][y] = min(floyd[x][y], z);
            floyd[y][x] = floyd[x][y];
        }
        for(int k=1; k<=n; ++k)
            for(int i=1; i<=n; ++i)
                for(int j=1; j<=n; ++j)
                    floyd[i][j] = min(floyd[i][j], floyd[i][k]+floyd[k][j]);
        for(int k=1; k<=n; ++k)
        	for(int i=1; i<=n; ++i)
            	for(int j=1; j<=n; ++j)
                    if(floyd[i][j] == floyd[i][k]+floyd[k][j])
                        ans[k]++;
        for(int i=1; i<=n; ++i)
            cout << ans[i] << endl;
    }
    return 0;
}
