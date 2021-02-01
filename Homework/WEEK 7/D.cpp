#include <iostream>
#include <set>
#include <map>
using namespace std;
set<int> st;
map<int,int> mp;
int n;

int main()
{
    while(scanf("%d", &n)==1 && n){
        st.insert(1000000000);
        mp[1000000000] = 1;
        int u,v;
        while(n--){
            scanf("%d%d", &u, &v);
            printf("%d ", u);
            auto it = st.lower_bound(v);
            if(it == st.end())
                printf("%d\n", mp[*(--it)]);
            else{
                int t1 = *it;
                if(it != st.begin()){
                    it--;
                    if((v-*it) <= (t1-v))
                        printf("%d\n", mp[*it]);
                    else 
						printf("%d\n", mp[t1]);
                }
                else
					printf("%d\n", mp[*it]);
            }
            mp[v] = u;
            st.insert(v);
        }
        st.clear();
        mp.clear();
    }
    return 0;
}