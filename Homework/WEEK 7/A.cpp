#include<iostream>
using namespace std;
int n, k, a[100005], L[100005], R[100005];
long long ans=0;

void merge(int l, int mid, int r)
{
    int t1=0, t2=0;
    for(int i=l; i<=mid; ++i)
        L[t1++] = a[i];
    for(int i=mid+1; i<=r; ++i)
        R[t2++] = a[i];
    int i=0, j=0, pos=l;
    while(i<t1 && j<t2)
        if(L[i] > R[j]){
            ans += (t1-i);
            a[pos++] = R[j++];
        }
        else
            a[pos++] = L[i++];
    while(i<t1)
        a[pos++] = L[i++];
    while(j<t2)
        a[pos++] = R[j++];
}

void mergesort(int l, int r)
{
	if(r<=l)
		return;
    int mid = (l+r)/2;
    mergesort(l, mid);
    mergesort(mid+1, r);
    merge(l, mid, r);
}

int main()
{
    while(scanf("%d%d", &n, &k)!=EOF){
        ans = 0;
        for(int i=0; i<n; ++i)
            scanf("%d", a+i+1);
        mergesort(1, n);
        ans = (ans>k) ? ans-k : 0;
        cout << ans << endl;
    }
    return 0;
}