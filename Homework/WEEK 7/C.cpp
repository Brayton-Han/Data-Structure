#include <iostream>
#include <math.h>
int n, i, fib_4[15005] = {0, 1}, fib[40] = {0, 1};
const double x = log10(1.0/sqrt(5.0)), y = log10((1.0+sqrt(5.0))/2.0);
double a;
 
int main() 
{
	for (i=2; i<40; ++i)
        fib[i] = fib[i-1] + fib[i-2];
	for (i=2; i<=15000; ++i){
		fib_4[i] = fib_4[i-1] + fib_4[i-2];
		if (fib_4[i] >= 10000)
            fib_4[i] -= 10000;
	}
	while (scanf("%d", &n) != EOF) {
		if (n < 40) 
            printf("%d\n", fib[n]);
		else {
			a = x + n*y;
			a = pow(10, a-(int)a+3);
			printf("%d...%.4d\n", (int)a, fib_4[n%15000]);
		}
	}
	return 0;
}