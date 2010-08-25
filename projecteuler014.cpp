#include <stdio.h>
#include <map>

int getCollatz(long long);

using namespace std;

map<long long, int> memo;

int projecteuler014(void) {
	long long i;
	long long longestCollatzNum = 0;
	int maxCollatz = 0;
	int collatz = 0;

	for (i = 1LL; i < 1000000LL; i++) {
		memo[i] = getCollatz(i);
		printf("%lld %d\n", i, memo[i]);
	}
	printf("\n");
	for (i = 10000LL; i < 1000000LL; i++) {
		collatz = getCollatz(i);
		if (maxCollatz < collatz) {
			maxCollatz = collatz;
			longestCollatzNum = i;
		}
	}
	printf("%lld %d\n", longestCollatzNum, maxCollatz);
	
	return 0;
}

int getCollatz(long long collatz) {
	if (memo[collatz] != 0) return memo[collatz];
	if (collatz == 1) return 1;
	if (collatz % 2L == 0) return getCollatz(collatz/2) + 1;
	else if (collatz % 2L == 1) return getCollatz(collatz*3+1) + 1;
}
