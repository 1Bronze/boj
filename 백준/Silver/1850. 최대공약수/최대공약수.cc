#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long a, b; cin >> a >> b;
    long long minimum = min(a, b);
    
    int gcd = 1;
    
    for(int i=1; i<100000000; i++) {
        if(i>minimum) break;
        else {
            if(a%i==0 && b%i==0) gcd = i;
        }
    }
    
    for(int i=0; i<gcd; i++) {
        cout << "1";
    }

    return 0;
}
