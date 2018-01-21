#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NUM_CHAR 127
#define MAX_LENGTH 1024

void findLowestFreqChar(char*);

int main()
{
    char sentence[MAX_LENGTH];
    
    // Read sentence
    fgets(sentence, MAX_LENGTH, stdin);
    sentence[strlen(sentence)] = '\0';
    
    findLowestFreqChar(sentence);
    
    return 0;
}

void findLowestFreqChar(char* sentence) {   
    /* Write Your Code Here! */
    int asciiCode[95] = {0};
    int min = MAX_LENGTH;

    for(int i=0; i<strlen(sentence); i++)
    	asciiCode[(int)sentence[i]-32]++;
    
    for(int i=0; i<95; i++) {
    	if(asciiCode[i] < min && asciiCode[i] != 0)
    		min = asciiCode[i];
    } 

    printf("%d\n", min);

    for(int i=0; i<95; i++) {
    	if(asciiCode[i] == min) {
    		if(i == 0)
    			printf("(space) ");
    		else
    			printf("%c ", i+32);
    	}
    }
}