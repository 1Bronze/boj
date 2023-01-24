#include <cstdio>
bool prime[1000001];

void init() {
    for(int i=1; i<=1000000; i++) prime[i] = true;
    
    prime[1] = false;
    for(int i=2; i*i<=1000000; i++) {
        if(!prime[i*i]) continue;
        
        for(int j=2*i; j<=1000000; j+=i)
            prime[j] = false;
    }
}

int main() {
    
    init();
    
    while(1) {
        int n; scanf("%d", &n);
        if(!n) break;
        
        for(int j=3; j<=n/2; j+=2) {
            if(prime[j] && prime[n-j]) {
                printf("%d = %d + %d\n", n, j, n-j);
                break;
            }
            
            if(j==499999)
                printf("Goldbach's conjecture is wrong.\n");
        }
    }
}