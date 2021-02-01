#include <iostream>
using namespace std;
int T, n, B, i;

int main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--){
        cin >> n >> B;
        B %= 9973;
        for(i=0; i<9973; ++i)
        	if((B*i-n)%9973==0)
        		break;
        cout << i << endl;
    }
    return 0;
}
