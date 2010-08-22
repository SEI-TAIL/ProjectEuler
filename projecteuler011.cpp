#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int max(int x, int y) {
	return x > y ? x : y;
}

int projecteuler011(void) {
	FILE *fp;
	int fileTable[22][22];
	int buf, i, j;
	int maxProduct = 0;
	const int FIRST_ROW = 1;
	const int MAX_ROW = 20;
	const int FIRST_SENTINEL = 0;
	const int END_SENTINEL = MAX_ROW + 1;
	const int SENTINEL = 0;

	if ((fp = fopen("projecteuler011.txt", "r")) == NULL) {
		return 0;
	}

	for (i = FIRST_ROW; i <= MAX_ROW; i++) {
		for (j = FIRST_ROW; j <= MAX_ROW; j++) {
			fileTable[i][j] = 0;
		}
	}

	for (i = FIRST_SENTINEL; i <= END_SENTINEL; i+=END_SENTINEL) {
		for (j = FIRST_SENTINEL; j <= END_SENTINEL; j++) fileTable[i][j] = SENTINEL;
	}
	for (j = FIRST_SENTINEL; j <= END_SENTINEL; j+=END_SENTINEL) {
		for (i = FIRST_SENTINEL; i <= END_SENTINEL; i++) fileTable[i][j] = SENTINEL;
	}

	for (i = FIRST_ROW, j = FIRST_ROW; (buf = getc(fp)) != EOF;) {
		if (isdigit(buf)) {
			fileTable[i][j] *= 10;
			fileTable[i][j] += buf - '0';
		} else if (buf == '\n') {
			i++;
			j = FIRST_ROW;
		} else if (buf == ' ') {
			j++;
		}
	}

	for (i = FIRST_SENTINEL; i <= END_SENTINEL; i++) {
		for (j = FIRST_SENTINEL; j <= END_SENTINEL; j++) {
			printf("%2d ", fileTable[i][j]);
		}
		printf("\n");
	}

	int k;
	int down, right, rightDown, leftDown;
	for (i = FIRST_ROW; i <= MAX_ROW; i++) {
		for (j = FIRST_ROW; j <= MAX_ROW; j++) {
			down = right = rightDown = leftDown = fileTable[i][j];
			for (k = 1; k < 4; k++) {
				if (fileTable[i][j + k] == SENTINEL) break;
				right *= fileTable[i][j + k];
			}
			for (k = 1; k < 4; k++) {
				if (fileTable[i + k][j] == SENTINEL) break;
				down *= fileTable[i + k][j];
			}
			for (k = 1; k < 4; k++) {
				if (fileTable[i + k][j + k] == SENTINEL) break;
				rightDown *= fileTable[i + k][j + k];
			}
			for (k = 1; k < 4; k++) {
				if (fileTable[i + k][j - k] == SENTINEL) break;
				leftDown *= fileTable[i + k][j - k];
			}
			maxProduct = max(maxProduct, max(max(right, down), max(rightDown, leftDown)));
		}
	}
	return maxProduct;
}

