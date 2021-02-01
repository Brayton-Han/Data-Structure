#include <cstdio>
#include <cstring>

int lens=0, pos1=0, pos2=0, mmod=10;
long long a, b, c, mod=1000000007;
long long hash[1000002], base[1000002];
char s[1000002];

bool check()
{
    a = (hash[pos1] - hash[0] * base[pos1] % mod + mod) % mod;
    b = (hash[pos2] - hash[pos1] * base[pos2-pos1] % mod + mod) % mod;
    c = (hash[lens] - hash[pos2] * base[lens-pos2] % mod + mod) % mod;
    if( (a+b)%mod == c%mod )
		return 1;
    else
	 	return 0;
}

void print()
{
    for(int i=1;i<=pos1;i++)
		printf("%c",s[i]);
    printf("+");
    for(int i=pos1+1;i<=pos2;i++)
		printf("%c",s[i]);
    printf("=");
    for(int i=pos2+1;i<=lens;i++)
		printf("%c",s[i]);
}

int main() 
{
    scanf("%s",s+1);
    lens=strlen(s+1); hash[0]=0; base[0]=1;
	for(int i=1; i<=lens; ++i){
        hash[i] = (hash[i-1] * mmod % mod + s[i] - '0') % mod;
        base[i] = base[i-1] * mmod % mod;
	}
	for(pos2 = (lens%2 ? lens/2+1 : lens/2); pos2<=lens-lens/3; ++pos2){
    	int len=lens-pos2;
    	if(s[pos2+1] == '0' && len!=1)
			continue;
		pos1 = pos2-len;
    	if(pos1>0 && (s[pos1+1]!='0' || len==1) && check())	{print(); break;}	
		pos1 = pos2-len+1;
    	if((s[pos1+1]!='0' || len==2) && pos1<pos2 && check())	{print(); break;}
    	pos1 = len;
        if((s[pos1+1]!='0' || pos2-len==1) && pos1<pos2 && check())	{print(); break;}
        pos1 = len-1;
        if(pos1>0 && (s[pos1+1]!='0' || pos2==len) && pos1<pos2 && check())	{print(); break;}
    }
	return 0;
}
