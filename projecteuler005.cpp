#include <stdio.h>
#include <math.h>

int divPrime(int, int);

// 1から20までの最小公倍数
// tableに素因数の最大累乗値を代入

int projecteuler005(void) {
	int i, j, k, bufMlt, commonMlt = 1;
	int commonMltTable[20];

	for (i = 0; i < 20; i++) commonMltTable[i] = 0;

	for (i = 2; i <= 20; i++) {
		for (j = 2; j <= i; j++) {
			bool fPrime = true;
			for (k = 2; k*k <= j; k++) {
				if (j % k == 0) fPrime = false;
			}
			if (fPrime == true) {
				bufMlt = divPrime(i, j);
				commonMltTable[j] = commonMltTable[j] < bufMlt ? bufMlt : commonMltTable[j];
			}
		}
	}
	for (i = 0; i < 20; i++) {
		if (commonMltTable[i] > 0) {
			commonMlt *= (int)pow((double)i, (double)commonMltTable[i]);
		}
		printf("%d ", commonMltTable[i]);
	}

	return commonMlt;
}

// 渡されたiはjで何回割り切れるか
int divPrime(int i, int j) {
	if (i != 0 && i % j == 0) {
		return 1 + divPrime(i/j, j);
	}
	return 0;
}
