#include <stdio.h>
#include <string.h>

int projecteuler017(void) {
	int i, j;
	char str[5], len;
	int letter = 0;
	int preLetter[] = {	0, 3, 3, 5, 4, 4, 3, 5, 5, 4,
				3, 6, 6, 8, 8, 7, 7, 9, 8, 8};

	int bufLetter = 0;
	for (i = 1; i < 1000; i++) {
		sprintf(str, "%d", i);
		len = strlen(str);
		bufLetter = letter;
		if (len == 1) {
			letter += preLetter[i];
			continue;
		} else {
			if ((str[len-2] - '0') == 1) {
				int buf = (str[len-2] - '0') * 10 + (str[len-1] - '0');
				letter += preLetter[buf];
			} else {
				letter += preLetter[(str[len-1] - '0')];
				switch ((str[len-2] - '0')) {
					case 4 :
					case 5 :
					case 6 :
						letter += 5;
						break;
					case 2 :
					case 3 :
					case 8 :
					case 9 :
						letter += 6;
						break;
					case 7 :
						letter += 7;
						break;
				}
			}
			if (len >= 3) {
				letter += preLetter[(str[len - 3] - '0')] + 10;
			}
		}
	}
	letter += 11;
	letter -= 27;
	printf("%d\n", letter);
	return letter;
}
