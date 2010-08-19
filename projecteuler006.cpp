#include <stdio.h>
#include <math.h>

// 1から100までの二乗の合計と、1から100までの合計の二乗の差

int projecteuler006(void) {
	int i;
	int sumOfSquare = 0, squareOfSum = 0;
	for (i = 1; i <= 100; i++) {
		sumOfSquare += (int)pow((double)i, 2.0);
		squareOfSum += i;
	}
	squareOfSum = (long long)pow((double)squareOfSum, 2.0);

	printf("%lld %lld %lld\n", squareOfSum, sumOfSquare, squareOfSum - sumOfSquare);

	return squareOfSum - sumOfSquare;
}
