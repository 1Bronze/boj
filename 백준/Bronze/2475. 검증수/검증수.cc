#include <iostream>
using namespace std;

int num, result = 0;

int main() {
    for(int i=0; i<5; i++) {
        cin >> num;
        result += num*num;
    }
    
    result %= 10;
    cout << result;
}