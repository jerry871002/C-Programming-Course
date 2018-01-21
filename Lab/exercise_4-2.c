#include <stdio.h>
#include <stdlib.h>

float S1(int n);
float S2(int n);
int factorial(int n);

int main() {
    int n;
    printf("Enter an integer value for the number of order n:");
    scanf("%d", &n);
    printf("The result of S1 and S2 are:\n");
    printf("S1 = %.5f\n", S1(n));
    printf("S2 = %.5f\n", S2(n));
}

int factorial(int n) {
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

float S1(int n) {
    int i;
    float result = 0, j;
    for(i = 1; i <= n; i++) {
        result += (1 / (float)i);
    }
    return result;
}

float S2(int n) {
    int i;
    float result = 0, j;
    for(i = 1; i <= n; i++) {
        if(i > 10)
            break;
        result += (1 / (float)factorial(i));
    }
    return result;
}