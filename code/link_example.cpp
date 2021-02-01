#include <bits/stdc++.h>
using namespace std;

int con[3] = {10,14,12};
list<int> l;
list<int>::iterator x;

int main () {
	//迭代器 begin() 指向第一个元素，end() 指向队尾哨兵。
	//初始 begin() 与 end() 相同，链表为空。
	cout << (l.begin()==l.end()?"true":"false") << endl;
	// true

	//从链表尾插入元素
	for (int i = 0; i < 3; i++) l.push_back(con[i]);
	// 10 14 12
	
	//弹出链表尾元素
	l.pop_back();
	//从链表头插入元素
	l.push_front(16);
	// 16 10 14
	
	//弹出链表头元素
	l.pop_front();
	//输出链表长度
	cout << l.size() << endl;
	// 2

	//输出链表头元素和尾元素
	cout << l.front() << ' ' << l.back() << endl;
	// 10 14

	//找到链表第2个元素（即头指针begin()后一个）
	x = l.begin();  x++;
	//在x前插入元素
	l.insert(x, 18);
	// 10 18 14
	l.insert(x, 6);
	// 10 18 6 14
	//删除x对应的链表元素
	l.erase(x);
	// 10 18 6
	
	//对链表排序
	l.sort();
	// 6 10 18

	//找到链表第2个元素
	x = l.begin();  x++;
	//将其修改为100
	*x = 100;

	//输出
	for (x = l.begin(); x != l.end(); x++) cout << *x << ' ';
	cout << endl;
	// 6 100 18
	return 0;
}