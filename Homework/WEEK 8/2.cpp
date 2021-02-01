#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n, a[100005], b[100005], L[100005], R[100005], temp;
long long ans=0;

void merge(int l, int m, int r)
{
    int t1=0, t2=0;
    for(int i=l; i<=m; ++i)
        L[t1++] = b[i];
    for(int i=m+1; i<=r; ++i)
        R[t2++] = b[i];
    int i=0, j=0;
    while(i<t1 && j<t2)
        if(a[L[i]]>a[R[j]]){
            ans = (ans+t1-i)%99999997;
            b[l++] = R[j++];
        }
        else
            b[l++] = L[i++];
    while(i<t1)
        b[l++] = L[i++];
    while(j<t2)
        b[l++] = R[j++];
}

void di(int lef, int rgt)
{
    if(rgt<=lef)
        return;
    int mid = (lef+rgt)/2;
    di(lef, mid);
    di(mid+1, rgt);
    merge(lef, mid, rgt);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> temp;
        a[temp] = i;
    }
    for(int i=1; i<=n; ++i)
        cin >> b[i];
    di(1, n);
    cout << ans%99999997 << endl;
    return 0;
}
