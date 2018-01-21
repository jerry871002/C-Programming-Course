#include <stdio.h>

int main() {
    int times;
    int i, j;
    printf("Enter the size of multiplication table(1~9): ");
    scanf("%d", &times);
    if(times > 9 || times < 1)
        printf("The size of multiplication table should be 1~9.");
    else {
        for(i = 1; i <= times; i++) {
            for(j = 1; j <= times; j++) {
                printf("%d * %d = %d", i, j, i*j);
                if(j != times)
                    printf("\t");
            }
            if(i != times)
                printf("\n");
        }
    }
    return 0;
}

