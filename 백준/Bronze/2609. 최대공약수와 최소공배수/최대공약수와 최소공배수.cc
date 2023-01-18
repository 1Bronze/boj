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
    int A, B;
    cin >> A >> B;
    cout << getGCD(A, B) << "\n" << getLCM(A, B);
    
    return 0;
}
