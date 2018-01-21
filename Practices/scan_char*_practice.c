//sprintf()
#include <stdio.h>

int main(int argc, char* argv[]) {
	int n = atoi(argv[1]);
	char buffer*;
	sprintf(buffer, "%d.out", n);
	printf("%s", buffer);
	return 0;
} 