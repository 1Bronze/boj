#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string N; int B;

char getInt(char n) {
    if(n=='0') return 0;
    if(n=='1') return 1;
    if(n=='2') return 2;
    if(n=='3') return 3;
    if(n=='4') return 4;
    if(n=='5') return 5;
    if(n=='6') return 6;
    if(n=='7') return 7;
    if(n=='8') return 8;
    if(n=='9') return 9;
    if(n=='A') return 10;
    if(n=='B') return 11;
    if(n=='C') return 12;
    if(n=='D') return 13;
    if(n=='E') return 14;
    if(n=='F') return 15;
    if(n=='G') return 16;
    if(n=='H') return 17;
    if(n=='I') return 18;
    if(n=='J') return 19;
    if(n=='K') return 20;
    if(n=='L') return 21;
    if(n=='M') return 22;
    if(n=='N') return 23;
    if(n=='O') return 24;
    if(n=='P') return 25;
    if(n=='Q') return 26;
    if(n=='R') return 27;
    if(n=='S') return 28;
    if(n=='T') return 29;
    if(n=='U') return 30;
    if(n=='V') return 31;
    if(n=='W') return 32;
    if(n=='X') return 33;
    if(n=='Y') return 34;
    return 35;
}

int main() {
    cin >> N >> B;
    
    int result = 0;
    for(int i=N.length()-1; i>=0; i--) {
        result += getInt(N[N.length()-1-i]) * pow(B,i);
    }
    
    cout << result;
}