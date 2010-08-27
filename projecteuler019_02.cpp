#include <stdio.h>

int projecteuler019(void) {
	int weekday = 1, day, month, year;
	int sundayNum = 0;
	year = 1900;
	month = 1;
	day = 1;
	weekday = 1;
	for (;year <= 2000;) {
		switch (month) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				weekday = (weekday + 31)%7;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				weekday = (weekday + 30)%7;
				break;
			case 2:
				if (year % 4 != 0 || (year % 400 != 0 && year % 100 == 0)) weekday = (weekday + 28)%7;
				else weekday = (weekday + 29)%7;
				break;
		}

		if (year > 1900 && weekday == 0) {
			sundayNum++;
		}

		if (month < 12) month++;
		else {
			month = 1;
			year++;
		}

		printf("%d %d %d\n", year, month, weekday);

	}

	printf("%d\n", sundayNum);

	return sundayNum;
}
