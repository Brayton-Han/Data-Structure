#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int T, temp;
vector<int> v;

bool work(int a, int b)
{
    if(a+b==24 || a*b==24 || a-b==24 || (b!=0 && a/b==24) || b-a==24 || (a!=0 && b/a==24))
        return true;
    else
        return false;
}

bool work2(int a, int b, int c, int d)
{
    if(work(a+b, c+d) || work(a+b, c-d) || work(a+b, c*d) || work(a+b, c/d) || work(a+b, d-c) || work(a+b, d/c))
        return true;
    if(work(a-b, c+d) || work(a-b, c-d) || work(a-b, c*d) || work(a-b, c/d) || work(a-b, d-c) || work(a-b, d/c))
        return true;
    if(work(a*b, c+d) || work(a*b, c-d) || work(a*b, c*d) || work(a*b, c/d) || work(a*b, d-c) || work(a*b, d/c))
        return true;
    if(work(a/b, c+d) || work(a/b, c-d) || work(a/b, c*d) || work(a/b, c/d) || work(a/b, d-c) || work(a/b, d/c))
        return true;
    if(work(b-a, c+d) || work(b-a, c-d) || work(b-a, c*d) || work(b-a, c/d) || work(b-a, d-c) || work(b-a, d/c))
        return true;
    if(work(b/a, c+d) || work(b/a, c-d) || work(b/a, c*d) || work(b/a, c/d) || work(b/a, d-c) || work(b/a, d/c))
        return true;
}

bool judge(int curV, int flag)
{
    bool ans=false;
    if(curV==24 && flag==15)
    	ans=true;
    for(int i=0; i<4 && (!ans); i++){
        int value = v[i];
        if(!(flag & (1<<i)))
            if(curV == 0)
                ans = judge(value, flag|(1<<i));
            else
                ans = judge(curV / value, flag|(1<<i)) || 
                      judge(value / curV, flag|(1<<i)) ||
                      judge(curV + value, flag|(1<<i)) ||
                      judge(curV - value, flag|(1<<i)) ||
                      judge(value - curV, flag|(1<<i)) ||
                      judge(curV * value, flag|(1<<i)) ;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--){
        for(int i=0; i<4; ++i){
            cin >> temp;
            v.push_back(temp);
        }
        bool b1=false, b2=false, b3=false;
        b1 = work2(v[0], v[1], v[2], v[3]);
        b2 = work2(v[0], v[2], v[1], v[3]);
        b3 = work2(v[0], v[3], v[1], v[2]);
        if(b1 || b2 || b3 || judge(0,0))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        v.clear();
    }
    return 0;
}