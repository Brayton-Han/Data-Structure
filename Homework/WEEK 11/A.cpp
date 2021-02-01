#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n, ans=1, color[10005];
vector<int> vec[10005];

void work(int index, int pre, int last){
    for(int i=0, temp; i<vec[index].size(); ++i){
        temp = vec[index][i];
        if(temp!=last){
            if(pre!=color[temp])
                ans++;
            work(vec[index][i], color[temp], index);
        }
    }
}

int main()
{
    cin >> n;
    for(int i=2, u; i<=n; ++i){
        cin >> u;
        vec[i].push_back(u);
        vec[u].push_back(i);
    }
    for(int i=1; i<=n; ++i)
        cin >> color[i];
    work(1, color[1], 1);
    cout << ans << endl; 
    return 0;
}