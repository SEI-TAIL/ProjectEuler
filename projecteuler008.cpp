#include <stdio.h>
#include <ctype.h>

// 1000桁の数値の中から5桁の連続した数を取り出し、その積の最大値を求める

int projecteuler008(void) {
	int i, n = 0, mlt5Dig, maxMlt5Dig = 0;
	int digit5[5];
	char chrFile;
	FILE *fp;

	if ((fp = fopen("projecteuler8.txt", "r")) == NULL) {
		printf("file open error\n");
		return 0;
	}

	for (i = 0; i < 5; i++) digit5[i] = 0;

	while ((chrFile = getc(fp)) != EOF) {
		if (isdigit(chrFile) == 0) continue;
		digit5[n] = chrFile - '0';
		n < 4 ? n++ : n = 0;
		mlt5Dig = 1;
		for (i = 0; i < 5; i++) {
			mlt5Dig *= digit5[i];
		}
		if (maxMlt5Dig < mlt5Dig) {
			maxMlt5Dig = mlt5Dig;
		}
	}

	fclose(fp);

	return maxMlt5Dig;
}
