#include <stdio.h>

#define MaxSize 10

int LinearSearch(int [], int);

int main() {
    int array[MaxSize] = {21,15,12,24,9,30,27,6,3,18};
    int key, pos;
    
    printf("please enter a key number():");
    scanf("%d", &key);
    
    pos = LinearSearch(array, key);
    
    if(pos != -1) {
        printf("The position of key is %d\n", pos);
    } else {
        printf("key %d is not found\n", key);
    }
    
    return 0;
}

int LinearSearch(int array[], int key) {
    for(int i = 0; i < MaxSize; i++) {
        if(array[i] == key) {
            return i;
            break;
        }
        else if(i == 9) {
            return -1;
        }
    }
}