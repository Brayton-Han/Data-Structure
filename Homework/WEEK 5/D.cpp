#include <iostream>
#include <cstring>
#include <deque>
using namespace std;
int n, q, x, y, ans=0, i=0, j=0;
deque<int> d[300002];
int temp[300002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(temp, 0, sizeof(temp));
    cin >> n >> q;
    while(q--){
        cin >> x >> y;
        switch(x){
            case 1: ans++;
            		temp[j]=y;
                    d[y].push_back(j++);
                    break;
            case 2: ans -= d[y].size();
                    d[y].clear();
                    break;
            case 3: while(i<y){
			        	if(d[temp[i]].size()!=0)
			        		if(d[temp[i]].front()<=i){
			        			ans--;
                        		d[temp[i]].pop_front();
							}
						++i;
                    }
        }
        cout << ans << endl;
    }
    return 0;
}
