#include <stdio.h>

int projecteuler009(void) {
	int a, b, c;
	
	for (a = 1; a < 1000; a++) {
		for (b = a; a+b < 1000; b++) {
			c = 1000 - a - b;
			if (a*a + b*b == c*c) {
				printf("a %d, b %d, c %d\n", a, b, c);
				printf("%d + %d = %d = %d\n", a*a, b*b, a*a+b*b, c*c);
				return a * b * c;
			}
		}
	}

	return 0;
}
