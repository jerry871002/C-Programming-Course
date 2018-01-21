//Practice to use fopen(), fclose(), and feof()

#include <stdio.h>

int main ()
{
	int num;
	// cfPtr = clients.dat file pointer
	FILE *cfPtr;
	// fopen opens file.
	// Exit program if unable to create file
	if ((cfPtr = fopen( "data.dat", "w")) == NULL) {
		printf("File could not be opened\n");
	} else {
		printf("Enter the num.\n");
		printf("Enter EOF to end input.\n");
		printf("? ");
		scanf("%d", &num);
		while (!feof(stdin)) {
			fprintf(cfPtr, "%d\n", num );
			printf("? ");
			scanf("%d", &num);
		}
		// fclose closes file
		fclose(cfPtr);
	}
	return 0;
} 