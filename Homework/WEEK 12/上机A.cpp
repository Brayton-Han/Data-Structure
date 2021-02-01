#include <iostream>
#include <cstring>
using namespace std;
int T, fa[100005], n, p;
bool zs[100005];

int find(int x) {return x==fa[x] ? x : fa[x]=find(fa[x]) ;}

int main()
{
    cin >> T;
    while(T--){
        cin >> n >> p;
	    int ans = n;
        memset(zs, true, sizeof(zs));
	    for(int i=1; i<=n; ++i)
		    fa[i]=i;
	    for(int i=2; i<=n; ++i)
		    if(zs[i] && i>=p)
				for(int j=2; i*j<=n; ++j){
					zs[i*j] = false;
					if(find(i*j)!=find(i*j-i)){
						fa[find(i*j)] = find(i*j-i);
						--ans;
					}
				}
	    cout << ans << endl;
    }
	return 0;
} 