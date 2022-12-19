#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int gSize = 2*n-1;

	for(int i=1; i<=n; i++) {
		int lSize = 2*i-1;
		for(int j=(gSize-lSize)/2; j>0; j--)
			printf(" ");
		for(int j=lSize; j>0; j--)
			printf("*");
		// for(int j=(gSize-lSize)/2; j>0; j--)
		// 	printf(" ");
		printf("\n");
	}
}