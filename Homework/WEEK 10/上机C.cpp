#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int N, cur, ml, an[100005], p1;
vector<int> vec[100005];

void bfs(int index, int len, int last)
{
    if(len>ml){
        ml = len;
        cur = index;
    }
    for(int i=0; i<vec[index].size(); ++i)
        if(vec[index][i]!=last)
            bfs(vec[index][i], len+1, index);
}

void work1(int index, int len, int last)
{
    an[index] = len;
    for(int i=0; i<vec[index].size(); ++i)
        if(vec[index][i]!=last)
            work1(vec[index][i], len+1, index);
}

void work2(int index, int len, int last)
{
    an[index] = max(an[index], len);
    for(int i=0; i<vec[index].size(); ++i)
        if(vec[index][i]!=last)
            work2(vec[index][i], len+1, index);
}

int main()
{
    cin >> N;
    for(int i=1; i<N; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    memset(an, 0, sizeof(an));
    ml = 0;
    bfs(1, 0, 1);
    p1 = cur;
    ml = 0;
    bfs(cur, 0, cur);
    work1(cur, 0, cur);
    work2(p1, 0, p1);
    for(int i=1; i<=N; ++i)
        cout << an[i] << endl;
    return 0;
}
