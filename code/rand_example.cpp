#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
	srand(time(0));
	int N = 10;
	for (int i = 0; i < N; i++)
		cout << rand() << endl;
}