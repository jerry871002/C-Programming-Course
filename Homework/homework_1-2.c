#include <stdio.h>
#include <stdlib.h>

int main() {
    long n , num;
    int oddSum, evenSum, bitCount;
    
    while(1) {
        oddSum = 0; evenSum = 0; bitCount = 0;
        printf("Enter n: ");
        scanf("%ld", &n);
        
        if(n < 0)
            exit(1);
            
        num = n;
        
        while(num > 0) {
            if(bitCount % 2 == 0) {
                evenSum += (num % 10);
                num /= 10;
                bitCount++;
            } else if (bitCount % 2 == 1) {
                oddSum += (num % 10);
                num /= 10;
                bitCount++;
            }
        }
        
        if(abs(oddSum - evenSum) % 11 == 0)
            printf("%ld is divisible by 11.\n", n);
        else
            printf("%ld is not divisible by 11.\n", n);
    }
    
    return 0;
}