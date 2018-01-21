//decimalToBinary() turns decimal numbers to binary numbers

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long decimalToBinary(long);

static long result = 0;
static int i = 0;

int main() {
    long number;
    printf("Enter a decimal value:\n");
    scanf("%ld", &number);
    if(number < 0) {
        printf("Exit!\n");
        exit(1);
    }
    printf("The binary value of %ld is %ld.\n", number, decimalToBinary(number));
    return 0;
}

long decimalToBinary(long number) {
    if(number != 0) {
        result = result + pow(10, i) * (number % 2);
        i++;
        decimalToBinary(number / 2);
    }
    return result;
}