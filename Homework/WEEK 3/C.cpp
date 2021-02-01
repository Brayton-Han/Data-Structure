#include <iostream>
#include <string>
#include <list>
using namespace std; 
list<char> cbs;
list<char>::iterator p;
int n, m, p_, j=0;
char temp;
string ops;

void del()
{
	int num=1;
	auto iter=p;
	if(*iter=='('){
		while(num)
			if(*(++iter)==')')
				num--;
			else
				num++;
		p=cbs.erase(p, ++iter);
	}
	else{
		while(num)
			if(*(--iter)=='(')
				num--;
			else
				num++;
		p=cbs.erase(iter, ++p);
	}
	if(p==cbs.end())
		p--;
}

int main()
{
	cin >> n >> m >> p_;
	for(int i=0; i<n; ++i){
		cin >> temp;
		cbs.push_back(temp);
	}
	p=cbs.begin();
	while(--p_)
		p++;
	cin >> ops;
	while(m--)
		switch(ops[j++]){
			case 'L':
				p--;
				break;
			case 'R':
				p++;
				break;
			case 'D':
				del();
		}
	n=cbs.size();
	p=cbs.begin();
	for(int i=0; i<n; ++i)
		cout << *(p++);
	cout << endl;
	return 0;
} 
