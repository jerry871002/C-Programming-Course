//Make a matrix randomly
//Multiply two matrixs

#include <stdio.h>
#include <time.h>

#define Maxsize 10

int numrow,numcol;

void showarray(int, int, int [][Maxsize]);
void random(int [][Maxsize], int [][Maxsize]);
void mul (int [][Maxsize], int [][Maxsize], int [][Maxsize]);

int main()
{
	srand(time(NULL));

	printf("Please enter rows and cols\n");
	scanf("%d %d", &numrow, &numcol);

	int matrix1[Maxsize][Maxsize], matrix2[Maxsize][Maxsize];
	random(matrix1, matrix2);
	printf("Matrix1\n");
	showarray(numrow, numcol, matrix1);
	printf("Matrix2\n");
	showarray(numcol, numrow, matrix2);

	int matrix3[Maxsize][Maxsize] = {0};
	mul(matrix1, matrix2, matrix3);

	printf("Matrix3\n");
	showarray(numrow, numrow, matrix3);

	return 0;
} 

void showarray(int rows, int cols, int matrix[][Maxsize]) {
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			printf("%5d", matrix[i][j]);
		}
		printf("\n");
	}
}
void random(int matrix1[][Maxsize], int matrix2[][Maxsize]) {
	for(int i=0; i<numrow; i++) {
		for(int j=0; j<numcol; j++) {
			matrix1[i][j] = rand() % 10 + 1;
			matrix2[j][i] = rand() % 10 + 1;
		}
	}
}
void mul (int matrix1[][Maxsize], int matrix2[][Maxsize], int matrix3[][Maxsize]) {
	for(int i=0; i<numrow; i++) {
		for(int j=0; j<numrow; j++) {
			for(int k=0; k<numcol; k++) {
				matrix3[i][j] += matrix1[i][k] * matrix2[k][j]; 
			}
		}
	}
}