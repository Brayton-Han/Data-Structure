#include<iostream>
#include<string.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
int T;
ll n;

struct Matrix
{
    ll a[3][3];
    void init(){
    	memset(a, 0, sizeof(a));
        for(int i=0; i<3; i++)
            a[i][i] = 1;
    }
};

Matrix mul(Matrix a, Matrix b)
{
    Matrix ans;
    //此处可以调整顺序：ikj
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            for(int k=0; k<3; k++)
                ans.a[i][j] = (ans.a[i][j]+(a.a[i][k]*b.a[k][j])%mod)%mod;
    return ans;
}

Matrix mat_pow(Matrix a, ll n)
{
    Matrix ans;
    ans.init();
    while(n){
        if(n&1)
            ans=mul(ans, a);
        a = mul(a, a);
        n >>= 1;
    }
    return ans;
}

int main()
{
    cin >> T;
    while(T--){
        scanf("%lld", &n);
        if(n==2) 
            printf("3\n");
        else if(n==3) 
            printf("4\n");
        else if(n==4) 
            printf("6\n");
        else{
            Matrix A,B;
            ll x[3][3] = {1,1,0,0,0,1,1,0,0};
            A.a[0][0] = 6; A.a[0][1] = 4; A.a[0][2] = 3;
            for(int i=0; i<3; i++)
                for(int j=0; j<3; j++)
                    B.a[i][j] = x[i][j];
            Matrix p=mat_pow(B, n-4);
            Matrix ans=mul(A, p);
            printf("%lld\n", ans.a[0][0]%mod);
        }
    }
    return 0;
}
