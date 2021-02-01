#include <iostream>
#include <deque>
using namespace std;
int i=1, n, c, ans=0, temp;
deque<int> d;
char s[7];

int main()
{
    cin >> n;
    c = n<<1;
    while(c--){
        scanf("%s", s);
        if(s[0]=='a'){
        	scanf("%d", &temp);
        	d.push_front(temp);
		}
        else{
        	if(d.size()==0);
        	else if(d.front()!=i){
        		d.clear();
        		ans++;
			}
            else
            	d.pop_front();
            ++i;
        }
    }
    cout << ans << endl;
}
