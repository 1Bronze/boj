#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    
    long long e, f;
    e = stoll(a+b); f = stoll(c+d);
    
    cout << e+f;
    
    return 0;
}