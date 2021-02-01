#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
stack<char> stc;
stack<int> sti;
char c[100002];
int T, len;
string s;

void opera()
{
	s.push_back(stc.top());
    stc.pop();
}

void work()
{
	int temp1, temp2;
	auto it = s.begin();
	while(it!=s.end()){
		if(*it == '\\'){
			temp1=0;
			while(*(++it)!='\\')
				temp1 = 10*temp1 + int(*it-'0');
			sti.push(temp1);
		}
		else if(*it == '+'){
			temp1 = sti.top();
			sti.pop();
			temp2 = sti.top();
			sti.pop();
			sti.push(temp1+temp2);
		}
		else{
			temp1 = sti.top();
			sti.pop();
			temp2 = sti.top();
			sti.pop();
			sti.push(temp2-temp1);
		}
		it++;
	}
}

int main()
{
	c[0]='+';
    cin >> T;
    while(T--){
        scanf("%s", c+1);
        len = strlen(c+1);
        for(int i=1; i<len+2; ++i){
            if(isdigit(c[i])){
            	if(!isdigit(c[i-1]))
            		s.push_back('\\');
            	s.push_back(c[i]);
            	if(!isdigit(c[i+1]))
            		s.push_back('\\');
			}
            else if(c[i]=='(')
                stc.push('(');
            else if(c[i]==')'){
                while(stc.top()!='(')
                    opera();
                stc.pop();
            }
            else if(c[i]=='\0')
                while(stc.size()>0)
                    opera();
            else{
                while(stc.size()>0 && stc.top()!='(')
                    opera();
                stc.push(c[i]);
            }
        }
        work();
        cout << sti.top() << endl;
        sti.pop();
        s.clear();
    }
    return 0;
}
