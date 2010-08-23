#include <stdio.h>

int projecteuler013(void) {
	long long ValueLine[100][3];
	long long bufVal;
	const int MAX_DIGIT = 18;
	int buf, i, j, k;
	FILE *fp;

	if ((fp = fopen("projecteuler013.txt", "r")) == NULL) {
		return -1;
	}

	for (i = 0; i < 100; i++) {
		for (j = 0; j < 3; j++) {
			ValueLine[i][j] = 0;
		}
	}

	for (i = 0, j = 0, k = 0; (buf = getc(fp)) != EOF;) {
		if (buf == '\n') {
			printf(" 改行 \n");
			i++;
			j = 0;
			k = 0;
			continue;
		}

		if (k < MAX_DIGIT) {
			k++;
		} else {
			j++;
			if (j >= 3) {
				j = 0;
				i++;
			}
			k = 1;
		}

		ValueLine[i][j] *= 10;
		ValueLine[i][j] += (buf - '0');
		printf("%d %d %d\n", i, j, k);

		if (j == 0 && k == 14) {
			j++;
			k = 0;
		}
	}

	for (i = 0; i < 100; i++) {
		for (j = 0; j < 3; j++) {
			printf("%lld ", ValueLine[i][j]);
		}
		printf("\n");
	}

	for (j = 0; j < 3; j++) {
		bufVal = 0;
		for (i = 0; i < 100; i++) {
			bufVal += ValueLine[i][j];
			if (bufVal / 1000000000000000000LL >= 1LL) {
				ValueLine[0][j]++;
				bufVal -= 1000000000000000000LL;
			}
		}
		printf("\n\n%lld ", bufVal);
	}
	return 0;
}
