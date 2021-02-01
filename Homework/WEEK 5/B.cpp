#include <iostream>
#include <string.h>
using namespace std;
bool hs[1000002];
char str[1000002];

bool jud(int n)
{
    while(n){
        if(n%9 == 0)
			return false;
        n /= 9;
    }
    return true;
}

int main()
{
    int n;
    scanf("%d%*c", &n);
    while(n--){
        memset(hs, false, 1000002);
        gets(str);
        int len = strlen(str);
        for(int i=1; i<7; i++)
            for(int j=0; j<len-i+1; j++) {
                int temp = 0;
                for(int k=0; k<i; k++)
                    temp=temp*9 + str[j+k] - 'A' + 1;
                hs[temp] = true;
            }
        char ans[6];
        int top=0;
        for(int i=1;; i++)
            if(!hs[i] && jud(i)){
                while(i){
                    ans[top++] = i%9;
                    i /= 9;
                }
                break;
            }
        for(int i=top-1; i>=0; i--)
            printf("%c", ans[i]+'A'-1);
        printf("\n");
    }
    return 0;
}
