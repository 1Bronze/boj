#include <cstdio>

int main() {
    int n; scanf("%d", &n);
    
    int result = 1;
    
    for(int i=2; i<=n; i++) result *= i;
    printf("%d", result);
}