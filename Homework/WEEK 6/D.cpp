#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int n, temp, time=0, ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    auto it = v.begin();
    while(it != v.end()){
        if(time<=*it){
            time += *it;
            ans++;
        }
        it++;
    }
    cout << ans << endl;
    return 0;
}