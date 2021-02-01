#include <bits/stdc++.h>
using namespace std;

int main () {
  vector<int> V;
  for (int i=1; i<10; i++) V.push_back(i);
  // 1 2 3 4 5 6 7 8 9
  random_shuffle (V.begin(), V.end());
  // 9 2 7 3 1 6 8 4 5
  nth_element (V.begin(), V.begin()+4, V.end());
  // 2 1 3 4 (5) 6 8 9 7
  return 0;
}