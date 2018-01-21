#include <stdio.h>

#define arraySize 10

int main(void) {
    int i, next;
    int data[arraySize] = {34, 56, 4, 10, 77, 51, 93, 30, 5, 52};
    int insert;
    
    printf("Unsorted array:\n");
    for(i = 0; i < arraySize; i++)
        printf("%4d", data[i]);
    for(next = 1; next < arraySize; next++) {
        insert = data[next];
        int moveItem = next;
        while((moveItem > 0) && (data[moveItem - 1] > insert)) {
            data[moveItem] = data[moveItem - 1];
            moveItem--;
        }
        data[moveItem] = insert;
    }
    printf("\nSorted array:\n");
    for(i = 0; i < arraySize; i++)
        printf("%4d", data[i]);
    return 0;
}