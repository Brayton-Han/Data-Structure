#include <iostream>
#include <cstring>
using namespace std;
const int radix = 256;
const int bytes = 4;
const int MAXN = 1000;
int a[MAXN], aux[MAXN], bucket[radix], n;

template <typename item>
int getDigit(item a, int b)
{
    a >>= 8*(bytes-b-1);
    return a%radix;
}

void radixsort()
{
    for(int i=bytes-1; i>=0; --i){
    	memset(bucket, 0, sizeof(bucket));
        for(int j=0; j<n; ++j)
            bucket[getDigit(a[j], i)]++;
        for(int j=1; j<radix; ++j)
            bucket[j] += bucket[j-1];
        for(int j=n-1; j>=0; --j)
            aux[--bucket[getDigit(a[j], i)]] = a[j];
        for(int j=0; j<n; ++j)
            a[j] = aux[j];
    }
}

int main()
{
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> a[i];
    radixsort();
    for(int i=0; i<n; ++i)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}
