//printFunction() is messy and not working 100%

#include <stdio.h>

#define MAX_SIZE 10

void printFunction(int*, int);

int main() {
    int degreeOne, degreeTwo;
    int polynomialOne[MAX_SIZE] = {0}, polynomialTwo[MAX_SIZE] = {0}, polynomialSum[MAX_SIZE] = {0};
    
    printf("Enter the degree of polynomial 1:");
    scanf("%d", &degreeOne);
    printf("Please enter the coefficient in order:");
    for(int i = degreeOne; i >= 0; i--)
        scanf("%d", &polynomialOne[i]);
    printf("Polynomial 1 is ");
    printFunction(polynomialOne, degreeOne);
        
    printf("Enter the degree of polynomial 2:");
    scanf("%d", &degreeTwo);
    printf("Please enter the coefficient in order:");
    for(int i = degreeTwo; i >= 0; i--)
        scanf("%d", &polynomialTwo[i]);
    printf("Polynomial 2 is ");
    printFunction(polynomialTwo, degreeTwo);
    
    int degreeSum = degreeOne >= degreeTwo ? degreeOne : degreeTwo;
    for(int i = degreeSum; i >= 0; i--) {
        polynomialSum[i] = polynomialOne[i] + polynomialTwo[i];
    }
    printf("Sum =");
    printFunction(polynomialSum, degreeSum);
    
    return 0;
}

void printFunction(int* function, int degree) {
    for(int i = degree; i >= 0; i--) {
        if(i != degree && *(function+i) > 0)
            printf("+");
        if(*(function+i) == 1) {
            if(i == 0)
                printf("1");
            else if(i != 1)
                printf("X^%d", i);
            else
                printf("X");
        }
        else if(*(function+i) == 0)
            continue;
        else {
            if(i == 0)
                printf("%d", *(function+i));
            else if(i != 1)
                printf("%dX^%d", *(function+i), i);
            else
                printf("%dX", *(function+i));
        }
    }
    printf("\n");
}