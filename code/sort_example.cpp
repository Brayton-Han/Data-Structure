#include <bits/stdc++.h>
using namespace std;

bool cmp(const int &i, const int &j) {
    return (i>j);
}

int main () {
    int A[] = {32,71,12,45,26,80,53,33};
    sort (A, A + 8);
    //(12 26 32 33 45 53 71 80)
    vector<int> B(A, A+8);
    sort (B.begin(), B.end(), cmp);
    //(80 71 53 45 33 32 26 12)
    return 0;
}
