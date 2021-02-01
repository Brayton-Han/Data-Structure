#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
int N, M;
priority_queue<int> q;
ll ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    while(N--){
        cin >> ans;
        q.push(ans);
    }
    while(M){
        ans = q.top();
        q.pop();
        ans /= 2;
        M--;
        q.push(ans);
    }
    ans=0;
    while(q.size()){
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
    return 0;
}