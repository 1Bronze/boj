#include <cstdio>
bool prime[10000001];

void init() {
    for(int i=1; i<=10000000; i++) prime[i] = true;
    
    prime[1] = false;
    for(int i=2; i*i<=10000000; i++) {
        if(!prime[i*i]) continue;
        
        for(int j=2*i; j<=10000000; j+=i)
            prime[j] = false;
    }
}

int main() {
    
    init();
    int n; scanf("%d", &n);
    
    
    for(int i=2; i<=n; i++) {
        
        if(prime[i] && n%i==0) {
            printf("%d\n", i);
            n/=i; i--;
        }
    }
}