#include <iostream>
#include <cstring>
#include <deque>
using namespace std;
int n, q, x, y, ans=0, m=0;
deque<int> a;
int b[300002], c[300002], d[300002]; //d记录每种信息被删除的个数
int main()
{
	ios::sync_with_stdio(false);
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	memset(d, 0, sizeof(d));
    cin >> n >> q;
    while(q--){
        cin >> x >> y;
        switch(x){
        	case 1: a.push_back(y);
            	    b[y]++;
            		ans++;
					break;
			case 2: ans-=(b[y]-c[y]);
            		c[y]=b[y];
            		break;
            case 3: while(m<y){
                		d[a[m]]++;
                		if(d[a[m]]>c[a[m]]){
                    		c[a[m]]++;
                    		ans--;
                		}
                		m++;
        			}
        			break;
    	}
    	cout << ans << endl;
	}
    return 0;
}
