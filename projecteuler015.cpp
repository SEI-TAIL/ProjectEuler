#include <stdio.h>

int projecteuler015(void) {
	
	const int GRID = 20;
	long long i, j, route = 1;
	
	for (j = 1, i = GRID*2; j < i; i--, j++) {
		route *= i;
		route /= j;
		printf("%lld %lld %lld\n", i, j, route);
	}
	
	return 0;
}
