#include <stdio.h>
#include <time.h>
#include <math.h>

void parallelogram(int, int);

int main() {
    int base, factor, width, height, doAgain;
    
    do {
        srand(time(NULL));
        base = rand() % 8 + 1;
        printf("The randomly generated base = %d\n", base);
        printf("Please define the factor (1-3) = ");
        scanf("%d", &factor);
        
        while(factor < 1 || factor > 3) {
            printf("The factor must be a number between 1 and 3!!!!!\n");
            printf("Please define the factor (1-3) = ");
            scanf("%d", &factor);
        }
        
        width = (int)pow((double)base, (double)factor);
        height = base * factor;
        
        printf("Width = base ^ factor = %d ^ %d = %d\n", base, factor, width);
        printf("Height = base * factor = %d * %d = %d\n", base, factor, height);
        
        parallelogram(width, height);
        
        printf("Do you want to do it again?(1. Yes 2. No)\n");
        scanf("%d", &doAgain);
    } while(doAgain == 1);
    
    return 0;
}

void parallelogram(int width, int height) {
    int i, j, k;
    int countA = 0, countB = 0;
    
    for(i = 1; i <= height; i++) {
        for(k = height - i; k > 0; k--){
            printf(" ");
        }
        for(j = 1; j <= width; j++) {
            if (i == 1 || i == height || j == 1 || j == width) {
                printf("@");
                countA++;
            } else {
                printf("#");
                countB++;
            }
        }
        printf("\n");
    }
    
    printf("Number of \"@\" is %d\n", countA);
    printf("Number of \"#\" is %d\n", countB);
}