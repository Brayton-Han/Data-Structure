#include <bits/stdc++.h>
using namespace std;

int main(){
	srand(time(NULL));
	vector <pair<int, int > > V;
	for (int i = 0; i < 8; i++)
		V.push_back(make_pair(i / 2, rand()));
	sort(V.begin(), V.end());
	for (auto x : V)
		cout << x.first << ' ' << x.second << endl;
}