#include <iostream>
using namespace std;

int main() {
    int kg;
    cin >> kg;
    
    int n = kg/5;
    
    for(n; n >= 0; n--) {
        if((kg - (5*n))%3 == 0) {
            n += (kg-(5*n))/3;
            cout << n << endl;
            return 0;
        }
    }
    
    cout << "-1" << endl;
}