#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long n, val[200005], mc=0, ans=0;
vector<int> vec[200005];

bool cmp(int& x, int& y)
{
    return val[x]>val[y];
}

void bfs(int index, int last)
{
    int s = vec[index].size();
    if(s>1){
        long long sum=0;
        for(int i=0; i<s; ++i)
            sum += val[vec[index][i]];
        sort(vec[index].begin(), vec[index].end(), cmp);
        mc = max(mc, val[vec[index][0]]*val[vec[index][1]]);
        for(int i=0; i<s; ++i)
            ans = (ans+(val[vec[index][i]]*(sum-val[vec[index][i]]))%10007)%10007;
    }
    for(int i=0; i<s; ++i)
        if(vec[index][i]!=last)
            bfs(vec[index][i], index);
}

int main()
{
    cin >> n;
    for(int i=1, u, v; i<n; ++i){
        scanf("%d%d", &u, &v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    for(int i=1; i<=n; ++i)
        scanf("%d", &val[i]);
    bfs(1, 0);
    cout << mc << ' ' << ans << endl;
    return 0;
}