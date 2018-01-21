//Insertion Sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MaxSize 10

void DisplayMatrix(int [][MaxSize],const int,const int);
void GenerateMatrix(int [][MaxSize],const int,const int);
void SortMatrix(int [][MaxSize],const int,const int);
void InsertionSort(int [],const int);

int main()
{
    int numrows,numcols;
    int IntMatrix[MaxSize][MaxSize];
    srand(time(NULL));
    printf("Please enter the number of rows: ");
    scanf("%d", &numrows);
    printf("Please enter the number of columns: ");
    scanf("%d", &numcols);
    printf("The original matrix is\n");
    
    GenerateMatrix(IntMatrix, numrows, numcols);
    DisplayMatrix(IntMatrix, numrows, numcols);
    SortMatrix(IntMatrix, numrows, numcols);
    
    printf("The modified matrix is\n");
    DisplayMatrix(IntMatrix,numrows,numcols);
    return 0;
}

void DisplayMatrix(int IntMatrix[][MaxSize],const int numrows,const int numcols) {
    for(int i = 0; i < numrows; i++) {
        for(int j = 0; j < numcols; j++) {
            printf("%3d |", IntMatrix[i][j]);
        }
        printf("\n");
    }
}

void GenerateMatrix(int IntMatrix[][MaxSize],const int numrows,const int numcols) {
    for(int i = 0; i < numrows; i++) {
        for(int j = 0; j < numcols; j++) {
            IntMatrix[i][j] = rand() % 20;
            for(int k = 0; k < j; k++) {
                while(IntMatrix[i][j] == IntMatrix[i][k]) {
                    IntMatrix[i][j] = rand() % 20;
                    k = 0;
                }
            }
        }
    }
}

void SortMatrix(int IntMatrix[][MaxSize],const int numrows,const int numcols) {
    for(int i = 0; i < numrows; i++)
        InsertionSort(IntMatrix[i], numcols);
}

void InsertionSort(int MatrixRow[],const int num) {
    int j;
    for(int i = 1; i < num; i++) {
        int temp = MatrixRow[i];
        for(j = i - 1; j >= 0 && MatrixRow[j] < temp; j--)
            MatrixRow[j + 1] = MatrixRow[j];
        MatrixRow[j + 1] = temp;
    }
}