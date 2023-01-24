#include <iostream>
using namespace std;

bool prime[1000001];

int main() {
    
    int a, b; cin >> a >> b;
    
    for(int i=1; i<=1000000; i++) prime[i] = true;
    
    prime[1] = false;
    for(int i=2; i*i<=1000000; i++) {
        if(!prime[i*i]) continue;
        
        for(int j=2*i; j<=1000000; j+=i)
            prime[j] = false;
    }
    
    for(a; a<=b; a++) {
        if(prime[a]) 
            cout << a << "\n";
    }
}
