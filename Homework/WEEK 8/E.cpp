#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, a[3005];
vector<int> vec;

bool cmp(int& x, int& y)
{
	return x>y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> N >> M){
        for(int i=1; i<=N; ++i)
            cin >> a[i];
        for(int i=1; i<N; ++i)
            for(int j=i+1; j<=N; ++j)
                vec.push_back(a[i]+a[j]);
        sort(vec.begin(), vec.end(), cmp);
        auto it=vec.begin();
        while(M--){
            cout << *(it++);
            if(M!=0)
                cout << ' ';
        }
        cout << endl;
        vec.clear();
    }
    return 0;
}