#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float num;
    float result;
    float i;
    printf("Please enter the base floating-point number:");
    scanf("%f", &num);
    printf("%.3f to the power of 1, 2, 3 and 4 are:\n", num);
    for(i = 1; i <= 4; i++) 
        printf("%.3f\n", pow(num, i));
    return 0;
}

    /*for(int i = 1; i <= 4; i++) {
        result = num;
        for(int j = 1; j < i; j++)
            result *= num;
        printf("%.3f\n", result);
    }*/