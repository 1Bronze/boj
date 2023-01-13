#include <iostream>
#include <cmath>
using namespace std;

int count[10];
int a, b, c, result;

int main() {
    cin >> a >> b >> c;
    result = a * b * c;
    
    while(result > 0) {
        count[result%10]++;
        result /= 10;
    }
    
    for(int i=0; i<10; i++) cout << count[i] << "\n";
}