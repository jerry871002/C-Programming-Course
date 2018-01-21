#include <stdio.h>

int addAllDigits(int);

int main() {
	int num, digitSum;
	scanf("%d", &num);
	digitSum = addAllDigits(num);
	while(digitSum >= 10)
		digitSum = addAllDigits(digitSum);
	printf("%d", digitSum);
	return 0;
}

int addAllDigits(int num) {
	int digitSum = 0;
	while(num > 0) {
		digitSum += (num % 10);
		num /= 10;
	}
	return digitSum;
}