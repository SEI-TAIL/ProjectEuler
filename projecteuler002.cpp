#include <stdio.h>

// 4000000万までの偶数のフィボナッチ数列の合計

int projecteuler002(void) {
	int i = 2, j = 1;
	int sum = 2;
	while (true) {
		i += j;
		j = i - j;
		if (i >= 4000000) break;
		if (i % 2 == 0) {
			sum += i;
		}
	}
	return sum;
}
