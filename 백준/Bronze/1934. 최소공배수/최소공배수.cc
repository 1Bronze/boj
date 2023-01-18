#include <iostream>

using namespace std;

int getGCD(int a, int b) {
    int operand = (a<b) ? a:b;
    
    while(1) {
        if(a%operand==0 && b%operand==0) break;
        else operand--;
    }
    
    return operand;
}

int getLCM(int a, int b) {
    int GCD = getGCD(a, b);
    return (a/GCD)*(b/GCD)*GCD;
}

int main() {
    int N; cin >> N;
    int A, B;
    
    for(int i=0; i<N; i++) {
        cin >> A >> B;
        cout << getLCM(A, B) << "\n";
    }
    return 0;
}
