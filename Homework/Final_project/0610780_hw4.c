#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[10];
	int value;
	int level;
} node;

typedef struct {
	//AND:1 OR:2 NAND:3 NOR:4
	int type;
	char name[10];
	int level;
	node* inputNode[2];
	node* outputNode;	
} gate;

void levelization(gate*, int);
void simulation(node*, int, int);
void find_path(gate*, int);

int main(int argc, char* argv[]) {	
	//Open the file
	FILE *infPtr;
	infPtr = fopen(argv[1], "r");
	if(infPtr != NULL)
		printf("%s has read\n\n", argv[1]);
	else
		printf("The file cannot be opened.");

	int numOfIn, numOfOut, numOfGates;
    fscanf(infPtr, "%*s %d %d %d", &numOfIn, &numOfOut, &numOfGates);
    gate *gates = malloc(sizeof(gate) * numOfGates);
    node *nodes = malloc(sizeof(node) * (numOfIn + numOfOut) * 2);
    
    char s1[30], s2[30], s3[30];
    char buffer[100];
    
    fscanf(infPtr, "%*s %*s %*s");
    fscanf(infPtr, "%*s %[^;]", s1);
    fscanf(infPtr, "%*s %*s %[^;]", s2);
    fscanf(infPtr, "%*s %*s %[^;] %*[;]", s3);
    
    //buffer = s1 + s2 + s3
    strcat(s1, ",");
    strcat(s2, ",");
    strcpy(buffer, s1);
    strcat(buffer, s2);
    strcat(buffer, s3);
    
    char *substr = NULL;
    int nodeCount = 0;
    substr = strtok(buffer, ",");
    strcpy(nodes[nodeCount].name, substr);
    nodes[nodeCount++].level = 0;
    while(substr) {
        substr = strtok(NULL, ",");
        if(!substr) {
            break;
        }
        strcpy(nodes[nodeCount].name, substr);
        nodes[nodeCount++].level = 0;
    }
    
    for(int i = 0; i < numOfGates; i++) {
        char type[10], name[10], output[10], inputOne[10], inputTwo[10];
        fscanf(infPtr, "%s %[^( ] %*[( ] %[a-zA-z0-9] %*[, ] %[a-zA-z0-9] %*[, ] %[a-zA-z0-9] %*[);]", type, name, output, inputOne, inputTwo);
        
        if(!strcmp(type, "and"))
            gates[i].type = 1;
        else if(!strcmp(type, "or"))
            gates[i].type = 2;
        else if(!strcmp(type, "nand"))
            gates[i].type = 3;
        else if(!strcmp(type, "nor"))
            gates[i].type = 4;
        else
            printf("invalid gate type\n");
        
        strcpy(gates[i].name, name);
        
        for(int j = 0; j < nodeCount; j++) {
            if(!strcmp(output, nodes[j].name))
                gates[i].outputNode = &nodes[j];
            if(!strcmp(inputOne, nodes[j].name))
                gates[i].inputNode[0] = &nodes[j];
            if(!strcmp(inputTwo, nodes[j].name))
                gates[i].inputNode[1] = &nodes[j];
        }
    }
    
    fscanf(infPtr, "%*s %*s");
    for(int i = 0; i <numOfIn; i++)
        fscanf(infPtr, "%d", &nodes[i].value);

    for(int i = 0; i < numOfGates; i++) {
        gates[i].level = (gates[i].inputNode[0]->level > gates[i].inputNode[1]->level ? gates[i].inputNode[0]->level : gates[i].inputNode[1]->level) + 1;
        gates[i].outputNode->level = gates[i].level;
        switch (gates[i].type) {
            case 1:
                gates[i].outputNode->value = gates[i].inputNode[0]->value && gates[i].inputNode[1]->value;
                break;
            case 2:
                gates[i].outputNode->value = gates[i].inputNode[0]->value || gates[i].inputNode[1]->value;
                break;
            case 3:
                gates[i].outputNode->value = !(gates[i].inputNode[0]->value && gates[i].inputNode[1]->value);
                break;
            case 4:
                gates[i].outputNode->value = !(gates[i].inputNode[0]->value || gates[i].inputNode[1]->value);
                break;
        }
    }

	int choice = 0;
	while(choice != 4) {
		printf("please choose one function\n");
		printf("levelization(1), simulation(2), find path(3), exit(4): ");
		scanf("%d", &choice);
		switch(choice) {
            case 1:
                levelization(gates, numOfGates);
                break;
            case 2:
                simulation(nodes, numOfIn, numOfOut);
                break;
            case 3:
                find_path(gates, numOfGates);
                break;
            case 4:
                printf("Good Job! SEEYOU\n\n");
                exit(1);
        }
	}
	return 0;
}

void levelization(gate *gates, int numOfGates) {
    printf("Levelization\n");
    printf("Name = level\n");
    for(int i = 0; i < numOfGates; i++)
        printf("%s = %d\n", gates[i].name, gates[i].level);
    printf("\n");
}

void simulation(node *nodes, int numOfIn, int numOfOut) {
    printf("Simulation\n");
    printf("Output = value\n");
    for(int i = numOfIn; i < numOfIn + numOfOut; i++)
        printf("%s = %d\n", nodes[i].name, nodes[i].value);
    printf("\n");
}

void find_path(gate *gates, int numOfGates) {
    char name[10];
    gate *path;

    printf("Find path\n");
    printf("Please enter the indicated gate: ");
    scanf("%s", name);
    
    for(int i = 0; i < numOfGates; i++) {
        if(!strcmp(name, gates[i].name)) {
            path = malloc(sizeof(gate) * gates[i].level);
            gate current;
            
            for(int j = 0; j < gates[i].level; j++) {
                if(j == 0) {
                    path[j] = gates[i];
                    current = gates[i];
                    continue;
                }
                if(current.inputNode[0]->level > current.inputNode[1]->level) {
                    for(int k = 0; k < numOfGates; k++) {
                        if(!strcmp(current.inputNode[0]->name, gates[k].outputNode->name)) {
                            path[j] = gates[k];
                            current = gates[k];
                            break;
                        }
                    }
                } else {
                    for(int k = 0; k < numOfGates; k++) {
                        if(!strcmp(current.inputNode[1]->name, gates[k].outputNode->name)) {
                            path[j] = gates[k];
                            current = gates[k];
                            break;
                        }
                    }
                }
            }
        }
    }
    for(int i = path[0].level - 1; i >= 0; i--) {
        printf("%s ", path[i].name);
        if(i != 0)
            printf("=> ");
        else
            printf("\n");
    }
    printf("\n");
}
