//Make a matrix randomly
//Multiply two matrixs
//But with the data structure "struct"(Different from exercise_10-1)

#include <stdio.h> 
#include <time.h>

#define Maxsize 10

typedef struct {
	int numrow, numcol;
	int data[Maxsize][Maxsize];
} Matrix;

void showarray(const Matrix* m1);
void random(Matrix* m1, Matrix* m2);
void mul (const Matrix* m1, const Matrix* m2, Matrix* m3);

int main() { 
	srand(time(NULL));

	Matrix matrix1, matrix2, matrix3;

	printf("Please enter rows and cols\n");
	scanf("%d %d", &matrix1.numrow, &matrix1.numcol);
	matrix2.numrow = matrix1.numcol;
	matrix2.numcol = matrix1.numrow;
	matrix3.numrow = matrix1.numrow;
	matrix3.numcol = matrix1.numrow;
	for(int i=0; i<matrix3.numrow; i++) {
		for(int j=0; j<matrix3.numcol; j++) 
			matrix3.data[i][j] = 0;
	}

	random(&matrix1, &matrix2);

	printf("Matrix1\n"); 
	showarray(&matrix1); 
	printf("Matrix2\n"); 
	showarray(&matrix2); 

	mul(&matrix1, &matrix2, &matrix3);

	printf("Matrix3\n"); 
	showarray(&matrix3);

	return 0; 
}

void showarray(const Matrix* m1) {
	for(int i=0; i<m1->numrow; i++) {
		for(int j=0; j<m1->numcol; j++) {
			printf("%5d", m1->data[i][j]);
		}
		printf("\n");
	}
}
void random(Matrix* m1, Matrix* m2) {
	for(int i=0; i<m1->numrow; i++) {
		for(int j=0; j<m1->numcol; j++) {
			m1->data[i][j] = rand() % 10 + 1;
			m2->data[j][i] = rand() % 10 + 1;
		}
	}
}
void mul (const Matrix* m1, const Matrix* m2, Matrix* m3) {
	for(int i=0; i<m1->numrow; i++) {
		for(int j=0; j<m1->numrow; j++) {
			for(int k=0; k<m1->numcol; k++) {
				m3->data[i][j] += m1->data[i][k] * m2->data[k][j]; 
			}
		}
	}
}