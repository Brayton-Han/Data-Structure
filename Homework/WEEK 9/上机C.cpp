#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <utility>
using namespace std;
int n, m, temp, ans, x=0;
vector<set<pair<int, int>>> vec;
set<pair<int, int>> choose;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    //输入
    for(int i=0; i<n; ++i){
        set<pair<int, int>> s;
        for(int j=0; j<m; ++j){
            cin >> temp;
            s.insert({temp, i});
        }
        vec.push_back(s);
    }
    //先把每一行的最小元素取出
    for(int i=0; i<n; ++i){
    	choose.insert(*(vec[i].begin()));
    	vec[i].erase(vec[i].begin());
	}
    auto it=choose.end(); it--;
    ans = it->first-choose.begin()->first;
    //当每一行都有剩余时不断循环
    while(vec[x].size()){
        x=choose.begin()->second; //找到最小元素的行
        choose.erase(choose.begin()); //移除最小元素
        choose.insert(*(vec[x].begin())); //插入第二小元素
        vec[x].erase(vec[x].begin()); //在总表中删除第二小元素
        //记录极差
        it=choose.end(); it--;
        ans = min(ans, it->first-choose.begin()->first);
    }
    cout << ans << endl; 
    return 0;
}