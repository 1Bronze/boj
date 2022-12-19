#include <stdio.h>

int main() {
	int n; int min = 1000000; int max = -1000000;
	int arr[1000001];
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", &arr[i]);
	for(int i=1; i<=n; i++) {
		if(min>arr[i]) min=arr[i];
		if(max<arr[i]) max=arr[i];
	}
	printf("%d %d", min, max);
}