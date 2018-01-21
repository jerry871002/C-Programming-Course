#include <stdio.h>

int main() {
	int numOfElement;
	int checkLonely[20] = {0};

	scanf("%d", &numOfElement);
	int element[numOfElement];

	for(int i = 0; i < numOfElement; i++) {
		scanf("%d", &element[i]);
		checkLonely[element[i]]++;
	}
		
	for(int i = 0; i < 20; i++) {
		if(checkLonely[i] == 1)
			printf("%d", i);
	}

	return 0;
}