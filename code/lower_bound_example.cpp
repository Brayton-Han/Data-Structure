#include <bits/stdc++.h>
using namespace std;

int A[] = {10,20,30,30,20,10,10,20};

int main () {
	sort (A, A + 8);
	// 10 10 10 20 20 20 30 30
	int* low_A = lower_bound(A, A + 8, 20);
	cout << (low_A - A) << endl;
	// 3
	vector<int> v(A, A + 8);
	vector<int>::iterator low_v;
	low_v = lower_bound(v.begin(), v.end(), 30);
	cout << (low_v - v.begin()) << endl;
	// 6
	int B[] = {10,12,14,18,21,25,28,31};
	list<int> l(B, B + 8);
	list<int>::iterator low_l;
	low_l = lower_bound(l.begin(), l.end(), 23);
	cout << *low_l << endl;
	// 25
	return 0;
}