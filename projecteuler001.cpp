#include <stdio.h>

// 1 から 1000までの数値で
// 3もしくは5で割り切れる数値の合計

int projecteuler001(void) {
	int i, sum = 0;
	for (i = 0; i < 1000; i++) {
		if (i % 3 == 0) {
			sum += i;
		} else if (i % 5 == 0) {
			sum += i;
		}
	}
	return sum;
}
