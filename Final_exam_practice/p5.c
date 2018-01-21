#include <stdio.h>
#define g (-9.8)

int main(int argc, char* argv[]) {
	FILE* infPtr; 
	FILE* outfPtr;

	int v1, v2, timeDif;
	float h1, h2;

	infPtr = fopen(argv[1], "r");
	outfPtr = fopen(argv[2], "w");

	fscanf(infPtr, "%d %d %d", &v1, &v2, &timeDif);
	//printf("%d %d %d\n", v1, v2, timeDif);

	for(float i = 0.0; (v1 * i + 0.5 * g * i * i) >= 0; i += 0.01) {
		h1 = v1 * i + 0.5 * g * i * i;
		h2 = v2 * (i - timeDif) + 0.5 * g * (i - timeDif) * (i - timeDif);
		//printf("%.2f\n", h1 - h2);
		if(h1 - h2 <= 0) {
			fprintf(outfPtr, "Collide at time %.2f\n", i);
			if((v1 + g * i) < 0)
				fprintf(outfPtr, "Ball 1 is falling. ");
			else
				fprintf(outfPtr, "Ball 1 is rising. ");
			if((v2 + g * (i - timeDif)) < 0)
				fprintf(outfPtr, "Ball 2 is falling. ");
			else
				fprintf(outfPtr, "Ball 2 is rising. ");
			fclose(infPtr);
			fclose(outfPtr);
			return 0;
		}
	}

	fprintf(outfPtr, "There is no collision.");

	fclose(infPtr);
	fclose(outfPtr);
	
	return 0;
}