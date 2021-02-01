#include <bits/stdc++.h>
using namespace std;

int A[] = {10,20,30,30,20,10,10,20};

int main () {
	cout << sizeof(A) << endl;
	// 32 = 8 * 4
	memset(A, -1, sizeof(A));
	for (auto x : A)
		cout << x << ' ';
	cout << endl;
	// -1 -1 -1 -1 -1 -1 -1 -1
	memset(A, 1, sizeof(A));
	for (auto x : A)
		cout << x << ' ';
	cout << endl;
	// 16843009 ... 16843009
	// 16843009 = 0x01010101
	return 0;
}