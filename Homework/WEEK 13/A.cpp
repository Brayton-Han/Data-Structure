#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int inf=0x3f3f3f3f;
int m, n, a, b, floyd[105][105];

int main()
{
    while(~scanf("%d", &m), m){
        memset(floyd, inf, sizeof(floyd));
        for(int i=1; i<=m; ++i)
            floyd[i][i] = 0;
        for(int i=1; i<=m; ++i){
            scanf("%d", &n);
            while(n--){
                scanf("%d%d", &a, &b);
                floyd[i][a]=b;
            }
        }
        for(int k=1; k<=m; ++k)
            for(int i=1; i<=m; ++i)
                for(int j=1; j<=m; ++j)
                    floyd[i][j] = min(floyd[i][j], floyd[i][k]+floyd[k][j]);
        int ma = inf, p = 0;
        for(int i=1; i<=m; ++i){
            int temp = 0;
            for(int j=1; j<=m; ++j){
                if(i==j) 
                    continue;
                temp = max(temp, floyd[i][j]);
            }
            if(temp<ma)
                ma = temp, p = i;
        }
        if(ma==inf)
            printf("disjoint\n");
        else
            printf("%d %d\n", p, ma);
    }
    return 0;
}