#include <stdio.h>

int main(int argc, char* argv[]) {
	FILE* infPtr; 
	FILE* outfPtr;
	int dimension;

	infPtr = fopen(argv[1], "r");
	outfPtr = fopen(argv[2], "w");

	fscanf(infPtr, "%d", &dimension);
	float matrix[dimension][dimension+1];

	for(int i = 0; i < dimension; i++) {
		for(int j = 0; j < dimension; j++)
			fscanf(infPtr, "%f", &matrix[i][j]);
	}

	for(int i = 0; i < dimension; i++)
		fscanf(infPtr, "%f", &matrix[i][dimension]);

	for(int i = 0; i < dimension; i++) {
		if((int)matrix[i][i] != 1) {
			float divisor = matrix[i][i];
			for(int j = 0; j < dimension + 1; j++) {
				matrix[i][j] /= divisor;
			}
		}
		for(int j = 0; j < dimension; j++) {
			if(j == i)
                continue;
			float multiplier = matrix[j][i] / matrix[i][i] * (-1);
			for(int k = 0; k < dimension + 1; k++)
				matrix[j][k] += (matrix[i][k] * multiplier); 
		}
	}

	for(int i = 0; i < dimension; i++)
		fprintf(outfPtr, "%.1f\n", matrix[i][dimension]);

	return 0;
}