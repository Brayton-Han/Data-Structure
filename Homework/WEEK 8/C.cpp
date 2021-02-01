#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int num, temp=0;
string s;
vector<int> vec;

void split()
{
    int i=0;
    num = s.size();
    while(i<num)
        if(s[i]=='5')
            i++;
        else{
            while(s[i]!='5' && i<num)
                temp = 10*temp + int(s[i++]-'0'); 
            vec.push_back(temp);
            temp = 0;
        }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> s){
        split();
        sort(vec.begin(), vec.end());
        auto it = vec.begin();
        while(it!=vec.end()){
            cout << *(it++);
            if(it!=vec.end())
            	cout << ' ';
        }
        cout << endl;
        vec.clear();
    }
    return 0;
}