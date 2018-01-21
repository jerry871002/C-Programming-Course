//Selection Sort

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

void DisplayMatrix(int [][MaxSize], const int, const int);
void ReadMatrix(int [][MaxSize], int*, int*);
void SortMatrix(int [][MaxSize], const int, const int);
void SelectionSort(int* const , const int );
void swap(int*, int*);

int main()
{
    int numrows,numcols;
    int IntMatrix[MaxSize][MaxSize];
    ReadMatrix(IntMatrix, &numrows, &numcols);
    printf("The row is %d\nThe column is %d\n", numrows, numcols);
    printf("The original matrix is \n");
    DisplayMatrix(IntMatrix, numrows, numcols);
    SortMatrix(IntMatrix, numrows, numcols);
    printf("The modified matrix is \n");
    DisplayMatrix(IntMatrix, numrows, numcols);
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

void ReadMatrix(int IntMatrix[][MaxSize], int* numrowsPtr, int* numcolsPtr) {
    scanf("%d", numrowsPtr);
    scanf("%d", numcolsPtr);
    for(int i = 0; i < *numrowsPtr; i++) {
        for(int j = 0; j < *numcolsPtr; j++)
             scanf("%d", &IntMatrix[i][j]);
    }
}

void SortMatrix(int IntMatrix[][MaxSize],const int numrows,const int numcols) {
    for(int i = 0; i < numrows; i++)
        SelectionSort(IntMatrix[i], numcols);
}

void SelectionSort(int* const matrixRow, const int numcols) {
    int minIndex;
    for(int i = 0; i < numcols - 1; i++) {
        minIndex = i;
        for(int j = i + 1; j < numcols; j++) {
            if(*(matrixRow+j) < *(matrixRow+minIndex))
                minIndex = j;
        }
        if(minIndex != i)
            swap(matrixRow+i, matrixRow+minIndex);
    }
}

void swap(int* numOne, int* numTwo) {
    int temp = *numOne;
    *numOne = *numTwo;
    *numTwo = temp;
}