//Usage of struct
//How to get input from command line by argv 
//and transfer it into int by function atoi()
//or transfer it into float by atof()

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define numOfNodes 10
#define maxDim

typedef struct {
	int ID;
	double Coord[maxDim];
} Node;

typedef struct  {
	int node_num;
	double distance;
} Distance;

int main(int argc, char *argv[]) {
	int dimention;
	scanf("%d", &dimention);
	Node node[numOfNodes];
	for(int i=0; i<numOfNodes; i++) {
		node[i].ID = i;
		for(int j=0; j<dimention; j++) {
			scanf("%lf", &node[i].Coord[j]);
		}
	}

	int target_index = atoi(argv[1]);
	int l_norm = atoi(argv[2]);

	Distance distance[numOfNodes];

	for(int i=0; i<numOfNodes; i++) {
		double dis = 0;
		for(int j=0; j<dimention; j++) {
			dis += pow(fabs(node[i].Coord[j] - node[target_index].Coord[j]), l_norm);
		}		
		distance[i].node_num = i;
		distance[i].distance = pow(dis, 1./l_norm);
		dis = 0;
	}

	for(int i=0; i<numOfNodes-1; i++) {
		for(int j=0; j<numOfNodes-i-1; j++) {
			if(distance[j].distance > distance[j+1].distance) {
				Distance temp = distance[j];
				distance[j] = distance[j+1];
				distance[j+1] = temp;
			}
		}
	}

	printf("Distance to point %d(Nearest to Farthest, %d-norm)\n", target_index, l_norm);
	printf("%4s%11s\n", "ID", "Distance");
	for(int i=1; i<numOfNodes; i++) {
		printf("%4d %10.2lf\n", distance[i].node_num, distance[i].distance);
	}
}