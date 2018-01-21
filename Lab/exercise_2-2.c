#include <stdio.h>

int main() {
    char p1, p2;
    printf("Enter s, r, p for player 1:");
    p1 = getchar();
    getchar();
    printf("Enter s, r, p for player 2:");
    p2 = getchar();
    //putchar('\n');
    //putchar(p1);
    //putchar(p2);
    //printf("%d", p1 == p2);
    if(p1 == p2)
        printf("Two players tie!");
    else if((p1 == 's' && p2 == 'p')||(p1 == 'r' && p2 == 's')||(p1 == 'p' && p2 == 'r'))
        printf("Player 1 win!");
    else
        printf("Player 2 win!");
}