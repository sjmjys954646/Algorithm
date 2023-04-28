#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int n;
	int five = 0;
	int three = 0;
	int sum;

	scanf("%d", &n);

	if (n % 5 == 0) {
		five = n / 5;
		sum = five + three;
		printf("%d", sum);
	}
	else if (n % 5 == 1) {
		if (n == 1) printf("%d", -1);
		else {
			int m = n - 6;
			five = m / 5;
			three = 2;
			printf("%d", three + five);
		}
	}
	else if (n % 5 == 2) {
		if (n == 2 || n == 7) printf("%d", -1);
		else {
			int m = n - 12;
			five = m / 5;
			three = 4;
			printf("%d", three + five);
		}

	}
	else if (n % 5 == 3) {

		int m = n - 3;
		five = m / 5;
		three = 1;
		printf("%d", three + five);

	}
	else if (n % 5 == 4) {
		if (n == 4) printf("%d", -1);
		else {
			int m = n - 9;
			five = m / 5;
			three = 3;
			printf("%d", three + five);
		}
	}

	return 0;
}