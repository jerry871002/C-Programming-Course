#include <stdio.h>

int main() {
    int num;
    int i, j;
    int result;
    printf("Enter an integer value:\n");
    scanf("%d", &num);
    printf("All prime numbers below %d are\n", num);
    for(i = 1; i <= num; i++) {
        result = 1;
        if(i <= 1)
            result = 0;
        if(i % 2 == 0 && i > 2)
            result = 0;
        for(j = 3; j < i/2; j += 2){
            if(i % j == 0)
            result = 0;
        }
        if(result == 1)
            printf("%d ", i);
    }
}