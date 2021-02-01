#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;
typedef long double ld;
const ld PI = acos(-1.0);
int n, ans1, ans2;
ld a, b, co;
vector<pair<ld, int>> vec;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> a >> b;
        vec.push_back({atan2(b, a), i+1});
    }
    sort(vec.begin(), vec.end());
    co = 10;
    for(int i=1; i<n; ++i)
        if(vec[i].first-vec[i-1].first < co){
            co = vec[i].first-vec[i-1].first;
            ans1 = vec[i-1].second;
            ans2 = vec[i].second;
        }
    if(2*PI+vec[0].first-vec[n-1].first < co){
        ans1 = vec[0].second;
        ans2 = vec[n-1].second;
    }
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}