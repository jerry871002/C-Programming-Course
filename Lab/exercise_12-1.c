//Insertion sort!!!

#include <stdio.h>
#include <stdlib.h>

// function declaration
// InsertionSort() resize() and medium() are required
void InsertionSort(int*, int);
int* resize(int*, int);
void medium(int*, int);

int main()
{
	int *array;
	int n;

	printf("Enter the size of array: ");
	scanf("%d", &n);
	array = (int*)malloc(n * sizeof(int));
	int x;
	int now = 0;
	printf("Enter a sequence (stop by -1): ");
	while(1) {
		// store x to array;
		scanf("%d", &x);
		if(x == -1) {
			if(now < n) {
				n = now;
				break;
			}
			n--;
			break;
		}
		*(array + now) = x;
		now++;
		// resize array if number of input is larger than n
		if(now >= n) {
			array = resize(array, n);
			n++;
		}	
	}
	// calculate the medium
	InsertionSort(array, n);
	medium(array, n);
	free(array);
	return 0;
}

void InsertionSort(int* vec, int size) {
	int jdx, idx, key;
	for (jdx = 1; jdx < size; jdx++) {
		key = vec[jdx];
		idx = jdx - 1;
		while (idx >= 0 && vec[idx] > key) {
			vec[idx+1] = vec[idx];
			--idx;
		}
		vec[idx+1] = key;
	}
}

int* resize(int* vec, int size) {
	return realloc(vec, sizeof(int) * (size + 1));
}

void medium(int* vec, int size) {
	if(size % 2 == 0) {
		printf("The mediums are %d and %d.\n", *(vec + size/2 - 1), *(vec + size/2));
	} else {
		printf("The medium is %d.\n", *(vec + size/2));
	}
}