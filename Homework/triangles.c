#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int max = a;
	if(b > max)
		max = b;
	if(c > max)
		max = c;
	int sqaureSum = a*a + b*b + c*c;
	int sqaureMax = max*max;
	if(max < a + b + c - max) {
		if(sqaureMax == sqaureSum - sqaureMax)
			printf("right triangle");
		else if(sqaureMax > sqaureSum - sqaureMax)
			printf("obtuse triangle");
		else if(sqaureMax < sqaureSum - sqaureMax)
			printf("acute triangle");
	} else {
		printf("not a triangle");
	}	
	return 0;
}