#include <iostream>
#include <deque>
using namespace std;
int n, a[2000002];
deque<int> q;

void in(int w)
{
	while(q.size()>0 && a[q.back()]>=a[w])
		q.pop_back();
    q.push_back(w);
}

int main()
{
    while(1){
    	cin >> n;
    	if(n==0) break;
        q.push_back(0);
        for(int i=1; i<=n; ++i){
            scanf("%d", &a[i]);
            a[n+i] = a[i];
        }
        for(int i=2; i<=2*n; ++i)
            a[i] += a[i-1];
        for(int i=1; i<=n; ++i)
        	in(i);
        int ans = 0;
        for(int i=n+1; i<=2*n; ++i){
            if(q.front() < i-n)
        		q.pop_front();
            in(i);
            if(a[q.front()]>=a[i-n])
				ans++;
        }
        q.clear();
        cout << ans << endl;
    }
    return 0;
}
