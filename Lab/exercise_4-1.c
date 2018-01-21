//srand()

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int x;
    char p1, p2;
    srand(time(NULL));
    printf("Enter s, r, p for player:");
    p1 = getchar();
    getchar();
    x = rand() % 4 + 112;
    while(x == 113)
        x = rand() % 4 + 112;
    printf("Enter s, r, p for computer:%c\n", x);
    p2 = (char)x;
    
    if(p1 == p2)
        printf("Tie!\n");
    else if((p1 == 's' && p2 == 'p')||(p1 == 'r' && p2 == 's')||(p1 == 'p' && p2 == 'r'))
        printf("Player win!\n");
    else
        printf("Computer win!\n");
}