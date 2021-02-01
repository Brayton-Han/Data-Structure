#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> v;
string s;
int T, n;

bool cmp(string& a, string& b)
{
    return a+b > b+a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        while(n--){
            cin >> s;
            v.push_back(s);
        }
        sort(v.begin(), v.end(), cmp);
        auto it=v.begin();
        while(it!=v.end())
            cout << *(it++);
        cout << endl;
        v.clear();
    }
    return 0;
}