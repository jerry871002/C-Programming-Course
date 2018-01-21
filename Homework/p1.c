#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool myStrstr(char*, char*);

int main()
{
    char str1[1024], str2[1024];
    
    // Read the first string
    scanf("%1023s", str1);
    str1[strlen(str1)] = '\0';
    
    // Read the second string
    scanf("%1023s", str2);
    str2[strlen(str2)] = '\0';
    
    // Use myStrstr to judge if str1 contains str2
    if(myStrstr(str1, str2))
        printf("%s is a substring of %s.\n", str2, str1);
    else
        printf("%s is not a substring of %s.\n", str2, str1);
  
    return 0;
}

bool myStrstr(char* str1, char* str2) {
    int i, j;
    unsigned long lenOne = strlen(str1);
    unsigned long lenTwo = strlen(str2);

    if(lenOne < lenTwo)
        return false;

    for(i=0; i < lenOne-lenTwo+1; i++) {
        while(str1[i] == str2[0]) {
            for(j=0; j < lenTwo; j++) {
                if(str1[i+j] != str2[j])
                    break;
                if(j == lenTwo-1)
                    return true;
            }
            break;
        }
    }
    return false;
}