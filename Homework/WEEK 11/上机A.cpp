#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int T, n, pre[10], in[10], cur, pos;
bool b[10], temp;
unordered_map<int, int> m;

void judge()
{
    pos = m[pre[cur]];
    b[pos] = false;
    if(b[pos-1]){
        cur++; judge();
    }
    if(b[pos+1]){
        cur++; judge();
    }
}

int main()
{
    cin >> T;
    while(T--){
        cin >> n;
        for(int i=1; i<=n; ++i){
            cin >> pre[i];
            in[i] = i;
        }
        b[0] = b[n+1] = false;
        do{
            for(int i=1; i<=n; ++i){
                m[in[i]] = i;
                b[i] = true;
            }
            cur = 1;
            judge();
            temp = true;
            for(int i=1; i<=n; ++i)
                if(b[i]==true)
                    temp = false;
            if(temp)
                break;
        }while(next_permutation(in+1, in+n+1));
        for(int i=1; i<=n; ++i){
            cout << in[i];
            if(i<n)
                cout << ' ';
        }
        cout << endl;
    }
    return 0;
}
