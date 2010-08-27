#include <stdio.h>
#include <fstream>
#define max(x,y) (x>y?x:y)

int topBottomTriangle(int i, int j);

int fileTable[15][15];

int projecteuler018(void) {
	int i, j;
	int n = 15;
	int triMax;

	std::ifstream cin("projecteuler18.txt");

	for(i = 0; i < n; i++) {
		for(int j=0;j<=i;j++) {
			cin >> fileTable[i][j];
		}
	}

	triMax = topBottomTriangle(0, 0);
	printf("%d\n", triMax);
	for (i = 0; i < 15; i++) {
		for (j = 0; j < i; j++) {
			printf("%d ", fileTable[i][j]);
		}
		printf("\n");
	}

	return 0;
}

int topBottomTriangle(int i, int j) {
	int val;
	int right, left;
	int nextMax;
	val = fileTable[i][j];
	if (i == 14) return val;
	left = topBottomTriangle(i+1, j);
	right = topBottomTriangle(i+1, j+1);
	return val + max(left, right);
}
