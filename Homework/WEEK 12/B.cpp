#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int P, sn, M, a[10005];
vector<int> vec[1005];
int main()
{
    cin >> P;
    for(int i=1; i<=P; ++i){
        scanf("%d%d", &sn, &M);
        for(int j=0, temp; j<M; ++j)
            scanf("%d", &a[j]);
        for(int j=1; j<=M; ++j)
            if(j%2){
                sort(a, a+j);
                vec[i].push_back(a[j/2]);
            }
    }
    for(int i=1, si, cnt=10; i<=P; ++i){
        si=vec[i].size();
        printf("%d %d\n", i, si);
        for(int j=0, cnt=0; j<si; ++j)
            if(cnt<10){
                printf("%d ", vec[i][j]);
                cnt++;
            }else{
                cnt -= 10;
                cout <<endl;
                printf("%d ", vec[i][j]);
                cnt++;
            }
        cout << endl;
    }
    return 0;
}