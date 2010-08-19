#include <stdio.h>

// 10001番目の素数を求める

int projecteuler007(void) {
	int i, j, n = 1, prime;
	for (i = 3;; i += 2) {
		bool fPrime = true;
		for (j = 3; j*j <= i; j += 2) {
			if (i % j == 0) {
				fPrime = false;
				break;
			}
		}
		if (fPrime == true) {
			n++;
			if (n == 10001) {
				prime = i;
				break;
			}
		}
	}
	return prime;
}
