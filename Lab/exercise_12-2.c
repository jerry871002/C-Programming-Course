//char* points to a string literal, you can't change the value it points to!!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[10];
	long id;
	int age;
	char gender;
} student;

int main(int argc,char *argv[]) {
	char inputfile[20] = "none";
	char outputfile[20] = "none";
	int num;
	FILE* readPtr;
	FILE* writePtr;
	student* uee1302;

	if(argc == 2)
		strcpy(inputfile, argv[1]);
	else {
		for(int i=0; i<argc; i++) {
			if(!strcmp("-i", argv[i]))
				strcpy(inputfile, argv[i+1]);
			else if(!strcmp("-o", argv[i]))
				strcpy(outputfile, argv[i+1]);
		}
	}

	if(!strcmp(inputfile, "none") && strcmp(outputfile, "none")){
		printf("Input file is required.\n");
		return 0;
	}

	if((readPtr = fopen(inputfile, "r")) == NULL){
		printf("File does not exist!!\n");
		return 0;
	} else {
		fscanf(readPtr, "%d", &num);
		//printf("%d\n", num);
		uee1302 = malloc(num * sizeof(student));
		for(int i=0; i<num; i++) {
			fscanf(readPtr, "%s %ld %d %c", uee1302[i].name, &uee1302[i].id, &uee1302[i].age, &uee1302[i].gender);
			//printf("%s %ld %d %c\n", uee1302[i].name, uee1302[i].id, uee1302[i].age, uee1302[i].gender);
		}

	}

	if(!strcmp(outputfile, "none")) {
		writePtr = fopen("test.txt", "w");
		printf("Write output in test.txt file.\n");
	} else {
		writePtr = fopen(outputfile, "w");
		printf("Write output in %s\n", outputfile);
	}

	for(int i=0; i<num; i++) {
		fprintf(writePtr, "%s %ld %d %c\n", uee1302[i].name, uee1302[i].id, uee1302[i].age, uee1302[i].gender);
	}

	free(uee1302);
	fclose(readPtr);
	fclose(writePtr);
	return 0;
}
