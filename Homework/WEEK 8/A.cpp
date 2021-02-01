#include <iostream>
using namespace std;
int n, a[1000005], L[500005], R[500005];
long long ans=0;

void merge(int l, int m, int r)
{
    int t1=0, t2=0;
    for(int i=l; i<=m; ++i)
        L[t1++] = a[i];
    for(int i=m+1; i<=r; ++i)
        R[t2++] = a[i];
    int i=0, j=0;
    while(i<t1 && j<t2)
        if(L[i]>R[j]){
            ans += (t1-i);
            a[l++] = R[j++];
        }
        else
            a[l++] = L[i++];
    while(i<t1)
        a[l++] = L[i++];
    while(j<t2)
        a[l++] = R[j++];
}

void mergesort(int lef, int rgt)
{
    if(rgt <= lef)
        return;
    int mid = (lef+rgt)/2;
    mergesort(lef, mid);
    mergesort(mid+1, rgt);
    merge(lef, mid, rgt);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; ++i)
        cin >> a[i];
    mergesort(1, n);
    long long tri = (n<<2)-n;
    if((tri-ans)&1)
        cout << "Um_nik" << endl;
    else
    	cout << "Petr" << endl;
    return 0;
}