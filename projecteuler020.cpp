#include <stdio.h>

int projecteuler020(void) {
	int i, j, n = 100;
	int sum = 0;
	int digit[1000];

	for (i = 0; i < 1000; i++) digit[i] = 0;
	
	digit[0] = 1;
	for (i = n; i > 0; i--) {
		for (j = 0; j < 1000; j++) {
			digit[j] *= i;
		}
		for (j = 0; j < 1000; j++) {
			if (digit[j] >= 10) {
				digit[j+1] += (digit[j] / 10);
				digit[j] = digit[j] % 10;
			}
		}
	}

	for (i = 0; i < 200; i++) {
		sum += digit[i];
	}

	printf("\n%d\n", sum);

	return sum;
}
