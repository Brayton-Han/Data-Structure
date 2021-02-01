#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
int T, N, X, Y;
pair<int, int> p[200005];

int main()
{
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        int ans=0, sum=0, i=0;
        while(N--){
            scanf("%d", &X);
            scanf("%d", &Y);
            p[i++]={X, 1};
            p[i++]={Y+1, -1};
        }
        sort(p, p+i);
        for(int j=0; j<i-1; ++j){
            sum += p[j].second;
            ans = max(ans, sum);
        }
        printf("%d\n", ans);
    }
    return 0;
}
