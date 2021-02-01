#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
char s[MAXN], t[MAXN];
int main() {
	cin >> (s + 1);
	int N = strlen(s + 1), M = 0;
	assert(1 <= N && N <= 100000);
	for (int i = 1; i <= N; ++ i) {
		assert(isdigit(s[i]) || isalpha(s[i]));
		if (s[i] != s[i - 1])
			t[M ++] = s[i];
	}
	t[M] = '\0';
	cout << t << endl;
}