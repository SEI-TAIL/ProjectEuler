#include <stdio.h>

// 600851475143の最大素因数
// 素数で割っていき、割り切れたときにdivを更新し、また素数で割っていく

int projecteuler003(void) {
	int i, j;
	int maxPrimeFactor = 0;
	long long div = 600851475143LL;

	for (i = 3; i*i <= div; i += 2) {
		if (div % i != 0) continue;
		bool fPrime = true;
		for (j = 3; j*j <= i; j += 2) {
			if (i % j == 0) {
				fPrime = false;
			}
		}
		if (fPrime == true) {
			div /= i;
			i = 3;
		}
	}

	maxPrimeFactor = div;
	printf("%lld\n", maxPrimeFactor);

	return maxPrimeFactor;
}
