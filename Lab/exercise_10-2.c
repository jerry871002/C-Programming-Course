//Use argv correctly!!!

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int i;
	double node[20];

	for(i=0; i<20; i++)
		scanf("%lf", &node[i]);

	int target_index = atoi(argv[1]);
	int l_norm = atoi(argv[2]);

	struct distance_calculate {
		int node_num;
		double distance;
	} max_dis = {0, 0.}, min_dis = {0, 100.};

	for(i=0; i<10 || i!=target_index; i++) {
		int dis = pow(pow((double)fabs(node[i*2]-node[target_index*2]), l_norm)
				  + pow((double)fabs(node[i*2+1]-node[target_index*2+1]), l_norm), (double)1/l_norm);
		if(dis > max_dis.distance) {
			max_dis.node_num = i;
			max_dis.distance = dis;
		}
		if(dis < min_dis.distance) {
			min_dis.node_num = i;
			min_dis.distance = dis;
		}
	}
	printf("Farthest to node %d is node %d with %d-norm distance %.6lf", target_index, max_dis.node_num, l_norm, max_dis.distance);
	printf("Nearest to node %d is node %d with %d-norm distance %.6lf", target_index, min_dis.node_num, l_norm, min_dis.distance);
}