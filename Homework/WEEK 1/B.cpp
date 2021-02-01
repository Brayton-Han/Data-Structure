#include<iostream>
#include<algorithm>
using namespace std;

long find_min(istream& in)
{
	long a,b,x,y,n;
	cin >> a >> b >> x >> y >> n;
	while(n)
	{
		if(a>b && b>y)
		{
			b--; n--;
		}
		else if(a>b && b==y)
		{
			a--; n--;
		}
		else if(b>a && a>x)
		{
			a--; n--;
		}
		else if(b>a && a==x)
		{
			b--; n--;
		}
		else if(a==b)
		{
			if(a==x && b>y)
			{
				b--; n--;
			}
			else if(a>x && b==y)
			{
				a--; n--;
			}
			else if(a>x && b>y)
			{
				x>y ? b-- : a--; n--;
			}
			else 
				n--;
		}
		else
			n--;
	}
	return a*b;
}

int main()
{
	int t;
	cin >> t;
	for(int i=0; i<t; ++i)
		cout << find_min(cin) <<endl;
	return 0;
}
