#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
char c;
long long ans;
set<int> x, y;
int w, h, n, m;
multiset<int> mx, my;
set<int>::iterator pre, nxt;
multiset<int>::iterator it, iter;
int main()
{
    cin >> w >> h >> n;
    x.insert(0); x.insert(w);
    y.insert(0); y.insert(h);
    mx.insert(w); my.insert(h);
    while(n--){
        cin >> c;
        scanf("%d", &m);
        switch(c){
            case 'H':
                y.insert(m);
                pre = nxt = y.find(m);
                pre--; nxt++;
                it = my.find(*nxt-*pre);
                my.erase(it);
                my.insert(*nxt-m);
                my.insert(m-*pre);
                break;
            case 'V':
                x.insert(m);
                pre = nxt = x.find(m);
                pre--; nxt++;
                iter = mx.find(*nxt-*pre);
                mx.erase(iter);
                mx.insert(*nxt-m);
                mx.insert(m-*pre);
                break;
        }
        it = mx.end(); it--;
        iter = my.end(); iter--;
        ans = (long long)(*it)*(*iter);
        printf("%lld\n", ans);
    }
    return 0;
}