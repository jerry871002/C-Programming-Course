#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printComplex(float[2], FILE*);

int main(int argv, char* argc[]) {
	FILE* infPtr;
	FILE* outfPtr;

	infPtr = fopen("complex.txt", "r");
	outfPtr = fopen("result.txt", "w");

	char complex[2][10];

	float real[2], image[2];

	for(int i = 0; i < 2; i++) {
		fscanf(infPtr, "%s", complex[i]);
		char* pEnd;
		real[i] = strtod(complex[i], &pEnd);
		image[i] = strtod(pEnd, NULL);
	}

	float arithmetic[4][2];
	arithmetic[0][0] = real[0] + real[1];
	arithmetic[0][1] = image[0] + image[1];
	arithmetic[1][0] = real[0] - real[1];
	arithmetic[1][1] = image[0] - image[1];
	arithmetic[2][0] = real[0] * real[1] - image[0] * image[1];
	arithmetic[2][1] = real[0] * image[1] + image[0] * real[1];
	arithmetic[3][0] = (real[0] * real[1] + image[0] * image[1])\
					   / (real[1] * real[1] + image[1] * image[1]);
	arithmetic[3][1] = (image[0] * real[1] - real[0] * image[1])\
					   / (real[1] * real[1] + image[1] * image[1]);

	for(int i = 0; i < 4; i++) {
		printComplex(arithmetic[i], outfPtr);
	}

	fclose(infPtr);
	fclose(outfPtr);

	return 0;
}

void printComplex(float complex[2], FILE* outfPtr){
	fprintf(outfPtr, "%.3f", complex[0]);
	if(complex[1] >= 0)
		fprintf(outfPtr, "+");
	fprintf(outfPtr, "%.3fi\n", complex[1]);
}