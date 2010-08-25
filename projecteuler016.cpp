#include <stdio.h>

int projecteuler016(void) {

	int digit[1000];
	int i, j;
	long long sum = 0;

	for (i = 0; i < 1000; i++) digit[i] = 0;

	for (i = 1, digit[0] = 2; i < 1000;i++) {

		for (j = 0; j < 1000; j++) {
			digit[j] *= 2;
		}

		for (j = 0; j < 1000; j++) {
			if (digit[j] >= 10) {
				digit[j] -= 10;
				digit[j+1] += 1;
			}
		}
	}

	for (i = 0; i < 1000; i++) {
		sum += (long long)digit[i];
	}
	printf("\n%lld\n", sum);

	for (i = 999; i >= 0; i--) {
		printf("%d", digit[i]);
	}
	printf("\n");

	return 0;
}
