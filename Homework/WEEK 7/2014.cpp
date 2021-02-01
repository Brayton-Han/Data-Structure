#include<iostream>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int T;
ll n;

struct Matrix
{
    ll a[2][2];
};

Matrix mul(Matrix a, Matrix b)
{
    Matrix ans;
    ans.a[0][0] = 0; ans.a[0][1] = 0; ans.a[1][0] = 0; ans.a[1][1] = 0; 
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            for(int k=0; k<2; k++)
                ans.a[i][j] = (ans.a[i][j]+(a.a[i][k]*b.a[k][j])%mod)%mod;
    return ans;
}

Matrix mat_pow(Matrix a, ll n)
{
    Matrix ans;
    ans.a[0][0] = 1; ans.a[0][1] = 0; ans.a[1][0] = 0; ans.a[1][1] = 1; 
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
        if(n==0){
        	cout << 0 << endl;
        	continue;
		}
        Matrix A, B, ans;
        A.a[0][0] = 1; A.a[0][1] = 0; A.a[1][0] = 0; A.a[1][1] = 0; 
        B.a[0][0] = 1; B.a[0][1] = 1; B.a[1][0] = 1; B.a[1][1] = 0; 
        ans = mul(A, mat_pow(B, n-1));
        printf("%d\n", ans.a[0][0]%mod);
    }
    return 0;
}
