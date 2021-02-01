#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int T, N;
ll a, b;
vector<vector<ll>> vec;

bool cmp(const vector<ll>& v1, const vector<ll>& v2)
{
    return (v1[2]>v2[2]) || (v1[2]==v2[2] && v1[3]>v2[3]);
}

void print()
{
    auto it = vec.begin();
    while(it!=vec.end()){
        switch((*it)[3]){
            case 2: printf("%lld+%lld=[>%lld]\n", (*it)[0], (*it)[1], (*it)[2]);break;
            case 1: printf("%lld+%lld=[=%lld]\n", (*it)[0], (*it)[1], (*it)[2]);break;
            case 0: printf("%lld+%lld=[<%lld]\n", (*it)[0], (*it)[1], (*it)[2]);break;
        }
        ++it;
    }
    printf("\n");
}

ll judge(ll& a, ll& b)
{
	if(a>b) return 2;
    else if(a==b) return 1;
    else return 0;
}

int main()
{
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        while(N--){
            scanf("%lld%lld", &a, &b);
            vec.push_back({a, b, a+b, judge(a, b)});
        }
        stable_sort(vec.begin(), vec.end(), cmp);
        print();
        vec.clear();
    }
    return 0;
}