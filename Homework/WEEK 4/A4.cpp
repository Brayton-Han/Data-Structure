#include <iostream>
using namespace std;
int s[1000][1000];

int main()
{
	int n, m, q, temp;
	cin >> n >> m >> q; 
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			cin >> s[i][j];	
	while(q--)
	{
		int a, b, c, d, h, w;
		cin >> a >> b >> c >> d >> h >> w;
		for(int i=0; i<h; ++i)
			for(int j=0; j<w; ++j)
			{
				temp = s[a+i-1][b+j-1];
				s[a+i-1][b+j-1] = s[c+i-1][d+j-1];
				s[c+i-1][d+j-1] = temp;
			}
	}
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
		{
			cout << s[i][j] << ' ';
			if(j == m-1)
				cout << endl;
		}
	return 0;
} 
