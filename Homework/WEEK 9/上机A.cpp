#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int T, n, temp;

int jump(vector<int>& nums){
    int maxPos=0, n=nums.size(), end=0, step=0;
    for(int i=0; i<n; ++i)
        if(maxPos>=i){
            maxPos = max(maxPos, i+nums[i]);
            if(i==end){
                end = maxPos;
                ++step;
            }
        }
    return step;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        vector<int> vec;
        for(int i=0; i<n; ++i){
            cin >> temp;
            vec.push_back(temp);
        }
        cout << jump(vec)+1 << endl;
    }
    return 0;
}