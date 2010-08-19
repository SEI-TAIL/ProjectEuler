#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3桁の数字2つの積で表すことができる回文数の最大値

int projecteuler004(void) {
	int i, j, k, l, plLen, largestPalind = 1000000;
	char strPalind[10];

	for (i = 999; i > 99; i--) {
		for (j = 999; j > 99; j--) {
			bool fPalind = true;
			k = i * j;
			if (largestPalind > k) continue;
			sprintf(strPalind, "%d", k);

			plLen = strlen(strPalind);
			for (l = 0; l < plLen / 2; l++) {
				if (strPalind[l] != strPalind[(plLen-1) - l]) {
					fPalind = false;
					break;
				}
			}

			if (fPalind == true) {
				largestPalind = largestPalind > k ? largestPalind : k;
				printf("%d\n", largestPalind);
			}
		}
	}

	return 0;
}
