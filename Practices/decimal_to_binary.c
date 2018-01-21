#include <stdio.h>

int main() {
    int i, n;
    scanf("%d", &n);
    for(i = 16; i; i>>=1)
    printf(i & n?"1":"0");
}