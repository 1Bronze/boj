#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    int aa, ab, ac;
    int ba, bb, bc;
    
    aa = a/100; ac = a%10; ab = (a-100*aa-ac)/10;
    ba = b/100; bc = b%10; bb = (b-100*ba-bc)/10;
    
    a = 100*ac + 10*ab + aa;
    b = 100*bc + 10*bb + ba;
    
    int result = (a>b) ? a:b;
    cout << result;
}