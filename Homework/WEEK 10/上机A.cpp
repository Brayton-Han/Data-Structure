#include<iostream>
#include<utility>
#include<cstring>
#include<algorithm>
using namespace std;
int T, n, a[10005], i, ans;
pair<int, int> p[10005];
bool b[10005];

void work(int r, int mi, int ma, int num)
{
    if(r==mi && r==ma && p[r].first<r && r<p[r].second){
        ans = max(ans, num+2);
        work(p[r].first, p[r].first, r, num+2);
        work(p[r].second, r, p[r].second, num+2);
    }else if(p[r].first!=0 && p[r].second!=0)
      	if(p[r].first<r && p[r].second<ma){
          	ans = max(ans, num+2);
          	work(p[r].first, r, ma, num+2);
          	work(p[r].second, r, ma, num+2);
        }else if(p[r].first>mi && p[r].second>r){
          	ans = max(ans, num+2);
          	work(p[r].first, mi, r, num+2);
          	work(p[r].second, mi, r, num+2);
        }
    else if(p[r].first==0 && p[r].second!=0)
      	if(p[r].second<ma){
          	ans = max(ans, num+1);
          	work(p[r].second, r, ma, num+1);
        }else if(p[r].second>r){
          	ans = max(ans, num+1);
          	work(p[r].second, mi, r, num+1);
        }
    else if(p[r].first!=0 && p[r].second==0)
      	if(p[r].first<r){
          	ans = max(ans, num+1);
          	work(p[r].first, r, ma, num+1);
        }else if(p[r].first>mi){
          	ans = max(ans, num+1);
          	work(p[r].first, mi, r, num+1);
        }
  	else if(p[r].first==0 && p[r].second==0);
    else{
        work(p[r].first, p[r].first, p[r].first, 1);
        work(p[r].second, p[r].second, p[r].second, 1);
    }
}

int main()
{
    cin >> T;
    while(T--){
        cin >> n;
        ans = 1;
        memset(b, false, sizeof(b));
        for(i=0; i<n; ++i){
            int x, l, r;
            scanf("%d%d%d", &x, &l, &r);
            p[x].first = l;
            p[x].second = r;
            b[l] = b[r] = true;
        }
        for(i=1; i<=n; ++i)
            if(!b[i])
                break;
        work(i, i, i, 1);
        cout << ans << endl;
    }
    return 0;
}