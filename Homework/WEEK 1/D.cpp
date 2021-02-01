#include<iostream>
#include<algorithm>
using namespace std;
int n, temp;

int main()
{
	cin >> n;
	while(n){
		cin >> temp;
		if(temp<13){
			int ans = 1;
			for(int i=1; i<=temp; i++)
				ans *= i;
			cout << ans << endl;
		}else{
			int i=0, a[160]={0};
			int max = 12*11*10*9*8*7*6*5*4*3*2;
			while(max){
				a[i++]=max%10;
				max /= 10;
			}
			for(int i=13; i<=temp; i++){
				int b=0;
				while(b<160){
					a[b] *= i;
					b++;
				}
				for(int j=0; j<159; j++){
					a[j+1] += (a[j]/10);
					a[j] %= 10;
				}
			}
			int x=159;
			while(a[x]==0)
				x--;
			while(x>=0){
				cout << a[x];
				x--;
			}
			cout << endl;
		}
		n--;
	}
	return 0;
}
