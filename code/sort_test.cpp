#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;

class rec{
	public:
	int val;
	int* pos;
} A[maxn];

bool cmp(const rec &A, const rec &B){
	return A.val < B.val;
}

int main() {
	srand(time(0));
	bool flag = true;
	while (flag){
		for (int i = 0; i < maxn; i++)
			if (i % 3 != 0){
				A[i].val = A[i - 1].val;
				A[i].pos = &A[i].val;
			}
			else{
				A[i].val = rand();
				A[i].pos = &A[i].val;
			}
		sort(A, A + maxn, cmp);
		for (int i = 0; i < maxn; i++)
			if (A[i].val == A[i - 1].val && A[i].pos < A[i - 1].pos)
				flag = false;
	}
	for (int i = 0; i < maxn; i++)
		cout << A[i].val << ' ' << A[i].pos << endl;
}