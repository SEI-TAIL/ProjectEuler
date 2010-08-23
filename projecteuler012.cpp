#include <stdio.h>
#include <math.h>

int projecteuler012(void) {
	int triangle = 0;
	int factorNum;
	int i, j, k = 0;
	for (i = 1;; i++) {
		triangle += i;
		factorNum = 0;
		for (j = 1; j*j < triangle; j++) {
			if (triangle % j == 0) factorNum++;
		}
		factorNum *= 2;
		if (j*j <= triangle) factorNum++;
		if (factorNum >= 500) return triangle;
		printf("%d %d %d\n", i, triangle, factorNum);
	}
	return 0;
}
