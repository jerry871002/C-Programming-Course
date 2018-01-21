#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int n = atoi(argv[1]);
	
	char buffer[10];
	sprintf(buffer, "%d.out", n);

	FILE* outfPtr;
	outfPtr = fopen(buffer, "w");

	int answer[200] = {0};
	answer[0] = 1;
	int digits = 1;

	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < digits; j++) {
			answer[j] *= i;
		}
		for(int j = 0; j < digits; j++) {
			if(answer[j] >= 10) {
				answer[j+1] += answer[j] / 10;
				answer[j] %= 10;
				if(j + 1 == digits)
					digits++;
			}
		}
	}

	int count = 0;
	for(int i = digits - 1; i >= 0; i--) {
		if(count % 60 == 0 && count != 0)
			fprintf(outfPtr, "\n");
		fprintf(outfPtr, "%d", answer[i]);
		count++;
	}

	fclose(outfPtr);

	return 0;
} 