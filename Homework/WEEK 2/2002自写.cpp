#include <bits/stdc++.h>
using namespace std;
int T, n, a[1005];

int main()
{
  cin >> T;
  while(T--){
    cin >> n;
    for(int i=1; i<=n; ++i)
      cin >> a[i];
    int ans = a[1], temp = a[1];
    for(int i=2; i<=n; ++i){
      temp = max(a[i]+temp, a[i]);
      ans = max(ans, temp);
    }
    cout << ans << endl;
  }
  return 0;
}