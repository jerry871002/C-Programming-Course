#include <stdio.h>
#include <string.h>

void findPassword(char[], FILE*);

int main(int argc, char* argv[]) {
	FILE* infPtr;
	FILE* outfPtr;

	char text[100];

	infPtr = fopen(argv[1], "r");
	outfPtr = fopen(argv[2], "w");

	while(fscanf(infPtr, "%s", text) != EOF) {
		findPassword(text, outfPtr);
	}

	fclose(infPtr);
	fclose(outfPtr);
	
	return 0;
}

void findPassword(char *original, FILE* outfPtr) {
	int startIndex;
	int maxLength = 0;

	int originalLength = strlen(original);

	for(int i = 0; i < originalLength; i++) {		
		for(int j = i + 1; j < originalLength; j++) {
			if(original[i] == original[j]) {
				int k = 1;
				while(j + k < originalLength && i + k < j) {
					if(original[i+k] != original[j+k])
						break;
					k++;
				}
				if(k > maxLength) {
					startIndex = j;
					maxLength = k;
				}					
			}
		}
		if(originalLength - i < maxLength)
			break;
	}

	for(int i = startIndex; i < startIndex + maxLength; i++)
		fprintf(outfPtr, "%c", original[i]);

	fprintf(outfPtr, " %d\n", maxLength);
}