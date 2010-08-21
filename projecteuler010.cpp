#include <stdio.h>

long long projecteuler010(void) {
	int i, j;
	long long sum = 2LL;
	for (i = 3; i <= 2000000; i += 2) {
		bool isPrime = true;
		for (j = 3; j*j <= i; j += 2) {
			if (i % j == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime == true) {
			sum += (long long)i;
		}
	}
	printf("%lld\n", sum);
	return sum;
}
