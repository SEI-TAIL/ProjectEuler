#include <stdio.h>
#include <map>

int projecteuler021(void) {
	int i, j;
	int sumFactor;
	int sumAmicable = 0;
	std::map<int, int> memo;

	for (i = 1; i < 10000; i++) {
		int amicable = 0;
		int sumFactor = 0;
		if (memo[i] == 1) {
			continue;
		}
		for (j = 1; j <= i/2; j++) {
			if (i % j == 0) {
				sumFactor += j;
			}
		}
		for (j = 1; j <= sumFactor/2; j++) {
			if (sumFactor % j == 0) {
				amicable += j;
			}
		}
		if (amicable == i && amicable != sumFactor) {
			sumAmicable += sumFactor;
			sumAmicable += amicable;
			memo[sumFactor] = 1;
			memo[amicable] = 1;
			printf("%d %d\n", sumFactor, amicable);
		} else {
			memo[sumFactor] = 1;
		}
	}

	printf("%d\n", sumAmicable);

	return sumAmicable;
}
