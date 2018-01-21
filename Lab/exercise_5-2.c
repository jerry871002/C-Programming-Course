//Is a number palindrome(e.g. 11100111)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    /*char s[10];
    int i;
    scanf("%s", s);
    for(i = 0; i < strlen(s) / 2; i++){
        if(s[i] != s[strlen(s) - 1 - i]){
            printf("%s is not a palindrome.\n", s);
            exit(1);
        }
    }
    printf("%s is a palindrome.\n", s);*/
    int n, dig, num, rev;
    scanf("%d", &num);
    n = num;
    rev = 0;
    while (num > 0)
    {
        dig = num % 10;
        rev = rev * 10 + dig;
        num = num / 10;
    }
    if(rev == n)
        printf("%d is a palindrome.\n", n);
    else
        printf("%d is not a palindrome.\n", n);
    return 0;
}