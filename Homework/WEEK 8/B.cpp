#include <iostream>
#include <math.h>
using namespace std;
int n, i, temp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    i = sqrt(n);
    while(n>0){
        for(temp = n-i+1; temp<=n; ++temp)
            if(temp>0)
                cout << temp << ' ';
        n -= i;
    }
    cout << endl;
    return 0;
}