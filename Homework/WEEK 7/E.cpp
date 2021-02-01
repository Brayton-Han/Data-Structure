#include <iostream>
using namespace std;
int n, k, a[200005], m=0;

void work(int l, int r)
{
    if(l+1==r || m==k)
		return;
    int mid = l+r>>1;
	m+=2;
	a[mid] += a[mid-1];
	a[mid-1] = a[mid]-a[mid-1];
	a[mid] -= a[mid-1];
    work(l, mid);
    work(mid, r);
}

int main()
{
    cin >> n >> k;
	k--;
    if(k&1){
		cout << -1 << endl;
		return 0;
	}
    for(int i=0; i<n; ++i)
		a[i] = i+1;
	work(0, n);
    if(m<k){
		cout << -1 << endl;
		return 0;
	}
    for(int i=0; i<n; ++i)
		printf("%d ", a[i]);
	return 0;
}